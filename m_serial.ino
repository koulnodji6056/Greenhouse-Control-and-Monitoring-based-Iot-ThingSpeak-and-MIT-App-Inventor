void affich()
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
  unsigned long limite = 70000;
    
    DateTime now = rtc.now();
    //serial printing 
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(", ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.print(",");
    Serial.print(temp_internal);
    Serial.print(",");
    Serial.print(hum_internal);
    Serial.print(",");
    Serial.print(temp_external);
    Serial.print(",");
    Serial.print(hum_external);  
    Serial.print(",");
    Serial.print(pre1);    
    Serial.print(",");
    Serial.print(pre2);
    Serial.print(",");  
    Serial.print(pre3);
    Serial.print(",");
    Serial.print(pre4);
    Serial.print(",");
    Serial.print(ldr); 
    Serial.print(",");
    Serial.print(co2good); 
    Serial.print(",");
    if(temp_internal <= 25){
     Serial.print("cold");     
    } else if(temp_internal <= 27){
      Serial.print("warm");
    } else {
      Serial.print("hot");
    }
    Serial.print(",");
    Serial.print(state_1); 
    Serial.print(",");  
    Serial.print(state_2); 
    Serial.print(","); 
    Serial.print(state_3); 
    Serial.print(",");  
    Serial.print(state_4);
    Serial.print(",");  
    Serial.print(state_5);
    Serial.print(",");  
    Serial.print(state_6); 
    Serial.print(",");  
    Serial.print(state_7);   
    Serial.print(",");  
    Serial.println(state_8);            
  

}