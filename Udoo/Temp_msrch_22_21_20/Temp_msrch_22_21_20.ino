#include <OneWire.h>
#include <DallasTemperature.h>

#define ONEWIRE_BUS 7

OneWire Wire(ONEWIRE_BUS);

DallasTemperature sensors(&Wire);

void setup() {
  // put your setup code here, to run once:
  
  delay(3000);
  
  Serial.begin(9600);
  delay(3000);
  
  Serial.println("DS18B20 Temp Sensor with OneWire and Dallas Temperature libraries");
  Serial.println("Starting sensor(s)...");
  
  sensors.begin();
  delay(3000);

}

void loop() {
  // put your main code here, to run repeatedly: 
  
  Serial.println("");
  
  Serial.print(sensors.getTempCByIndex(0));
  Serial.println(" degrees C");
  Serial.print("Device 0 at index 0 = ");
  Serial.print(sensors.getTempFByIndex(0));
  Serial.println(" degrees F");
  
}
