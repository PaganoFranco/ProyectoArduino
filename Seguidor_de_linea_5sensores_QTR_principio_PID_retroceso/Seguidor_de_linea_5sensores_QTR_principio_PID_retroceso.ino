const int sensorPines[] = {A0, A1, A2, A3, A4};
int velocidad = 130;
float Kp = 30;
int umbral = 700;

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(sensorPines[i], INPUT);
  }
  
  pinMode(5, OUTPUT); // enA
  pinMode(6, OUTPUT);  // in1
  pinMode(7, OUTPUT);  // in2
  pinMode(2, OUTPUT);  // in3
  pinMode(4, OUTPUT);  // in4
  pinMode(3, OUTPUT); // enB
  pinMode(13, OUTPUT);
  delay(1000);
}

void loop() {
  int valoresSensores[5];
  for (int i = 0; i < 5; i++) {
    valoresSensores[i] = analogRead(sensorPines[i]);
  }
  digitalWrite(13, HIGH);
  if (valoresSensores[0] > umbral && valoresSensores[4] > umbral) {
    adelante();
  } else if (valoresSensores[0] > umbral) {
    girarIzquierda(velocidad);
  } else if (valoresSensores[4] > umbral) {
    girarDerecha(velocidad);
  } else if (valoresSensores[1] < umbral) {
    girarIzquierda(velocidad);
  } else if (valoresSensores[3] < umbral) {
    girarDerecha(velocidad);
  } else if (valoresSensores[2] < umbral) {
    int correccion = Kp * (valoresSensores[2] - umbral);
    int velocidad_izq = velocidad + correccion;
    int velocidad_der = velocidad - correccion;
    avanzarConVelocidad(velocidad_izq, velocidad_der);
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
  for (int i = 1; i <= 4; i++) {
    digitalWrite(i, LOW);
  }
  analogWrite(5, 0);
  analogWrite(3, 0);
}

// Avanzar con velocidad específica para cada motor
void avanzarConVelocidad(int velocidad_izq, int velocidad_der) {
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  analogWrite(5, velocidad_izq);
  analogWrite(3, velocidad_der);
}

void retroceder() {
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  analogWrite(5, 120);
  analogWrite(3, 120);
}


