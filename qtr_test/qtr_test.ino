#include <QTRSensors.h>

QTRSensors qtr;

const uint8_t SensorCount = 3;  // Número de sensores en el conjunto
uint16_t sensorValues[SensorCount];  // Array para almacenar los valores de los sensores

void setup() {
  // Coloca tu código de configuración aquí, que se ejecutará una vez:
  qtr.setTypeAnalog();  // Configura los sensores para utilizar señales analógicas
  qtr.setSensorPins((const uint8_t[]){A0, A1, A2}, SensorCount);  // Asigna los pines de los sensores
  //qtr.setEmitterPin(2);  // Configura el pin del emisor infrarrojo

  delay(500);  // Espera 500 ms
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);  // Enciende el LED incorporado de Arduino para indicar que estamos en modo de calibración

  // La función analogRead() toma alrededor de 0.1 ms en un AVR.
  // 0.1 ms por sensor * 4 muestras por lectura de sensor (valor predeterminado) * 6 sensores
  // * 10 lecturas por llamada a calibrate() = aproximadamente 24 ms por llamada a calibrate().
  // Llama a calibrate() 400 veces para que la calibración dure alrededor de 10 segundos.
  for (uint16_t i = 0; i < 80; i++)
  {
    qtr.calibrate();
  }
  digitalWrite(LED_BUILTIN, LOW);  // Apaga el LED de Arduino para indicar que hemos terminado con la calibración

  // Imprime los valores mínimos de calibración medidos cuando los emisores estaban encendidos
  Serial.begin(9600);
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();

  // Imprime los valores máximos de calibración medidos cuando los emisores estaban encendidos
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
  delay(1000);
}

void loop() {
  // Lee los valores calibrados de los sensores y obtén una medida de la posición de la línea
  // de 0 a 5000 (para una línea blanca, utiliza readLineWhite() en su lugar)
  uint16_t position = qtr.readLineBlack(sensorValues);

  // Imprime los valores de los sensores como números de 0 a 1000, donde 0 significa reflectancia máxima
  // y 1000 significa reflectancia mínima, seguido de la posición de la línea
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println(position);

  delay(20); 
}