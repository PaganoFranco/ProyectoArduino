
// Incluye la librería para el sensor ultrasónico
#include <NewPing.h>

// Define los pines para el sensor ultrasónico
#define TRIGGER_PIN  2  
#define ECHO_PIN     3  
#define MAX_DISTANCE 200 

// Define el pin del LED
#define LED 13

// Crea una instancia del sensor ultrasónico
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // Inicializa el pin del LED como salida
  pinMode(LED, OUTPUT);
}

void loop() {
  // Realiza la medición de distancia
  unsigned int distance = sonar.ping_cm();

  // Si la distancia es menor que 5 cm, enciende el LED, de lo contrario, apágalo
  if (distance > 20) {
    digitalWrite(LED, HIGH);  // Enciende el LED
    delay(1000);
    digitalWrite(LED, LOW);  // Enciende el LED
    delay(1000);
  } else {
    digitalWrite(LED, LOW);
  }


  // Espera un breve período antes de realizar la siguiente medición
  delay(100);
}
