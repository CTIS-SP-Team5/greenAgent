 /*
 Preliminary test code
 Created by A.Cemil SABIR
 acsabir@gmail.com
 Creation date: 31.3.2014 20:20
 
 This is the code that will be run un Arduino DUE. Simply
 write down the code in C++, and press upload button in 
 Arduino IDE. It will compile the code and upload it to the
 Arduino via serial programming port. 
 
 This is the code snipplet for
 three of the sensors which use the same microcontroller
 type. These three sensors are moisture sensor, 
 humidity and rain (which we'll use to check and ensure 
 irrigation actuator) sensor, and luminosity sensor. 
  */
 
 /*
 
 Defining the analog ports to read an analog value for each
 sensor output. The range of analog output is 0 - 1024. The
 sensor microcontroller actually returns an inversed analog
 output(1023 for none, 0 for full intensity), but that is 
 confusing and we reverse it before printing it to the serial
 console. Conversion to SI units is the duty of the listeners
 on the serial line, so as not to stress Arduino DUE chip.
 
 */
 
 #define ANALOG_SENSOR_PIN_HUMIDITY A0
 #define ANALOG_SENSOR_PIN_IRRIGATION A1
 #define ANALOG_SENSOR_PIN_LUMINOSITY A2
 
 /*
 
 There is a bug in the baraometer sensor's library; therefore,
 though its constants are declared as a placeholder, it is 
 not implemented.
 
 */
 
 #define ANALOG_SENSOR_PIN_BAROMETER A3      
 
 /*
 
 We still have not gotten the resistors for the thermometer
 sensors. Therefore, though the constants are declared,
 they are not implemented.
 
 */
 
 #define ANALOG_SENSOR_PIN_THERMOMETER A4
 
 /*
 
 We still have not gotten the power adapterf for CO2 sensors.
 Therefore, though the constants are declared, they are 
 not implemented.
 
 */
 
 #define ANALOG_SENSOR_PIN_CO2 A5
 
 /*
 
 Define a constant interval in milliseconds to wait between 
 sensor reading blocks.
 
 */
 
 #define SENSOR_READ_INTERVAL 3000
 
 /*
 
 Define a constant interval in milliseconds to wait for
 initializations to complete.
 
 */
 
 #define INIT_DELAY 3000
  
 /*
 
 Define a constant baud rate which will determine the speed 
 of the serial line.
 
 */
  
 #define BAUD_RATE 9600      // Default value. 
  
 /*
 
 Defining the digital ports. Digital ports has only two states,
 which are HIGH and LOW. They state that the sensor readings
 passed the threshold, but since these thresholds are set 
 manually digital outputs are of no use to us. Still, we need 
 to set them in order for sensors to work correctly.
 
 */
 
 #define DIGITAL_SENSOR_PIN_IRRIGATION 0
 #define DIGITAL_SENSOR_PIN_HUMIDITY 1
 #define DIGITAL_SENSOR_PIN_LUMINOSITY 2
 #define DIGITAL_SENSOR_PIN_BAROMETER 3
 #define DIGITAL_SENSOR_PIN_THERMOMETER 4
 #define DIGITAL_SENSOR_PIN_CO2 5
 
 /*
 
 Here we define variables that holds the last digital values 
 read from the digital output ports of the sensors. Again, 
 this is pointless, in terms of operation of the sensors, but 
 we keep these to better track the operational health of the 
 sensor. So far,  these may flactuate, and often do, but have 
 no effect on the operation of the sensors.
 
 */
 
 int humidity_state,       // Holds the last digital value read from humidity sensor.
     irrigation_state,     // Holds the last digital value read from irrigation sensor.
     luminosity_state,     // Holds the last digital value read from luminosity sensor.
     barometer_state,      // Holds the last digital value read from barometer sensor.
     thermometer_state,    // Holds the last digital value read from thermometer sensor.
     co2_state;            // Holds the last digital value read from carbon dioxide sensor.
 
 
 /*
 
 Here we define variables that holds the last analog values
 read from analog ports of the sensors. Again, these are raw
 data. It's the responsability of whoever is reading the
 serial port.
 
 */
 
 int humidity_analog_value,         // Holds the last analog value read from humidity sensor.
     irrigation_analog_value,       // Holds the last analog value read from irrigation sensor.
     luminosity_analog_value,       // Holds the last analog value read from luminosity sensor.
     barometer_analog_value,        // Holds the last analog value read from barometer sensor.
     thermometer_analog_value,      // Holds the last analog value read from thermometer sensor.
     co2_analog_value;              // Holds the last analog value read from carbon dioxide sensor.



/*

setup() function is run once at the start of the execution of
the code. All of the initialization code that will (and needs
to) run once should go here. 

*/

void print_line(char buffer[])
{
  
  int index = 0;
  char tmp[128];
  int tmp_size = 0;
  
  while (buffer[index] != '\0')
  {
    if (index != 0 && tmp_size == 127)
    {
      tmp[127] = '\0';
      Serial.print(tmp);
      tmp_size = 0;
    }
    
    tmp[tmp_size++] = buffer[index++];
  }
  
  if (index % 128 != 0)
  {
    int last = (index / 128) * 128;      // Integer division, be careful.
    int end = index;
    tmp_size = 0;
    
    while (buffer[index] != '\0')
    {
      tmp[tmp_size++] = buffer[index++];
    }
    
    while (end - index > 0)
    {
      tmp[tmp_size++] = ' '; 
    }
    
    tmp[tmp_size] = '\0';
    
    Serial.print(tmp);
  }
  
}

void setup() {
  
  /* 
  
  At the initial stage of the execution, where initilization
  of the serial line occurs, sometimes the output delays and
  we cannot catch the first lines put to serial rapidly. 
  Therefore, we delay for 3 seconds to give breathing time 
  to whatever background operations are running.
  
  */
  
  delay(INIT_DELAY);
  
  /*
  
  Start the serial line. Note that there is a bug about putting
  float types into the serial line, which is known and waiting
  to be fixed. For now, we will convert float types to strings
  or integers(where loss of precision is of no concern).
  
  */
  
  Serial.begin(BAUD_RATE);
  
  /*
  
  Again, we need to hang back for a little bit for the serial
  line to be initialized, or, on some occasions, rapidly put
  output will not be flushed into the serial line. In addition,
  a little bit of time is need to manually open the serial
  line monitor. Also, the listeners on the serial line may
  need time to finish initialization, thus, this delay is of
  essential nature. 
  
  */
  
  delay(INIT_DELAY);
  
  
  /* 
  
  Wellcome messages and warnings. 
  
  */
  
  Serial.println("****************************************************************************");
  Serial.println("* Green Agent embedded code testing...                                     *");
  Serial.println("*                                                                          *");
  Serial.println("* Serial line initialized.                                                 *");
  Serial.println("*                                                                          *");
  Serial.println("* This is the test code for sensors: humidity, irrigation, and luminosity. *");
  Serial.println("*                                                                          *");
  Serial.println("* WARNING: Raw values read from the sensors will be put on serial line.    *");
  Serial.println("* Value range: 0 - 1023                                                    *");
  Serial.println("* 0 means no reading while 1023 means maximum reading. The conversations   *");
  Serial.println("* is the responsability of whoever is listening to the serial line.        *");
  Serial.println("****************************************************************************");

}

/*

loop() is the function that, after setup() function finishes
execution, runs in an infinite loop. Inconveniently, Arduino
does not support multithreading or multitasking; therefore,
all the readings and different sensor operations needs to be
done in sequential order, which means care needs to be taken
when some operation is supposed to take a long time to 
complete(such as delays). There is a NASA project, for Arduino 
and Rasperrypie, that aims to inspect a multitasking and 
multithreading library. Go check it.

*/

void loop() {
  // put your main code here, to run repeatedly:
 
  /*
  
  This delay specifies the time interval between subsequent
  sensor readings. Note that all the operations done in the
  loop() function should be regarded as a block, and this 
  interval is the time difference between the end of the last
  iteration and the start of the next iteration. While the
  total execution time can be estimated approximately by 
  manually timing, it cannot be guaranteed.
  
  */
  
  delay(SENSOR_READ_INTERVAL);
 
  // Read digital outputs.
  humidity_state = digitalRead(DIGITAL_SENSOR_PIN_HUMIDITY);
  irrigation_state = digitalRead(DIGITAL_SENSOR_PIN_IRRIGATION);
  luminosity_state = digitalRead(DIGITAL_SENSOR_PIN_LUMINOSITY);
  // barometer_state = digitalRead(DIGITAL_SENSOR_PIN_BAROMETER);          // Waiting bug fix.
  // thermometer_state = digitalRead(DIGITAL_SENSOR_PIN_THERMOMETER);      // Waiting resistors.
  // co2_state = digitalRead(DIGITAL_SENSOR_PIN_CO2);                      // Waiting power adapter.

  // Read analog outputs.
  humidity_analog_value = analogRead(ANALOG_SENSOR_PIN_HUMIDITY);          // Read the voltage from sensor.
  irrigation_analog_value = analogRead(ANALOG_SENSOR_PIN_IRRIGATION);      // Read the voltage from sensor.
  luminosity_analog_value = analogRead(ANALOG_SENSOR_PIN_LUMINOSITY);      // Read the voltage from sensor.
  // barometer_analog_value = analogRead(ANALOG_SENSOR_PIN_BAROMETER);     // Waiting bug fix.
  // thermometer_analog_value = analogRead(ANALOG_SENSOR_PIN_THERMOMETER); // Waiting resistors.
  // co2_analog_value = analogRead(ANALOG_SENSOR_PIN_CO2);                 // Waiting power adapter.
  
  // Print analog values to the serial line.
  Serial.println("");
  Serial.print("Humidity:   ");
  Serial.println(1023 - humidity_analog_value, DEC);
  
  Serial.print("Irrigation: ");
  Serial.println(1023 - irrigation_analog_value, DEC);
  
  Serial.print("Luminosity: ");
  Serial.println(1023 - luminosity_analog_value, DEC);
  
  /* 
  
  Serial.print("pressure: ");
  Serial.println(1023 - barometer_analog_value, DEC);
  
  Serial.print("Temperature: ");
  Serial.println(1023 - thermometer_analog_value, DEC);
  
  Serial.print("CO2: ");
  Serial.println(1023 - co2_analog_value, DEC);
  
  */
  
  // End of code. That's it!
}
