#include <Servo.h>

int Lecturas[10]; // Vector de lecturas para almacenar las lecturas del potenciómetro.
int Val, i = 0, Total = 0, Promedio = 0;
Servo Servo1; // Primer servo.
Servo Servo2; // Segundo servo.

void setup() {
  Servo1.attach(9); // Conecta el primer servo al pin 9.
  Servo2.attach(10); // Conecta el segundo servo al pin 10.
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios.
  for (i = 0; i < 10; i++) // Inicialización del vector Lecturas.
    Lecturas[i] = 0;
  i = 0;
}

void loop() {
  // Sustrae el total con la lectura inmediata anterior.
  Total = Total - Lecturas[i];
  
  // Agrega una lectura a la posición actual dentro del vector Lecturas.
  Lecturas[i] = analogRead(A0); // Conecta el potenciómetro al pin A0.

  // Realiza la sumatoria entre las últimas 10 lecturas.
  Total = Total + Lecturas[i];
  i = i + 1;

  // Calcula el promedio de las últimas 10 lecturas y ajusta el valor para los servos.
  if (i >= 10) {
    i = 0;
    Promedio = Total / 10;
    
    // Ajusta el valor para el primer servo (rango 0 a 179 grados).
    Val = map(Promedio, 0, 1023, 0, 179);
    Servo1.write(Val);
    
    // Ajusta el valor para el segundo servo (rango 179 a 0 grados).
    Val = map(Promedio, 0, 1023, 179, 0);
    Servo2.write(Val);
    
    // Muestra el valor en el monitor serial para propósitos de depuración.
    Serial.println(Val, DEC);
  }
}