#include <Adafruit_Sensor.h>
#include <DHT.h>
DHT dht(D3 , DHT11);//
float oonapoom;
float kwamchuen;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  // Initialize device.
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  oonapoom = dht.readTemperature();
  Serial.println(oonapoom);
  
}
