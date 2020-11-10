/*
   TUTORIAL LCD 1602 PADA ARDUINO
   MENGGUNAKAN I2C
   MENAMPILKAN NILAI ANALOG DARI LDR

   Pinout LCD :
   SDA -> SDA
   SCL -> SCL
   VCC -> VCC
   GND -> GND

   LDR -> A2
*/

#include <Wire.h>

#include <LiquidCrystal_I2C.h>
//set I2C address untuk Modul I2C LCD, beberapa modul menggunakan 0x3F atau 0x27

//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


void setup()
{
  pinMode(A2,INPUT); //set A0 menjadi input
  Serial.begin(115200);  // memulai komunikasi serial untuk debug
  Serial.println("Mencoba LDR pada Arduino");

  lcd.begin(16, 2);  // inisiasi lcd

  //-------- Menulis karakter pada display LCD ------------------
  // NOTE: Posisi cursor : (KOLOM, BARIS) mulai dari 0
  lcd.setCursor(0, 0); //set cursor untuk mulai pada kolom 0 di baris 0
  lcd.print("Nilai LDR");

}

void loop()
{
  int hasil = analogRead(A2); //ambil data nilai A2 dan simpan ke variabel hasil 
  lcd.setCursor(0, 1);
  lcd.print(hasil);
  delay(500);
}
