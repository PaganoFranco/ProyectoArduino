int duracion, sm, tic, pinTrig = 6, pinEcho = 7, estado = 0;

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
  digitalWrite(9, HIGH);  // Enciende el primer LED
  digitalWrite(8, HIGH);  // Enciende el segundo LED
}

// Función para apagar los LEDs
void apagarLED() {
  digitalWrite(9, LOW);   // Apaga el primer LED
  digitalWrite(8, LOW);   // Apaga el segundo LED
}

// Función para medir la distancia utilizando el sensor ultrasónico
void medirDistancia() {
  digitalWrite(pinTrig, LOW);      // Asegura que el pin de trig se encuentra en LOW
  delayMicroseconds(5);           // Espera 5 microsegundos
  digitalWrite(pinTrig, HIGH);     // Envía un pulso HIGH al pin de trig
  delayMicroseconds(15);          // Espera 15 microsegundos
  digitalWrite(pinTrig, LOW);      // Termina el pulso LOW
  duracion = pulseIn(pinEcho, HIGH); // Lee la duración del pulso en el pin de echo
  sm = duracion / 58;             // Calcula la distancia en centímetros
}

void setup() {
  // Serial.begin(9600);  // Inicializa la comunicación serial (comentado)
  pinMode(2, OUTPUT);   // Configura el pin 2 como salida
  pinMode(3, OUTPUT);   // Configura el pin 3 como salida
  pinMode(4, OUTPUT);   // Configura el pin 4 como salida
  pinMode(5, OUTPUT);   // Configura el pin 5 como salida
  pinMode(8, OUTPUT);   // Configura el pin 8 como salida
  pinMode(9, OUTPUT);   // Configura el pin 9 como salida
  pinMode(pinTrig, OUTPUT); // Configura el pin de trig como salida
  pinMode(pinEcho, INPUT);  // Configura el pin de echo como entrada
  encenderLED();           // Enciende los LEDs
  delay(5000);            // Espera 5 segundos
}

void loop() {
  medirDistancia();      // Mide la distancia con el sensor ultrasónico
  // Serial.println(sm); // Imprime la distancia medida (comentado)
  if (sm > 1 && sm < 40) { // Si la distancia está en el rango deseado
    tic ++;               // Incrementa el contador tic
  } else {
    tic = 0;              // Reinicia el contador tic si la distancia está fuera del rango
  }
  if (tic >= 2) {        // Si el contador tic es mayor o igual a 2
    if (estado == 0 && millis() > 5050) { // Si el estado es 0 y han pasado más de 5050 milisegundos
      derecha();        // Gira a la derecha
      delay(10);        // Espera 10 milisegundos
    }
    adelante();        // Mueve el robot hacia adelante
    encenderLED();     // Enciende los LEDs
    delay(300);        // Espera 300 milisegundos
    estado = 1;        // Cambia el estado a 1
  } else {
    izquierda();       // Gira a la izquierda
    apagarLED();       // Apaga los LEDs
  }
}

