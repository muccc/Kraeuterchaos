const int AirValue = 520;   
const int WaterValue = 260;  
int intervals = (AirValue - WaterValue)/3;   
int soilMoistureValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}


void loop() {
  digitalWrite(8, LOW); 
  water();
  
}

void water() {
soilMoistureValue = analogRead(A0); 
if(soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals))
{
  Serial.println("Very Wet");
}
else if(soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals))
{
  Serial.println("Wet");
}
else if(soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals))
{
  Serial.println("Dry");
}
delay(10000);
}
