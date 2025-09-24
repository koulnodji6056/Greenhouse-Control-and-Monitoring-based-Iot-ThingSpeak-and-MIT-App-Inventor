void cloudData()
{
  temp_internal = dht21.readTemperature();
  temp_external = dht22.readTemperature();
  hum_internal = dht21.readHumidity();
  hum_external = dht22.readHumidity();     
  soil1 = analogRead(sensor1);
  pre1 = map(soil1, wet_sensor1, dry_sensor1, 100, 0); 
  soil2 = analogRead(sensor2); 
  pre2 = map(soil2, wet_sensor2, dry_sensor2, 100, 0); 
  soil3 = analogRead(sensor3);
  pre3 = map(soil3, wet_sensor3, dry_sensor3, 100, 0);  
  soil4 = analogRead(sensor4);
  pre4 = map(soil4, wet_sensor4, dry_sensor4, 100, 0); 
  ldr = analogRead(light);
  Carbon = analogRead(InputCo2);  
  int ValueCo2 = Carbon-255;
  int co2good = map(Carbon, 0, 1024, 400, 5000);  

  int state_1 = digitalRead(Relay1_Heater1);
  int state_2 = digitalRead(Relay2_Heater2);
  int state_3 = digitalRead(Relay3_AirOut1);
  int state_4 = digitalRead(Relay4_AirIn1);  
  int state_5 = digitalRead(Relay5_AirIn2);
  int state_6 = digitalRead(Relay6_AirOut2);    
  int state_7 = digitalRead(Relay7_solenoid1);
  int state_8 = digitalRead(Relay8_solenoid2);
  int state_9 = digitalRead(lampe_relay);
  
  if (gprsSerial.available())    
  {
    Serial.write(gprsSerial.read());
 
   gprsSerial.println("AT");
   delay(1000);
 
   gprsSerial.println("AT+CPIN?");
   delay(1000);
 
   gprsSerial.println("AT+CREG?");
   delay(1000);
 
   gprsSerial.println("AT+CGATT?");
   delay(1000);
 
   gprsSerial.println("AT+CIPSHUT");
   delay(1000);
 
   gprsSerial.println("AT+CIPSTATUS");
   delay(2000);
 
   gprsSerial.println("AT+CIPMUX=0");
   delay(2000);
 
   ShowSerialData();
 
   gprsSerial.println("AT+CSTT=\"internet\"");//start task and setting the APN,
   delay(1000);
 
   ShowSerialData();
 
   gprsSerial.println("AT+CIICR");//bring up wireless connection
   delay(3000);
 
   ShowSerialData();
 
   gprsSerial.println("AT+CIFSR");//get local IP adress
   delay(2000);
 
   ShowSerialData();
 
   gprsSerial.println("AT+CIPSPRT=0");
   delay(3000);
 
   ShowSerialData();
  
   gprsSerial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");//start up the connection
   delay(2000);
 
   ShowSerialData();
 
   gprsSerial.println("AT+CIPSEND");//begin send data to remote server
   delay(1000);
   ShowSerialData();
  
   String str="GET https://api.thingspeak.com/update?api_key=0ONK2QQZ8C62Y6PX&field1=" + String(temp_internal) +"&field2="+String(hum_internal) +"&field3="+String(temp_external) +"&field4="+String(hum_external) +"&field5="+String(pre1) +"&field6="+String(pre3) +"&field7="+String(co2good) +"&field8="+String(ldr);
   Serial.println(str);
   gprsSerial.println(str);//begin send data to remote server
   Serial.println(str);
   delay(1000);
   ShowSerialData();
 
   gprsSerial.println((char)26);//sending
   delay(3000);//waitting for reply, important! the time is base on the condition of internet 
   gprsSerial.println();
 
   ShowSerialData();
 
   gprsSerial.println("AT+CIPSHUT");//close the connection
   delay(100);
   ShowSerialData();
  }
} 
void ShowSerialData()
{
  while(gprsSerial.available()!=0)
  Serial.write(gprsSerial.read()); 
}