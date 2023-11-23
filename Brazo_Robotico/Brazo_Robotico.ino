#include <Servo.h>

int Lecturas[10]; // Vector de lecturas para almacenar las lecturas del potenciómetro.
int Lecturas1[10]; // Vector de lecturas para almacenar las lecturas del potenciómetro.
int LecturaPulsador = 0; // Variable para almacenar la lectura del pulsador.
int Val, Val1, i = 0, Total = 0, Promedio = 0, j = 0, Total1 = 0, Promedio1 = 0;
Servo Servo1; // Primer servo.
Servo Servo2; // Segundo servo.
Servo Servo3; // Tercer servo.
Servo Servo4; // Cuarto servo.
int abre = 7;
int cierra = 6; 
int ValorPulsador = 0; 

void setup() {
  Servo1.attach(9); // Conecta el primer servo al pin 9.
  Servo2.attach(10); // Conecta el segundo servo al pin 10.
  Servo3.attach(11); // Conecta el segundo servo al pin 11.
  Servo4.attach(12); // Conecta el segundo servo al pin 12.
  pinMode(abre, INPUT_PULLUP);
  pinMode(cierra, INPUT_PULLUP);
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios.
  for (i = 0; i < 10; i++) // Inicialización del vector Lecturas.
    Lecturas[i] = 0;
  i = 0;
  for (j = 0; j < 10; j++) // Inicialización del vector Lecturas.
    Lecturas1[j] = 0;
  i = 0;
}

void loop() {
  // Sustrae el total con la lectura inmediata anterior.
  Total = Total - Lecturas[i];
  
  // Agrega una lectura a la posición actual dentro del vector Lecturas.
  Lecturas[i] = analogRead(A0); // Conecta el potenciómetro al pin A0.
  Lecturas1[j] = analogRead(A1);
  // Realiza la sumatoria entre las últimas 10 lecturas.
  Total = Total + Lecturas[i];
  i = i + 1;

  Total1 = Total1 + Lecturas1[j];
  j = j + 1;

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

   if (j >= 10) {
    j = 0;
    Promedio1 = Total1 / 10;
    
    // Ajusta el valor para el primer servo (rango 0 a 179 grados).
    Val1 = map(Promedio1, 0, 1023, 0, 179);
    Servo3.write(Val1);

    // Muestra el valor en el monitor serial para propósitos de depuración.
    Serial.println(Val1, DEC);
  }

  LecturaPulsador = digitalRead(abre);
  if (LecturaPulsador == HIGH) {
    ValorPulsador = 90; // Si se presiona el pulsador, establece el ángulo del cuarto servo a 90 grados.
    Servo4.write(ValorPulsador);
    delay(500); // Pequeño retardo para evitar lecturas erráticas por rebotes del pulsador.
  }
  LecturaPulsador = digitalRead(cierra);
  if (LecturaPulsador == HIGH) {
    ValorPulsador = 0; // Si se presiona el pulsador, establece el ángulo del cuarto servo a 90 grados.
    Servo4.write(ValorPulsador);
    delay(500); // Pequeño retardo para evitar lecturas erráticas por rebotes del pulsador.
  }
}