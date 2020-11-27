

char phone_no[]="+989176538521";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(300);

  Serial.println("AT+CMGF=1");
  delay(1000);
  Serial.print("ATD");
  Serial.print(phone_no);
  delay(8000);
  Serial.println("ATH"); 
  
 
  
  
  

}

void loop() {
  
}
