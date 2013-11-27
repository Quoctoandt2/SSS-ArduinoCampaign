/*
 * Copyright (c) 2013, Convergence of design, hardware & software of Silicon Straits Saigon
 * http://www.siliconstraits.vn/
 * All rights reserved.
 *
 * Code nham muc dich gioi thieu cho cac ban moi lap trinh voi arduino co the the lam quen
 * voi cam bien sieu am do khoang cach, cam bien nhiet do LM35DZ va man hinh LCD 2 dong
 *
 */
 
/*
 * \file
 *         A quick program that detect people or thing in a range and indicate with the light
 * \author
 *        Pham Ba Tho     https://www.facebook.com/phambatho  
 *        Tran Duy Thanh  https://www.facebook.com/tranduy.thanh.37      
 * \date
 *        Nov.27th 2013 
 */
 
 /*-------------------------------------------------------------------------------------------*/
 
/*
  Luu y ve module man hinh LCD 2 dong

  Cac chan duoc noi nhu sau
 * LCD RS noi voi chan     12
 * LCD Enable noi voi chan 11
 * LCD D4 noi voi chan      5
 * LCD D5 noi voi chan      4
 * LCD D6 noi voi chan      3
 * LCD D7 noi voi chan      2
 * LCD R/W noi voi chan GND cua board Arduino
 * Co mot dien tro 10V duoc dung de dieu chinh do
   do tuong phan (noi nom na la chu duoc hien thi
   sang ro hay mo)
 * noi chan VSS (hoac co ten khac la VCC) voi chan 5V cua arduino 
   va VDD (hoac co ten khac la GND) voi chan GND cua arduino
 */

/*
  Doi voi module UltraSonic (Do khoang cach bang song sieu am)

  Luu y:
 * Chan Trigger cua module UltraSonic noi voi chan 6 cua board arduino
 * Chan echo cua module UltraSonic noi voi chan 7 cua board arduino
 */

/*
  Doi voi module cam bien nhiet do

  Luu y:
 * Chan Trigger cua module UltraSonic noi voi chan 6 cua board arduino
 * Chan echo cua module UltraSonic noi voi chan 7 cua board arduino
 */

 /* De cho vien lap trinh duoc de dang, arduino cung nhu cac trinh bien
    dich khac deu co san cac thu vien ho tro. Co the hieu nom na ve cac
    thu vien the nay: Thay vi cac ban phai viet hang chuc dong code de
    tao cac thiet lap ban dau (de module san sang hoat dong) va them
    hang chuc dong code de thuc hien chi mot tac vu nao day voi module hay
    board arduino thi voi su giup do cua cac thu vien nay, ban chi can
    viet vai ba dong code don gian ma thoi. Cac thu vien nay hau het deu
    co san trong thu muc cai dat ~/libraries, ngoai ra ban cung co the
    tim thay nhieu thu vien nhu vay tren internet tu cong dong rong lon
    su dung arduino */
 /* De su dung thu vien san co cua man hinh LCD va module UltraSonic, ta
    viet nhu nhu sau */
#include <LiquidCrystal.h>
#include <NewPing.h>

/* Thiet lap ban dau cho man hinh LCD */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/* Thiet lap ban dau cho module UltraSonic */
#define TRIGGER_PIN  6  
#define ECHO_PIN     7  
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

/* Chung ta khai bao cac bien se su dung o day */
unsigned int distance = 0;
int          Thermal_Sensor_Pin = A1;    // Dau ra cua cam bien nhiet do duoc noi voi chan A1
unsigned int Thermal_Sensor_Value = 0;  // bien chua du lieu thu duoc tu cam bien nhiet do
unsigned int Temperature = 0;


void setup() {
  
  /* Chung ta can them dong nay de bat dau su dung duoc module LCD
     Day cung la mot dong code can thiet de thiet lap ban dau cho
     man hinh LCD, tuy nhien, vi mot vai ly do ma dong code nay khong
     nam o tren ma duoc viet o day
     
     Ta co the hieu the nay: dong thiet lap o tren lam chuc nang chuan
     bi san sang moi thu de arduino va lcd hieu nhau, LCD va dang o trang
     thai "nghi ngoi" va chua san sang de lam cai gi het. Dong code duoi
     day giong nhu viec thong bao cho arduino rang "ke tu bay gio, chung ta
     muon su dung lcd de hien thi cai gi day, va yeu cau lcd phai san sang
     doi lenh va thuc hien bat cu luc nao" */
  lcd.begin(16, 2);
  
}

void loop() {
  
  delay(50);
  
  /* Chung ta ra lenh do khoang cach va luu gia tri do trong bien co ten "uS" */
  unsigned int uS = sonar.ping();
  /* Gia tri trong bien uS thuc ra la khoang thoi gian ke tu luc ta phat song
     sieu am den luc chung ta thu lai duoc song sieu am phan hoi. Vay nen ta can
     dung lenh duoi day de tinh ra gia tri khoang cach (theo don vi centimet).
     Luu y:
     Gia tri duoc lam trong den 1 centimet */
  distance = uS / US_ROUNDTRIP_CM;
  
  /* De hien thi ket qua do khoang cach ra man hinh, chung ta viet nhung dong sau,
     toi se giai thich theo tung dong lenh cho cac ban */
      
      /* Lenh dau tien la xoa moi thu da hien thi truoc do tren man hinh */
  lcd.clear();
      /* Lenh tiep theo la xac dinh vi tri ta muon in ra tren man hinh.
         Cu the: trong dong code duoi, ta di chuyen den o dau tien cua dong tren */
  lcd.setCursor(0, 0);
      /* Ta viet dong chu "Khoang cach" len man hinh */
  lcd.print("Khoang cach:");
      /* Ta muon in gia tri ra man hinh tu o thu 13 cua dong tren, ta viet the nay */
  lcd.setCursor(13, 0);
      /* In gia tri ra man hinh */
  lcd.print(distance);
  
  /* Doc gia tri cua cam bien nhiet do */
  Thermal_Sensor_Value = analogRead(Thermal_Sensor_Pin);
  /* Tu gia tri nhan duoc, tinh toan ra nhiet do */
  Temperature = Thermal_Sensor_Value*500/1024;
  
  /* Hien thi len LCD - Cac lenh tuong tu nhu tren */
  lcd.setCursor(0, 1);
  lcd.print("Nhiet do:");
  lcd.setCursor(13, 1);
  lcd.print(Temperature);
}

