#define trigPin 2 //sensor 1
#define echoPin 7 //sensor 1
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


  // Luego, entra en el bucle principal
    // Medir la distancia con el primer ultrasónico
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration / 2) / 29.1;

    // Medir la distancia con el segundo sensor ultrasónico
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin2, LOW);
    duration2 = pulseIn(echoPin2, HIGH);
    distance2 = (duration2 / 2) / 29.1;

    // Medir la distancia con el tercer sensor ultrasónico
    digitalWrite(trigPin3, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin3, LOW);
    duration3 = pulseIn(echoPin3, HIGH);
    distance3 = (duration3 / 2) / 29.1;

    // Medir la distancia con el cuarto sensor ultrasónico
    digitalWrite(trigPin4, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin4, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin4, LOW);
    duration4 = pulseIn(echoPin4, HIGH);
    distance4 = (duration4 / 2) / 29.1;

 

    if((distance < cuidado && distance2 < cuidado)){

      digitalWrite(motorIzquierdoPin1, LOW);
      digitalWrite(motorIzquierdoPin2, velocidad);
      digitalWrite(motorDerechoPin1, LOW);
      digitalWrite(motorDerechoPin2, velocidad); 

      digitalWrite(Stop, HIGH);
      digitalWrite(Stop2, HIGH);
      delay(200);
      digitalWrite(Stop, LOW);
      digitalWrite(Stop2, LOW);
      delay(200);

      digitalWrite(motorIzquierdoPin1, LOW);
      digitalWrite(motorIzquierdoPin2, velocidad);
      digitalWrite(motorDerechoPin1, velocidad);
      digitalWrite(motorDerechoPin2, LOW); 
      delay(200);

    }else if((distance3 < (cuidado-5) && distance4 < (cuidado-5)) ){
      digitalWrite(motorIzquierdoPin1, velocidad);
      digitalWrite(motorIzquierdoPin2, LOW);
      digitalWrite(motorDerechoPin1, velocidad);
      digitalWrite(motorDerechoPin2, LOW); 
      digitalWrite(Stop, LOW);
      digitalWrite(Stop2, LOW);
    } else if (distance4 < (cuidado-5)||  distance2 < cuidado){
      
      digitalWrite(motorIzquierdoPin1, LOW);
      digitalWrite(motorIzquierdoPin2, velocidad);
      digitalWrite(motorDerechoPin1, velocidad);
      digitalWrite(motorDerechoPin2, LOW); 
      digitalWrite(Stop, LOW);
      digitalWrite(Stop2, LOW);

      digitalWrite(giroIz, HIGH);
      delay(200);
      digitalWrite(giroIz, LOW);
      delay(200);
    }else if(distance3 < (cuidado-5) || distance < cuidado ){
      
      digitalWrite(motorIzquierdoPin1, velocidad);
      digitalWrite(motorIzquierdoPin2, LOW);
      digitalWrite(motorDerechoPin1, LOW);
      digitalWrite(motorDerechoPin2, velocidad); 
      digitalWrite(Stop, LOW);
      digitalWrite(Stop2, LOW);

      digitalWrite(giroDr, HIGH);
      delay(200);
      digitalWrite(giroDr, LOW);
      delay(200);
    } else{ 
      digitalWrite(motorIzquierdoPin1, velocidad);
      digitalWrite(motorIzquierdoPin2, LOW);
      digitalWrite(motorDerechoPin1, velocidad);
      digitalWrite(motorDerechoPin2, LOW); 
      digitalWrite(Stop, LOW);
      digitalWrite(Stop2, LOW);
    } 

    delay(10);
  }
