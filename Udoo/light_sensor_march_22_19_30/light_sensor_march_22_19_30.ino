 #define ANALOG_SENSOR_PIN A0
 #define DIGITAL_SENSOR_PIN 3
 #define LEDPIN 3 //Onboard led
 
 int switch_state; // Holds the last digital value
 int light_analog_value; // Holds the last analog value

void setup() {
  // put your setup code here, to run once:
  
  delay(3000);
  
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600);
  delay(3000);
  
  Serial.println("Light Sensor Test begin...");

}

void loop() {
  // put your main code here, to run repeatedly:
 
  delay(500);
 
  switch_state = digitalRead(DIGITAL_SENSOR_PIN);

  if (switch_state == LOW)
  {
    digitalWrite(LEDPIN, HIGH);
    Serial.println("Digital Signal on");
  }
  else
  {
    digitalWrite(LEDPIN, LOW);
    Serial.println("Digital Signal off");
  }

  light_analog_value = analogRead(ANALOG_SENSOR_PIN); // Read the voltage from sensor
  
  Serial.print("Analog value(0 - 1023): ");
  Serial.println(1023 - light_analog_value, DEC);
}
