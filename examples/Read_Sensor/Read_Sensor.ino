#define SENSOR_PIN 2

#include <zph02.h>

zph02 aqi_sensor(10);



void setup() {

  
Serial.begin(115200);

Serial.println("ZPH02 Sensor Init");

  while(!Serial){
    delay(100);
    }

    
  aqi_sensor.begin(SENSOR_PIN);

}

void loop() {


// Get Current AQI Moving Average 
float AQI = aqi_sensor.getAqi(false);

Serial.print("AQI Moving Average: ");

Serial.println(AQI);
Serial.println();



// Get Current Duty Cycle
float DutyCycle = aqi_sensor.getAqi(true);

Serial.print("Current Sensor Duty Cycle: ");

Serial.println(DutyCycle);
Serial.println();
     

    
  
}
