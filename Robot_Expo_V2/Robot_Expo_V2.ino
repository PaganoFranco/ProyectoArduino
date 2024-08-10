#define trigPin 2  //sensor 1
#define echoPin 7  //sensor 1
#define trigPin2 8 //sensor 2
#define echoPin2 4 //sensor 2
#define trigPin3 10 //sensor 3
#define echoPin3 11 //sensor 3
#define trigPin4 12 //sensor 4
#define echoPin4 13 //sensor 4

int motorIzquierdoPin1 = 3;
int motorIzquierdoPin2 = 5;
int motorDerechoPin1 = 6;
int motorDerechoPin2 = 9;
int Stop = A0;
int Stop2 = A1;
int giroIz = A2;
int giroDr = A3;
int velocidad = 120;
float cuidado = 15;

float distance;   // Variable global para la distancia del primer sensor ultrasónico
float duration;   // Variable global para la duración del pulso del primer sensor ultrasónico
float distance2;  // Variable global para la distancia del segundo sensor ultrasónico
float duration2;  // Variable global para la duración del pulso del segundo sensor ultrasónico
float distance3;  // Variable global para la distancia del tercer sensor ultrasónico
float duration3;  // Variable global para la duración del pulso del tercer sensor ultrasónico
float distance4;  // Variable global para la distancia del cuarto sensor ultrasónico
float duration4;  // Variable global para la duración del pulso del cuarto sensor ultrasónico

float medirDistancia(int trig, int echo) {
  
   digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = (duration / 2) / 29.1;
    return distance; // Devolver la distancia medida
}

void controlarMotores(int izqPin1, int izqPin2, int derPin1, int derPin2, int velocidad) {
  digitalWrite(izqPin1, velocidad);  // Activar el pin correspondiente al motor izquierdo
  digitalWrite(izqPin2, LOW);   // Desactivar el otro pin del motor izquierdo

  digitalWrite(derPin1, velocidad);  // Activar el pin correspondiente al motor derecho
  digitalWrite(derPin2, LOW);   // Desactivar el otro pin del motor derecho

}

void accionesMovimiento(float distancia1, float distancia2, float distancia3, float distancia4, int velocidad, float cuidado) {
  if ((distancia1 < cuidado) && (distancia2 < cuidado)) {
    // Lógica para mover el robot hacia adelante o realizar una acción específica para evitar obstáculos
    controlarMotores(motorIzquierdoPin2, motorIzquierdoPin1, motorDerechoPin2, motorDerechoPin1, velocidad);
    // Otras acciones específicas según la situación
  } else if ((distancia3 < cuidado - 5) || (distancia1 < cuidado)) {
    // Lógica para realizar una acción específica cuando se detecta un obstáculo en el lado izquierdo
    controlarMotores(motorIzquierdoPin1, motorIzquierdoPin2, motorDerechoPin2, motorDerechoPin1, velocidad);
    
  } else if ((distancia4 < cuidado - 5) || (distancia2 < cuidado)) {
    // Lógica para realizar una acción específica cuando se detecta un obstáculo en el lado derecho
    controlarMotores(motorIzquierdoPin2, motorIzquierdoPin1, motorDerechoPin1, motorDerechoPin2, velocidad);
    
  } else {
    // Lógica para seguir avanzando o realizar una acción predeterminada
    controlarMotores(motorIzquierdoPin1, motorIzquierdoPin2, motorDerechoPin2, motorDerechoPin1, velocidad);
  }
}


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

  pinMode(motorIzquierdoPin1, OUTPUT);
  pinMode(motorIzquierdoPin2, OUTPUT);
  pinMode(motorDerechoPin1, OUTPUT);
  pinMode(motorDerechoPin2, OUTPUT);
  pinMode(Stop, OUTPUT);
  pinMode(Stop2, OUTPUT);
  pinMode(giroIz, OUTPUT);
  pinMode(giroDr, OUTPUT);
  Serial.begin(9600);
  delay(10);

   for (int i = 0; i < 3; i++) { // Titilar la luz tres veces
    digitalWrite(Stop, HIGH);
    digitalWrite(Stop2, HIGH);
    delay(1000);
    digitalWrite(Stop, LOW);
    digitalWrite(Stop2, LOW);
    delay(1000);
  }

}

void loop() {
   // Lógica principal del programa
  // Medir distancias con los sensores ultrasónicos
  float distancia = medirDistancia(trigPin, echoPin);
  float distancia2 = medirDistancia(trigPin2, echoPin2);
  float distancia3 = medirDistancia(trigPin3, echoPin3);
  float distancia4 = medirDistancia(trigPin4, echoPin4);

  // Realizar acciones de movimiento basadas en las lecturas de los sensores
  accionesMovimiento(distancia, distancia2, distancia3, distancia4, velocidad, cuidado);

  delay(10); // Pequeño retraso entre iteraciones del bucle principal
}
