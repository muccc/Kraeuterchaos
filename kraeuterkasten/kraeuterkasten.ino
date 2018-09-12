const int AirValue = 520;   
const int WaterValue = 260;  
int intervals = (AirValue - WaterValue)/3;   
int soilMoistureValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT); //LED
  pinMode(7, OUTPUT); //PUMP
}


void loop() {
  
  digitalWrite(7, HIGH);
  soilMoistureValue = analogRead(A0); 
if(soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals))
{
  Serial.println("Very Wet");
  digitalWrite(7, HIGH);
}
else if(soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals))
{
  Serial.println("Wet");
  digitalWrite(7, HIGH);
}
else if(soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals))
{
   Serial.println("Dry");
  digitalWrite(7, LOW);
}
delay(1000);
}


