int duracionIzquierda, duracionDerecha, distanciaFrontal, tic, pinTrigFrontal = 6, pinEchoFrontal = 7;
int pinTrigIzquierda = 8, pinEchoIzquierda = 9, pinTrigDerecha = 10, pinEchoDerecha = 11;
int estado = 0;

// Función para mover el robot hacia adelante
void adelante() {
  digitalWrite(5, LOW);   // Apaga el motor derecho
  digitalWrite(4, HIGH);  // Enciende el motor izquierdo
  digitalWrite(3, LOW);   // Apaga el motor trasero
  digitalWrite(2, HIGH);  // Enciende el motor delantero
}

// Función para girar el robot a la izquierda
void izquierda() {
  digitalWrite(5, LOW);   // Apaga el motor derecho
  digitalWrite(4, HIGH);  // Enciende el motor izquierdo
  digitalWrite(3, HIGH);  // Enciende el motor trasero
  digitalWrite(2, LOW);   // Apaga el motor delantero
}

// Función para girar el robot a la derecha
void derecha() {
  digitalWrite(5, HIGH);  // Enciende el motor derecho
  digitalWrite(4, LOW);   // Apaga el motor izquierdo
  digitalWrite(3, LOW);   // Apaga el motor trasero
  digitalWrite(2, HIGH);  // Enciende el motor delantero
}

// Función para detener el robot
void detener() {
  digitalWrite(5, LOW);   // Apaga el motor derecho
  digitalWrite(4, LOW);   // Apaga el motor izquierdo
  digitalWrite(3, LOW);   // Apaga el motor trasero
  digitalWrite(2, LOW);   // Apaga el motor delantero
}

// Función para encender los LEDs
void encenderLED() {
  digitalWrite(12, HIGH); // Enciende el primer LED
  digitalWrite(13, HIGH); // Enciende el segundo LED
}

// Función para apagar los LEDs
void apagarLED() {
  digitalWrite(12, LOW);  // Apaga el primer LED
  digitalWrite(13, LOW);  // Apaga el segundo LED
}

// Función para medir la distancia utilizando el sensor ultrasónico frontal
void medirDistanciaFrontal() {
  digitalWrite(pinTrigFrontal, LOW);    // Asegura que el pin de trig se encuentra en LOW
  delayMicroseconds(5);                // Espera 5 microsegundos
  digitalWrite(pinTrigFrontal, HIGH);   // Envía un pulso HIGH al pin de trig
  delayMicroseconds(15);               // Espera 15 microsegundos
  digitalWrite(pinTrigFrontal, LOW);    // Termina el pulso LOW
  distanciaFrontal = pulseIn(pinEchoFrontal, HIGH); // Lee la duración del pulso en el pin de echo
  distanciaFrontal = distanciaFrontal / 58; // Calcula la distancia en centímetros
}

// Función para medir la distancia utilizando el sensor ultrasónico izquierdo
void medirDistanciaIzquierda() {
  digitalWrite(pinTrigIzquierda, LOW);  // Asegura que el pin de trig se encuentra en LOW
  delayMicroseconds(5);                // Espera 5 microsegundos
  digitalWrite(pinTrigIzquierda, HIGH); // Envía un pulso HIGH al pin de trig
  delayMicroseconds(15);               // Espera 15 microsegundos
  digitalWrite(pinTrigIzquierda, LOW);  // Termina el pulso LOW
  duracionIzquierda = pulseIn(pinEchoIzquierda, HIGH); // Lee la duración del pulso en el pin de echo
  duracionIzquierda = duracionIzquierda / 58; // Calcula la distancia en centímetros
}

// Función para medir la distancia utilizando el sensor ultrasónico derecho
void medirDistanciaDerecha() {
  digitalWrite(pinTrigDerecha, LOW);    // Asegura que el pin de trig se encuentra en LOW
  delayMicroseconds(5);                // Espera 5 microsegundos
  digitalWrite(pinTrigDerecha, HIGH);   // Envía un pulso HIGH al pin de trig
  delayMicroseconds(15);               // Espera 15 microsegundos
  digitalWrite(pinTrigDerecha, LOW);    // Termina el pulso LOW
  duracionDerecha = pulseIn(pinEchoDerecha, HIGH); // Lee la duración del pulso en el pin de echo
  duracionDerecha = duracionDerecha / 58; // Calcula la distancia en centímetros
}

void setup() {
  pinMode(2, OUTPUT);    // Configura el pin 2 como salida
  pinMode(3, OUTPUT);    // Configura el pin 3 como salida
  pinMode(4, OUTPUT);    // Configura el pin 4 como salida
  pinMode(5, OUTPUT);    // Configura el pin 5 como salida
  pinMode(8, OUTPUT);    // Configura el pin 8 como salida (pinTrigIzquierda)
  pinMode(9, INPUT);     // Configura el pin 9 como entrada (pinEchoIzquierda)
  pinMode(10, OUTPUT);   // Configura el pin 10 como salida (pinTrigDerecha)
  pinMode(11, INPUT);    // Configura el pin 11 como entrada (pinEchoDerecha)
  pinMode(6, OUTPUT);    // Configura el pin 6 como salida (pinTrigFrontal)
  pinMode(7, INPUT);     // Configura el pin 7 como entrada (pinEchoFrontal)
  pinMode(12, OUTPUT);   // Configura el pin 12 como salida (LED)
  pinMode(13, OUTPUT);   // Configura el pin 13 como salida (LED)
  encenderLED();        // Enciende los LEDs
  delay(5000);          // Espera 5 segundos
}

void loop() {
  medirDistanciaFrontal(); // Mide la distancia con el sensor ultrasónico frontal
  medirDistanciaIzquierda(); // Mide la distancia con el sensor ultrasónico izquierdo
  medirDistanciaDerecha(); // Mide la distancia con el sensor ultrasónico derecho

  // Decide la acción del robot basado en las distancias medidas
  if (distanciaFrontal < 10) {  // Si hay un obstáculo cercano al frente
    if (duracionIzquierda < duracionDerecha) { // Si el obstáculo está más cerca a la izquierda
      derecha();   // Gira a la derecha
    } else {        // Si el obstáculo está más cerca a la derecha
      izquierda();  // Gira a la izquierda
    }
    detener();      // Detiene el robot
    encenderLED(); // Enciende los LEDs
  } else {
    adelante();    // Avanza hacia adelante
    apagarLED();  // Apaga los LEDs
  }

  delay(300); // Espera 300 milisegundos
}
