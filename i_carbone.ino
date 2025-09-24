void CarbonDioxyde() {
  Carbon = analogRead(InputCo2); 
 int ValueCo2 = Carbon-255;
 int co2good = map(Carbon, 0, 1024, 400, 5000);
}
