//Dokumentasi Program Modul Deteksi Biogas SI PERAPIH BIO V3.0
#include <WiFi.h> //header liblary Wifi Esp32

String apiKey = "SB1NQ6CKZT9OEVG2";         // API key dari ThingSpeak
const char *ssid = "BAI 1B";                // SSID WiFi
const char *pass = "b41#123A";              // Password WiFi
const char* server = "api.thingspeak.com";  // Server
const uint32_t analogPin = 34;              // Pin ADC untuk membaca sensor
const uint32_t TimeOutKoneksi = 30000;      // mengatur peringatan timeout wifi
const uint32_t R0 = 100;                    // Nilai R0 hasil kalibrasi dalam udara bersih
const uint32_t RL = 10;                     // Nilai resistor load (RL) dalam kilo-ohm
uint64_t TimePassed = 0;                    // waktu tunggu koneksi

WiFiClient client;                          // membuat koneksi TCP

void setup() {
    Serial.begin(115200);                   // memulai komunikasi serial monitor
    WiFi.begin(ssid, pass);                 // mencoba konek ke wifi

    while (WiFi.status() != WL_CONNECTED) { //looping pengecekan koneksi
      if (TimePassed >= 30000) {
        delay(1000);
        Serial.println();  
        Serial.println("Gagal tersambung, Periksa Sambungan Wifi");  
      }
      else {
      TimePassed+=500;
      delay(250);
      Serial.print(".");
      }
    }
    Serial.println("\nOk Udah nyambung Wifi");
}

void loop() {
    int sensorValue = analogRead(analogPin);   // Membaca nilai analog dari sensor
    float Vout = (sensorValue / 4095.0) * 3.3; // Tegangan keluaran sensor (0-3.3V)
    
    // Menghitung Rs (resistansi sensor) berdasarkan Vout
    float Rs = ((3.3 - Vout) / Vout) * RL;    // Rumus untuk menghitung Rs

    // Menghitung rasio Rs/R0
    float ratio = Rs / R0;

    /* Menghitung konsentrasi gas dalam ppm (menggunakan rumus dari datasheet)
       Misalnya, menggunakan rumus eksponensial yang biasa ditemukan di datasheet MQ sensor
       ppm = A * (Rs/R0)^B, dengan A dan B yang sesuai dengan jenis gas 
       Misalnya, rumus eksponensial dengan B = -2.1(LPG), kalau -2.3 metana */

    float ppm = pow(ratio, -2.1); 

    if (isnan(sensorValue)) { //cek apakah value sensor NaN (kalau NaN Berarti ga konek)
      Serial.println("Gagal Baca Sensor");
      return;
    }

    // Mengirim data ke ThingSpeak
    if (client.connect(server, 80)) {
      String postStr = apiKey;
      postStr += "&field1=";  // field ke
      postStr += String(ppm); // Kirim nilai ppm
      postStr += "r\n";

      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postStr.length());
      client.print("\n\n");
      client.print(postStr);

      Serial.print("Gas Terdeteksi (ppm): ");
      Serial.println(ppm);
      Serial.println("Mengirim data");
    }

    delay(500);
    client.stop();
    Serial.println("Tunggu Delay Update...");

    // ThingSpeak membutuhkan delay minimal 15 detik antar update (jangan di ganti)
    delay(15000);
}
