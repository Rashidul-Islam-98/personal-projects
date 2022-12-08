#include<SoftwareSerial.h>
SoftwareSerial mySerial(2,3);
int sensor=A0;
int buzzer=13;
int green=12;
int red=11;
int relay=10;
int data;
void setup()
{
  pinMode(sensor,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(relay,OUTPUT);
  mySerial.begin(9600);
  Serial.begin(9600);
  delay(100);
}
void loop()
{
  data=0;
  data=analogRead(sensor);
  Serial.println(data);
  if(data>450)
  {
    SendMessage();
    digitalWrite(buzzer,HIGH);
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(relay,LOW);
  }
  else
  {
    digitalWrite(buzzer,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(relay,HIGH);
  }
}
void SendMessage()
{
  mySerial.println("AT+CMGF=1");
  delay(1000);
  mySerial.println("AT+CMGS=\"+8801302482643\"\r");
  delay(1000);
  mySerial.println("Ecess Gas Detected.");
  delay(100);
  mySerial.println((char)26);
  delay(1000);
}
