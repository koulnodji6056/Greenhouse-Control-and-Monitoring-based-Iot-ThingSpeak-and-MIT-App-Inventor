
void temp() {
  temp_internal = dht21.readTemperature(); 
  if(temp_internal < TEMP_THRESHOLD_LOWER){
   digitalWrite(Relay1_Heater1, LOW);
   digitalWrite(Relay2_Heater2, LOW);   
     
  }else if(temp_internal > TEMP_THRESHOLD_UPPER) { 
   digitalWrite(Relay3_AirOut1, LOW);
    
  }else{
   digitalWrite(Relay1_Heater1, HIGH);
   digitalWrite(Relay2_Heater2, HIGH);
   digitalWrite(Relay3_AirOut1, HIGH);
  }  
  
} 
