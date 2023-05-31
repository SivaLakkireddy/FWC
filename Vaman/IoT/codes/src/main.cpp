//----------------------Skeleton Code--------------------//
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "SIVA"  // Replace with your network credentials
#define STAPSK  "siva1234"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;
int X=0,C=0,B=0,A=0;   
int Y,R,Q,P; 

void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//

void setup(){
  OTAsetup();

  //-------------------//
  // Custom setup code //
  //-------------------//
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT); 
    pinMode(4, OUTPUT);   
    pinMode(5, OUTPUT);  
    
    pinMode(13, OUTPUT); 
    
    pinMode(6, INPUT);  
    pinMode(7, INPUT);  
    pinMode(8, INPUT);
    pinMode(9, INPUT); 
}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//

  A = digitalRead(6);
  B= digitalRead(7);
  C = digitalRead(8);
  X= digitalRead(9);
  
  P=(B&&C&&X);
  Q=(B&&!C&&!X)||(!B&&C&&X)||(A&&!X);
  R=(!X);
  Y=(A&&!X);

  digitalWrite(2, P);
  digitalWrite(3, Q);
  digitalWrite(4, R);
  digitalWrite(5, Y);
  
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);
  delay(2000);

}
