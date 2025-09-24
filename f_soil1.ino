void  soilMoisture1() {
 //for soil moisture sensor 1 in first range of the plant; for trays 1
 soil1 = analogRead(sensor1);
 pre1 = map(soil1, wet_sensor1, dry_sensor1, 100, 0);  
 //for soil moisture sensor 2 in first range of the plant; for trays 1
  soil2 = analogRead(sensor2);
  pre2 = map(soil2, wet_sensor2, dry_sensor2, 100, 0);  
  if (pre1 < CUT_OFF_MOISTURE_PERCENATGE_1 || pre2 < CUT_OFF_MOISTURE_PERCENATGE_1){  
   digitalWrite(Relay7_solenoid1, HIGH);  
  }else{
    digitalWrite(Relay7_solenoid1, LOW);     
  }    
}