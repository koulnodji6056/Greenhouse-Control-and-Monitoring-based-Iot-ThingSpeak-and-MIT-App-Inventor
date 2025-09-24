void  LDR(){
  ldr = analogRead(light);
  /*
  if (ldr < 700){ 
   digitalWrite(lampe_relay, HIGH);
  }else{
   digitalWrite(lampe_relay, LOW);
  }
  */ 
}