#include <OneWire.h>
#include <DallasTemperature.h>
/*
------RECORDATORIO------
Conecciones: 
Sensore temperatura de mate PIN 2
Sensore temperatura de te PIN 3
Rele resistencia PIN 13
Rele resistencia PIN 12
-------------------------
IMPORTANTE: Posee sisterma de monitor en serie
para verificar el funcionamiento de los sensores
*/


// Define los pines a los que están conectados los sensores DS18B20
const int sensor1Pin = 2;  // Sensor 1 conectado en el pin 2
const int sensor2Pin = 3;  // Sensor 2 conectado en el pin 3

// Inicializa los buses OneWire para ambos sensores
OneWire oneWire1(sensor1Pin);
OneWire oneWire2(sensor2Pin);

// Inicializa las bibliotecas DallasTemperature para ambos sensores
DallasTemperature sensors1(&oneWire1);
DallasTemperature sensors2(&oneWire2);

void setup() {
  // Inicializa la comunicación serial
  Serial.begin(9600);

  // Inicializa los sensores DS18B20
  sensors1.begin();
  sensors2.begin();

  pinMode(13, OUTPUT); // Rele resistencia para mate conectado al pin 13
  pinMode(12, OUTPUT); // Rele resistencia para mate conectado al pin 12
}

void loop() {
  // Llama a las funciones para obtener la temperatura de ambos sensores
  float TemperaturaMate = getTemperature(sensors1, 0);
  float TemperaturaTe = getTemperature(sensors2, 0);

  /*
  Si la temperatura es menor a 30° se enciende el relé, y 
  si la temperatura es mayor a 60 se apaga el relé
  */
  if (TemperaturaMate < 30) {
    digitalWrite(13, HIGH);  // Enciende el relé
  } else if (TemperaturaMate > 60) {
    digitalWrite(13, LOW);  // Apaga el relé
  }

  /*
  si la temperatura es menor a 30° se enciende el relé, y 
  si la temperatura es mayor a 80° se apaga el relé.
  */
  if (TemperaturaTe < 30) {
    digitalWrite(12, HIGH);  // Enciende el relé
  } else if (TemperaturaTe > 80) {
    digitalWrite(12, LOW);  // Apaga el relé
  }

  // Muestra las temperaturas en el monitor serial
  Serial.print("Temperatura Mate: ");
  Serial.print(TemperaturaMate);
  Serial.println(" °C");

  Serial.print("Temperatura Te: ");
  Serial.print(TemperaturaTe);
  Serial.println(" °C");

  // Espera un momento antes de tomar otra lectura
  delay(500);
}

float getTemperature(DallasTemperature &sensors, int index) {
  // Solicita la lectura de temperatura al sensor específico
  sensors.requestTemperatures();

  // Lee la temperatura en grados Celsius
  return sensors.getTempCByIndex(index);
}