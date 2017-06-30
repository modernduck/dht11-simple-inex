#include <Adafruit_Sensor.h>
#include <DHT.h>
DHT dht(D3 , DHT11);//
//-------for led-----------
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);
//-------------------
float oonapoom;
float kwamchuen;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  // Initialize device.
  dht.begin();
  //clear jor 
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //เริ่มการใช้งานจอ
   display.clearDisplay();//ล้างจอ
}

void loop() {
  // put your main code here, to run repeatedly:
  oonapoom = dht.readTemperature();
  Serial.println(oonapoom);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print(oonapoom);//display.print พิมพ์1 บรรทัด
  display.println(" C");//ใช้ ""ครอบข้อความกรณีจะพิมพ์ข้อความ println คือขึ้นบรรทัดใหม่
  kwamchuen = dht.readHumidity();
  Serial.println(kwamchuen);
  display.print(kwamchuen);
  display.println(" %");
  display.display();
  
}
