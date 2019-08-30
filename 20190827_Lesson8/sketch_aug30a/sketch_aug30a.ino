const int Led_pin = 8;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // initial the serial0
  pinMode(Led_pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char CMD='?';
  while(Serial.available()<1) ;
  Serial.readBytes(&CMD,1);

  if(CMD=='A') digitalWrite(Led_pin,0);
  if(CMD=='B') digitalWrite(Led_pin,1);
  
  Serial.write("OK");
  delay(1000); // Unit:ms
}
