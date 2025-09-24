void loop() {
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
  curent=millis();
  if((curent-last)>thresh){
    DateTime now = rtc.now();
    MyFile = SD.open("growing.csv", FILE_WRITE);
    MyFile.print(now.year(), DEC);
    MyFile.print('/');
    MyFile.print(now.month(), DEC);
    MyFile.print('/');
    MyFile.print(now.day(), DEC);
    MyFile.print(", ");
    MyFile.print(now.hour(), DEC);
    MyFile.print(':');
    MyFile.print(now.minute(), DEC);
    MyFile.print(':');
    MyFile.print(now.second(), DEC);
    MyFile.print(",");
    MyFile.print(temp_internal);
    MyFile.print(",");
    MyFile.print(hum_internal);
    MyFile.print(",");
    MyFile.print(temp_external);
    MyFile.print(",");
    MyFile.print(hum_external);  
    MyFile.print(",");
    MyFile.print(pre1);    
    MyFile.print(",");
    MyFile.print(pre2);
    MyFile.print(",");  
    MyFile.print(pre3);
    MyFile.print(",");
    MyFile.print(pre4);
    MyFile.print(",");
    MyFile.print(ldr);
    MyFile.print(",");
    MyFile.print(co2good); 
    MyFile.print(",");
    if(temp_internal <= 25){
     MyFile.print("cold");     
    } else if(temp_internal <= 27){
      MyFile.print("warm");
    } else {
      MyFile.print("hot");
    }
    MyFile.print(",");
    MyFile.print(state_1); 
    MyFile.print(",");  
    MyFile.print(state_2); 
    MyFile.print(","); 
    MyFile.print(state_3); 
    MyFile.print(",");  
    MyFile.print(state_4);
    MyFile.print(",");  
    MyFile.print(state_5);
    MyFile.print(",");  
    MyFile.print(state_6);
    MyFile.print(",");  
    MyFile.print(state_7);
    MyFile.print(",");  
    MyFile.println(state_8);    
    MyFile.close();
    last = curent;
  }

  //logger();
  temp();
  delay(1000);
  hum();
  delay(1000);
  soilMoisture1();
  delay(1000);
  soilMoisture2();
  delay(1000);
  LDR();
  delay(1000);
  CarbonDioxyde(); 
  delay(1000);
  //display();
  //cloudData();
  affich();  
  delay(1000);  
}