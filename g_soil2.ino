void  soilMoisture2() {
  //for soil moisture sensor 3 in second range of the plant; for trays 2
 soil3 = analogRead(sensor3);
 pre3 = map(soil3, wet_sensor3, dry_sensor3, 100, 0);  
 //for soil moisture sensor 4 in second range of the plant; for trays 2
 soil4 = analogRead(sensor4);
 pre4 = map(soil4, wet_sensor4, dry_sensor4, 100, 0);  
  if (pre3 < CUT_OFF_MOISTURE_PERCENATGE_2 || pre4 < CUT_OFF_MOISTURE_PERCENATGE_2 ){
    digitalWrite(Relay8_solenoid2, HIGH); 
  }else{
    digitalWrite(Relay8_solenoid2, LOW);
  }         
}