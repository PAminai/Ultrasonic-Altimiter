int PingPin=13; //transmit
int EchoPin=12; //receave


void setup() {
pinMode(PingPin,OUTPUT);
pinMode(EchoPin,INPUT);
Serial.begin(9600);
}

void loop() {
  unsigned long duration,cm ;
digitalWrite(PingPin,LOW);
delayMicroseconds(2);

digitalWrite(PingPin,HIGH);
delayMicroseconds(5);

digitalWrite(PingPin,HIGH);

duration=pulseIn(EchoPin,HIGH);

cm=MicroToCm(duration);
Serial.print(cm);
Serial.println("cm");

}

unsigned long MicroToCm(unsigned long Micro){
  return(Micro/29)/2;
}

