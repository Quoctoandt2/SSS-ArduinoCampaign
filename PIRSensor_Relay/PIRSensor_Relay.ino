/*
 * Copyright (c) 2013, Convergence of design, hardware & software of Silicon Straits Saigon
 * http://www.siliconstraits.vn/
 * All rights reserved.
 *
 * Code nay la thi du su dung cam bien hong ngoai (khong phai cam bien chuyen dong PIR) de
 * phat hien vat the trong mot pham vi khoang cach cho truoc va bao tin hieu sang den neu
 * vat the do xuat hien
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

/* Chan "signal" cua IR_Sensor noi vao chan 8 cua arduino
   Chan "in 1" cua relay noi vao chan 9 cua arduino
   */

int ir_receive =  8;
int light      = 9;
int in_range;


void setup() {
  pinMode(light, OUTPUT);
  pinMode(ir_receive, INPUT);
}

void loop() {
  
     
  in_range = digitalRead(ir_receive); /* doc gia tri digital tu chan so 8 va luu gia tri */
  
  /* vi tin hieu nhan duoc la 1 neu khong phat hien vat the nao xuat hien
     trong vung phat hien cua cam bien, va se la 0 neu co vat the xuat hien
     trong vung phat hien cua cam bien, vay nen ta se bat den neu gia tri
     cua in_range la 0 va se tat den neu gia tri cua in_range la 1 */
  
  /* Ta co the thay doi vung phat hien cua cam bien (xa hay gan) bang cach xoay bien tro o phia sau cam bien */
  
  if (in_range) {
  digitalWrite(light, LOW);
  } else {
  digitalWrite(light, HIGH);
  }
  
  /* Sau 300s ta lai doc tin hieu mot lan */
  delay(300);  
}
