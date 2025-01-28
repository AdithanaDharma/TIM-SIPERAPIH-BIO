# I.	Motivasi
###   Motivasi yang melatari perlunya dibuat PCB pada rangkaian ini adalah, Penggunaan PCB dalam merangkai mikrokontroler dan berbagai modul yang kompatibel memberikan manfaat besar. PCB lebih stabil,tahan lama, dan tampak lebih profesional. Ketiga faktor ini sangat penting untuk keberhasilan proyek Innovillage ini.
# II.	Komponen yang digunakan
# 1.	ULN2003A
## a.	Pengertian
### ULN2003A adalah sebuah array transistor Darlington yang diproduksi oleh Texas Instruments (TI). Komponen ini terdiri dari tujuh pasang transistor NPN Darlington yang memiliki keluaran tegangan tinggi dengan dioda penjepit katoda bersama untuk mengalihkan beban induktif, dimana relay termasuk kedalam jenis beban induktif.
## b.	Transistor darlington
### Transistor Darlington adalah konfigurasi dari dua transistor bipolar (NPN atau PNP) yang dihubungkan secara seri untuk berfungsi sebagai satu transistor tunggal dengan penguatan (gain) yang sangat tinggi.
### •	Transistor pertama: Arus yang masuk ke basis transistor pertama akan diperkuat oleh transistor ini.
### •	Transistor kedua: Arus yang diperkuat oleh transistor pertama kemudian masuk ke basis transistor kedua, yang memperkuatnya lebih lanjut.
### Konfigurasi ini memungkinkan transistor Darlington untuk memiliki penguatan arus yang jauh lebih tinggi dibandingkan dengan transistor tunggal
![uln](https://github.com/user-attachments/assets/cec96273-4318-4026-b166-a36c7168e0b5)
## c.	Spesifikasi
![spek uln](https://github.com/user-attachments/assets/3f467314-d487-4884-a9af-17e3c5968707)
##### Gambar 3. Spesifikasi menurut  datasheet, https://www.alldatasheet.com/datasheet-pdf/view/1951053/TI1/ULN2003A.html
![uln2003](https://github.com/user-attachments/assets/b52325f2-e0f1-4a89-95e8-c9f230c05fa4)
##### Gambar 4. ULN2003A (Versi DIP)
## d.	Manfaat dalam rangkaian
### •	Sederhana dan Efisien: Menggunakan ULN2003A menyederhanakan desain rangkaian karena menggabungkan beberapa transistor dalam satu IC, mengurangi jumlah komponen yang diperlukan
### •	Penguatan Arus: ULN2003A dapat memperkuat arus dari pin GPIO ESP32 yang biasanya hanya mampu memberikan arus kecil. Ini memungkinkan ESP32 untuk mengendalikan relay yang membutuhkan arus lebih besar. Dengan ULN2003A ESP32 hanya akan terbebani dengan mengeluarkan arus 2-3mA untuk mengaktifkan transistor Darlington, artinya 14-21mA untuk seluruh relay. Sumber arus untuk menyalakan relay akan berasal dari tegangan eksternal (dalam hal ini adaptor 12v 1A) ini cukup karena relay 12v hanya perlu 33mA (total untuk 7 relay diperlukan 231mA) dibanding relay 5v yang perlu 70mA (selengkapnya di bagian 2)
### •	Proteksi Beban Induktif: ULN2003A dilengkapi dengan dioda penjepit yang melindungi ESP32 dari lonjakan tegangan yang dihasilkan oleh beban induktif seperti relay.
### •	Kompatibilitas Tegangan: ULN2003A dapat bekerja dengan tegangan input dari 3V hingga 5V, yang sesuai dengan tegangan output dari pin GPIO ESP32. Namun untuk menyalakan transistor Darlington ### akan memerlukan 1v jadi jika kita pakai adaptor 12v maka akan terpakai 1v oleh ULN2003A, Sebetulnya ada ULN2003V12 yang hanya memerlukan 0.1v, namun sayangnya belum tersedia di Indonesia (ULN2003A Lebih populer)

# 2.	Relay SRD-12VDC-SL-C
## a.	Pengertian
### SLD-12VDC-SL-C adalah jenis relay yang diproduksi oleh Ningbo Songle Relay Co., Ltd. Relay ini sering digunakan dalam berbagai aplikasi elektronik untuk mengontrol sirkuit dengan tegangan rendah.

## b.	Cara kerja
![relay](https://github.com/user-attachments/assets/9e5cff53-1f72-4fdc-b577-7df899a5a607)
![Cuplikan layar 2025-01-28 185044](https://github.com/user-attachments/assets/060e4071-30c6-4244-a50a-9206a52e503e)
##### Gambar 7. Relay SRD-12VDC-SL-C
### Relay sejatinya adalah saklar, tapi berbeda dari saklar konvensional yang kita tahu, relay bekerja dengan menimbulkan gaya magnet di bagian lilitan koil (yang uwer uwer di gambar) kemudian ini akan membuat angker (armature / bagian yang mirip pintu di gambar) dan membuat bisa melaluinya. Ada 2 Kondisi yang ada di relay ini yaitu Normaly open dan normaly close: 
### •	Normally Open (NO)
Dalam kondisi normal (tanpa daya), kontak NO terbuka, sehingga arus tidak mengalir. Ketika relay diberi daya (misalnya dari mikrokontroler), kontak NO akan menutup, memungkinkan arus mengalir.
### •	Normally Closed (NC)
Dalam kondisi normal (tanpa daya), kontak NC tertutup, sehingga arus mengalir. Ketika relay diberi daya, kontak NC akan terbuka, menghentikan aliran arus.
### c.	Spesifikasi
![spek relay](https://github.com/user-attachments/assets/44fd3faf-980f-440a-8cdb-3d1b2b93d8fb)
##### Gambar 8. spesifikasi SRD-12VDC-SL-C, https://www.alldatasheet.com/datasheet-pdf/view/1131868/SONGLERELAY/SRD-12VDC-FL-C.html
## III.	Desain PCB
### a.	Tautan Proyek: https://pro.easyeda.com/editor#id=ca1ccf5a594040719d95668f727589ba,tab=a162b587e98a446786fa549da2a3f541|*f97f490400c044459423d3b92b2276d4@ca1ccf5a594040719d95668f727589ba
### b.	Desain:
![2D_Modul Semprot Otomatis_1_2025-01-28](https://github.com/user-attachments/assets/bb691fe5-7089-4587-9405-681917355919)
##### Gambar 10. Hasil render 2D Tampak atas Rangkaian PCB
![3D_Modul Semprot Otomatis_1_2025-01-28 (1)](https://github.com/user-attachments/assets/c7a55724-af62-445f-86ab-19e72d710d8e)
##### Gambar 11. Hasil render 3D Tampak atas Rangkaian PCB
![2D_Modul Semprot Otomatis_1_2025-01-28 (1)](https://github.com/user-attachments/assets/da5717bc-7d50-4a28-84eb-0e3daf63038d)
##### Gambar 12. Hasil render 2D Tampak bawah Rangkaian PCB
![2D_Modul Semprot Otomatis_1_2025-01-28 (1)](https://github.com/user-attachments/assets/48bde936-b056-43e6-bd22-b95b311cefb3)
##### Gambar 13. Hasil render 3D Tampak bawah Rangkaian PCB
## IV.	Perhitungan
## a.	Lebar track
![image](https://github.com/user-attachments/assets/34cd6777-171e-4e62-9fa5-a3e8cb6982bf)
##### Umumnya untuk Track (jalur) yang dilewati 1A, Lebar yang diperlukan hanya 0.3mm, ini karena semua track adalah layer luar (proyek PCB ini menggunakan 2 layer) Namun untuk kenyamanan, Track sinyal lebarnya 0.5mm Dan track yang membawa daya 1mm Dengan ketebalan 1oz/ft2 
## b.	Kebutuhan Arus
### Rumus penguatan:
![Gambar5](https://github.com/user-attachments/assets/3f0beaf6-eee3-4475-a072-9286603a079b)
### Menghitung arus kolektor:	
![image](https://github.com/user-attachments/assets/4efb5dfa-86d9-45ac-8ce9-46f69eacd533)
![image](https://github.com/user-attachments/assets/35abdeec-2d97-41e8-b191-b37f7e15c412)
### hitung pada relay (beban relay 33mA, namun dilebihkan jadi 50mA jaga-jaga suhu naik): 
![image](https://github.com/user-attachments/assets/6e8bc766-48dc-4d6b-bb83-7f75e969bef9)

## V.	Referensi
### Texas Instruments. (n.d.). ULN2003A datasheet. AllDatasheet. Retrieved January 21, 2025, from https://www.alldatasheet.com/datasheet-pdf/view/1951053/TI1/ULN2003A.html
### Ningbo Songle Relay Co., Ltd. (n.d.). SRD-12VDC-FL-C datasheet. AllDatasheet. Retrieved January 21, 2025, from https://www.alldatasheet.com/datasheet-pdf/view/1131868/SONGLERELAY/SRD-12VDC-FL-C.html 
### u/Aggravating-Cap-2677 (2025, Januari 20). Do you think my schematics are right and work? [Online forum post]. Reddit. Retrieved January 21, 2025, from ### https://www.reddit.com/r/PCB/comments/1i5nykw/do_you_think_my_schematics_are_right_and_work/ 
### Gala, T. (2019, September 10). The art of drawing good schematics. Medium. Retrieved January 21, 2025, from https://medium.com/@tiago.gala/the-art-of-drawing-good-schematics-be3e7e59eb40 
### Microcontrollers Lab. (n.d.). Relay driver circuit using ULN2003. Retrieved January 21, 2025, from https://microcontrollerslab.com/relay-driver-circuit-using-uln2003/ 
### Digi-Key Electronics. (n.d.). PCB trace width conversion calculator. Retrieved January 21, 2025, from https://www.digikey.com/en/resources/conversion-calculators/conversion-calculator-pcb-trace-width
