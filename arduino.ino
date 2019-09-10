#include <OneWire.h>
#include <DallasTemperature.h>

int DS18B20 = 7;
OneWire ourWire(DS18B20); //CONFIGURA UMA INSTÂNCIA ONEWIRE PARA SE COMUNICAR COM O SENSOR
DallasTemperature sensors(&ourWire); //BIBLIOTECA DallasTemperature UTILIZA A OneWire
  
void setup(){
  configureSerial();
  startSensors();
  configureDelaySetup();
}

void loop(){
  loopTemperatureSensor();
  loopTurbiditySensor();
  delay(250);
}

void startSensors(){
  sensors.begin();
}

void configureDelaySetup(){
  delay(1000);
}

void configureSerial(){
  Serial.begin(9600);
}

void loopTemperatureSensor(){
  float temperature = getTemperature();
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.print("*C\n");
}

void loopTurbiditySensor(){
  float turbidity = getTurbidity();
  Serial.print("Turbidity: ");
  Serial.print(turbidity);
  Serial.print("\n");
  delay(500);
}

float getTemperature(){
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}

float getTurbidity(){
  int sensorValue = analogRead(A7);
  float turbidity = sensorValue * (5.0 / 1024.0);
  return turbidity;
}
