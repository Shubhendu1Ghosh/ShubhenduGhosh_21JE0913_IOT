
#include<SoftwareSerial.h>
SoftwareSerial mySerial();
#include<dht.h>
#define dht_dpin 7; 
dht DHT;
char c=0;
void setup() {
 pinMode(8,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  DHT.read11(dht_dpin);
 float msval=analogRead(A0);
float hmd=DHT.humidity;
float temp=DHT.temperature;
  if(mySerial.available()>0)
  {
    c = mySerial.read();
    if(c == '1' ){
     digitalWrite(8,HIGH); 
    }
    if(c == '2' ){
     digitalWrite(8,LOW); 
    }     
  }
}
