/* 
 PART OF THIS CODE
 Soil Moisture Sensor  
 modified on 21 Feb 2019 
 by Saeed Hosseini @ Electropeak 
 https://electropeak.com/learn/ 
*/
#define SensorPin A0 
float sensorValue = 0; 
void setup() { 
 //The LED pin initialiser I put in
 pinMode(13, OUTPUT);
 digitalWrite(13,LOW);
 Serial.begin(9600); 
} 
void loop() { 
 for (int i = 0; i <= 100; i++) 
 { 
   sensorValue = sensorValue + analogRead(SensorPin); 
   delay(10); 
 } 
 sensorValue = sensorValue/100.0; 
 Serial.println(sensorValue);
 //This if statement is mine
 if (sensorValue > 100) {
  digitalWrite(13,HIGH);
  Serial.println("LED activated"); 
 }
 delay(10); 
} 
