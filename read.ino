#include <SoftwareSerial.h>
SoftwareSerial mySerial(3,2);

void setup() 
{
      Serial.begin(9600);
      mySerial.begin(9600);


      Serial.println("Initializing");
      delay(1000);


      mySerial.println("AT");
      updateSerial();

      //mySerial.println("AT+CMGD=0"); //delete all message
      //updateSerial();

      mySerial.println("AT+CMGF=1");
      updateSerial();

      //mySerial.println("AT+CNMI=2,2,0,0,0");
      //updateSerial();
      
    //  mySerial.println("AT+CMGR=1");
    //  updateSerial();

      String A1="AT+CMGL=";
      char A2='"';
      String A3="ALL";
      
      
      
      mySerial.println(A1+A2+A3+A2);
      updateSerial();

}

void loop() 
{


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
