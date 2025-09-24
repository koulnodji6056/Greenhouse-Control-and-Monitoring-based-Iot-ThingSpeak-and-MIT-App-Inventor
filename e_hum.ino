
void hum() {
  hum_internal = dht21.readHumidity();
  if (hum_internal < HUM_THRESHOLD_LOWER){  
    digitalWrite(Relay4_AirIn1, LOW);
   digitalWrite(Relay5_AirIn2, LOW);
   
  }else if(hum_internal > HUM_THRESHOLD_UPPER) { 
   digitalWrite(Relay6_AirOut2, LOW);
       
  }else{
   digitalWrite(Relay4_AirIn1, HIGH);
   digitalWrite(Relay5_AirIn2, HIGH);
   digitalWrite(Relay6_AirOut2, HIGH); 
  }          

}
