void setup() {
  gprsSerial.begin(9600);               // the GPRS baud rate   
  Serial.begin(9600);
  dht22.begin();
  dht21.begin();
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //rtc.adjust(DateTime(2022, 6, 20, 8, 30, 0));
  SD.begin(53);
  //SD.remove("My.txt");
 
  tft.begin();
  tft.fillScreen(BLACK);
  tft.setRotation(1);  
  pinMode(Relay1_Heater1, OUTPUT);
  pinMode(Relay2_Heater2, OUTPUT);
  pinMode(Relay3_AirOut1, OUTPUT);
  pinMode(Relay4_AirIn1, OUTPUT);
  pinMode(Relay5_AirIn2, OUTPUT);  
  pinMode(Relay6_AirOut2, OUTPUT);
  pinMode(Relay7_solenoid1, OUTPUT);
  pinMode(Relay8_solenoid2, OUTPUT);
  pinMode(lampe_relay, OUTPUT);
  
  
  digitalWrite(Relay1_Heater1, HIGH);
  digitalWrite(Relay2_Heater2, HIGH); 
  digitalWrite(Relay3_AirOut1, HIGH);
  digitalWrite(Relay4_AirIn1, HIGH);
  digitalWrite(Relay5_AirIn2, HIGH); 
  digitalWrite(Relay6_AirOut2, HIGH);  
  digitalWrite(Relay7_solenoid1, HIGH);
  digitalWrite(Relay8_solenoid2, HIGH);
  digitalWrite(lampe_relay, HIGH);
  
}
