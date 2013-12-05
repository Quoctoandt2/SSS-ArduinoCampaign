/*
 * Copyright (c) 2013, Convergence of design, hardware & software of Silicon Straits Saigon
 * http://www.siliconstraits.vn/
 * All rights reserved.
 *
 * Code nay gioi thieu voi cac ban cach su dung quang tro (ta goi la cam bien anh sang cung duoc)
 * Tuy thuoc vao dac tinh cua quang tro va nhu cau cua ban ma du lieu analog nhan duoc va cach
 * xu ly du lieu do co it nhieu su thay doi. Mong cac ban luu y van de nay
 *
 */
 
/*
 * \file
 *         A quick program that measure the brightness of the room and turn the light on/off
 * \author
 *        Pham Ba Tho     https://www.facebook.com/phambatho  
 *        Tran Duy Thanh  https://www.facebook.com/tranduy.thanh.37      
 * \date
 *        Nov.27th 2013 
 */
 
 /*-------------------------------------------------------------------------------------------*/


 /* 
  * Tin hieu nhan duoc tu cam bien anh sang la tin hieu analog. Theo nhu khao sat cua chung toi
  * thi gia tri nhan duoc thuong la:
  * - khoang 600 neu khong co anh sang hoac anh sang yeu
  * - khoang 250 neu anh sang manh nhu anh sang ban ngay
  * Vay nen tu gia tri nhan duoc, chung ta se mo den neu gia tri nhan duoc lon hon 500 va
  * ta se tat den neu gia tri nhan duoc nho hon 350
  * 
  * O day, de thuan tien, ta goi gia tri 400 la on_level
  * va gia tri 350 la off_level voi 2 dong code nhu sau:
   */
  
#define on_level  400
#define off_level 350

/* Chung ta khia bao cac bien duoc su dung o day */
int Light_Sensor_Pin = A0;    // Chung ta dung ten Light_Sensor_Pin thay cho ten A0
int Light_bulb = 9;      // Chung ta dat ten cho chan so 9 la Light_bulb, day cung la chan dieu khien den
int Light_Sensor_Value = 0;  // bien Light_Sensor_value dung de luu gia tri nhan duoc va dem di so sanh sau nay

void setup() {
  // Chung ta dung lenh sau de quy dinh chan so 9 la chan xuat tin hieu
  pinMode(Light_bulb, OUTPUT);  
  Serial.begin(115200);
}

void loop() {

  /* Doc gia tri nhan duoc tu cam bien anh sang */
  Light_Sensor_Value = analogRead(Light_Sensor_Pin);    
  Serial.println(Light_Sensor_Value);
  /* Ta dung ham if de so sanh gia tri nhan duoc voi 400 */
  if(Light_Sensor_Value > on_level){
  
  /* Neu gia tri nhan duoc thuc su lon hon 400 thi dong lenh nay se duoc thuc hien
     Va dong lenh nay cung la lenh mo den */
     /* Luu y: Vi relay dao nguoc tin hieu nen den se sang neu
        ta cho chan dieu khien den xuong LOW */
  digitalWrite(Light_bulb, LOW);  
  }
  
  /* Ta dung ham if de so sanh gia tri nhan duoc voi 350 */
  if(Light_Sensor_Value < off_level){
  
  /* Neu gia tri nhan duoc thuc su nho hon 350 thi dong lenh nay se duoc thuc hien
     Va dong lenh nay cung la lenh tat den */
  digitalWrite(Light_bulb, HIGH);   
  }             
}
