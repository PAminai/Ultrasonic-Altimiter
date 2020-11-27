#include <SoftwareSerial.h>


SoftwareSerial mySerial(3,2);

char phone_no[]="+989176538521";
void setup() {

  Serial.begin(9600);
  mySerial.begin(9600);

  Serial.println("Initializing");
  delay(1000);

  mySerial.println("AT");
  updateSerial();
  
  mySerial.println("AT");
  updateSerial();
  
  mySerial.println("AT+CSQ");
  updateSerial();
  
  mySerial.println("AT+CCID");
  updateSerial();

  
  mySerial.println("AT+CREG?");
  updateSerial();
  
  mySerial.println("ATI");
  updateSerial();
  
  mySerial.println("AT+COPS?");
  updateSerial();


  mySerial.println("AT+COPS=?");
  updateSerial();
 
}

void loop() {
  // put your main code here, to run repeatedly:

}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
