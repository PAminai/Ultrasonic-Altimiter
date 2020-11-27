#include <SoftwareSerial.h>
/*
#include <GSM.h>
#include <GSM3CircularBuffer.h>
#include <GSM3IO.h>
#include <GSM3MobileAccessProvider.h>
#include <GSM3MobileCellManagement.h>
#include <GSM3MobileClientProvider.h>
#include <GSM3MobileClientService.h>
#include <GSM3MobileDataNetworkProvider.h>
#include <GSM3MobileMockupProvider.h>
#include <GSM3MobileNetworkProvider.h>
#include <GSM3MobileNetworkRegistry.h>
#include <GSM3MobileServerProvider.h>
#include <GSM3MobileServerService.h>
#include <GSM3MobileSMSProvider.h>
#include <GSM3MobileVoiceProvider.h>
#include <GSM3ShieldV1.h>
#include <GSM3ShieldV1AccessProvider.h>
#include <GSM3ShieldV1BandManagement.h>
#include <GSM3ShieldV1BaseProvider.h>
#include <GSM3ShieldV1CellManagement.h>
#include <GSM3ShieldV1ClientProvider.h>
#include <GSM3ShieldV1DataNetworkProvider.h>
#include <GSM3ShieldV1DirectModemProvider.h>
#include <GSM3ShieldV1ModemCore.h>
#include <GSM3ShieldV1ModemVerification.h>
#include <GSM3ShieldV1MultiClientProvider.h>
#include <GSM3ShieldV1MultiServerProvider.h>
#include <GSM3ShieldV1PinManagement.h>
#include <GSM3ShieldV1ScanNetworks.h>
#include <GSM3ShieldV1ServerProvider.h>
#include <GSM3ShieldV1SMSProvider.h>
#include <GSM3ShieldV1VoiceProvider.h>
#include <GSM3SMSService.h>
#include <GSM3SoftSerial.h>
#include <GSM3VoiceCallService.h>
*/




int trig=13 , echo=12, tx=10, rx=11;
boolean trigered=false;
long Distance,duration,normalDistance;
SoftwareSerial sim(10,11); // 10=RX   11=TX




void setup() {
sim.begin(9600);
Serial.begin(9600);
pinMode(echo,INPUT);
pinMode(trig,OUTPUT);

while(millis()<5000)
{
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

duration=pulseIn(echo,HIGH);
Distance=duration*0.17*1000;
normalDistance=Distance;
Serial.print("Distance:");
Serial.println(Distance);  
}

}

void loop() {
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

duration=pulseIn(echo,HIGH);
Distance=duration*0.17*1000; //bar hasbe milimetr
if(Distance<=100)
{
  sim.println("AT");
  sim.println("AT+CMGF=1");
  sim.println("AT+CMGS=\"+989176538521\"");
  sim.println("This is POORYA");

    sim.write(0x1A);
  //  sim.write(0x0D);
  //  sim.write(0x0A);
  
}
}
