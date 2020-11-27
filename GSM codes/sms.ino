#include <SoftwareSerial.h>


SoftwareSerial mySerial(3,2);

const int TRIG_PIN = 12;
const int ECHO_PIN = 13;  

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);
  mySerial.begin(9600);

  Serial.println("Initializing");
  delay(1000);



  mySerial.println("AT");
  updateSerial();




    

  


  
}

void loop() {
  unsigned long duration, cm ;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(5);

  digitalWrite(TRIG_PIN, HIGH);

  duration = pulseIn(ECHO_PIN, HIGH);

  cm = MicroToCm(duration);
//  Serial.print(cm);
//  Serial.println("cm");

if(cm==5)
{
  



    mySerial.println("AT+CMGF=1");
    updateSerial();
    mySerial.println("AT+CMGS=+989176538521");
    updateSerial();
    mySerial.print(cm + " cm");
    updateSerial();
    mySerial.write(26);
}
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

  unsigned long MicroToCm(unsigned long Micro) {
  return (Micro / 29) / 2;
}
  
