const int sensorPines[] = {A1, A2, A3};
int velocidad = 70;
float Kp = 20;
int umbral = 800;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(sensorPines[i], INPUT);
  }
  
  pinMode(10, OUTPUT); // enA
  pinMode(6, OUTPUT);  // in1
  pinMode(5, OUTPUT);  // in2
  pinMode(2, OUTPUT);  // in3
  pinMode(3, OUTPUT);  // in4
  pinMode(11, OUTPUT); // enB
  pinMode(13, OUTPUT);
  delay(1000);
}

void loop() {
  int valoresSensores[3];
  for (int i = 0; i < 3; i++) {
    valoresSensores[i] = analogRead(sensorPines[i]);
  }
  digitalWrite(13, HIGH);
  // Determinar la dirección del giro
  if (valoresSensores[1] < umbral) {
    // Si el sensor A1 está sobre la línea, avanza recto
    int correccion = Kp * (valoresSensores[1] - umbral);
    int velocidad_izq = velocidad + correccion;
    int velocidad_der = velocidad - correccion;
    avanzarConVelocidad(velocidad_izq, velocidad_der);
  } else if (valoresSensores[0] < umbral) {
    girarDerecha(velocidad);
  } else if (valoresSensores[2] < umbral) {
    girarIzquierda(velocidad);
  } else {
    retroceder();
  }
}

// Avanzar hacia adelante con la velocidad dada
void adelante() {
  avanzarConVelocidad(velocidad, velocidad);
}

// Girar a la derecha con la velocidad dada
void girarDerecha(int velocidad) {
  avanzarConVelocidad(velocidad, 0);
}

// Girar a la izquierda con la velocidad dada
void girarIzquierda(int velocidad) {
  avanzarConVelocidad(0, velocidad);
}

// Detener el robot de manera suave
void detener() {
  for (int i = 1; i <= 7; i++) {
    digitalWrite(i, LOW);
  }
  analogWrite(10, 0);
  analogWrite(11, 0);
}

// Avanzar con velocidad específica para cada motor
void avanzarConVelocidad(int velocidad_izq, int velocidad_der) {
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  analogWrite(10, velocidad_izq);
  analogWrite(11, velocidad_der);
}

void retroceder() {
digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  analogWrite(10, velocidad);
  analogWrite(11, velocidad);
}

