#define trigPin 3 //sensor 1
#define echoPin 2 //sensor 1
#define trigPin2 7 //sensor 2
#define echoPin2 6 //sensor 2
#define trigPin3 5 //sensor 3
#define echoPin3 4 //sensor 3


int motorIzquierdoPin1 = 11;
int motorIzquierdoPin2 = 10;
int motorDerechoPin1 = 13;
int motorDerechoPin2 = 12;

float distance;   // Variable global para la distancia del primer sensor ultrasónico
float duration;   // Variable global para la duración del pulso del primer sensor ultrasónico
float distance2;  // Variable global para la distancia del segundo sensor ultrasónico
float duration2;   // Variable global para la duración del pulso del segundo sensor ultrasónico
float distance3;  // Variable global para la distancia del tercer sensor ultrasónico
float duration3;  // Variable global para la duración del pulso del tercer sensor ultrasónico

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  pinMode(motorIzquierdoPin1, OUTPUT);
  pinMode(motorIzquierdoPin2, OUTPUT);
  pinMode(motorDerechoPin1, OUTPUT);
  pinMode(motorDerechoPin2, OUTPUT);

  Serial.begin(9600);
  //delay(5000);
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
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    duration2 = pulseIn(echoPin2, HIGH);
    distance2 = (duration2 / 2) / 29.1;
    
    // Medir la distancia con el Tercer sensor ultrasónico
    digitalWrite(trigPin3, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin3, LOW);
    duration3 = pulseIn(echoPin3, HIGH);
    distance3 = (duration3 / 2) / 29.1;
    
    // Para verificar si andan los sensores
    //Serial.println(distance3);

    if (distance < 25) {
      // Si el sensor 1 detecta el robot avanza
      digitalWrite(motorIzquierdoPin1, HIGH);
      digitalWrite(motorIzquierdoPin2, LOW);
      digitalWrite(motorDerechoPin1, HIGH);
      digitalWrite(motorDerechoPin2, LOW);
      delay(100);
    } else if(distance2 < 25){
      digitalWrite(motorIzquierdoPin1, HIGH);
      digitalWrite(motorIzquierdoPin2, LOW);
      digitalWrite(motorDerechoPin1, LOW);
      digitalWrite(motorDerechoPin2, HIGH); 
    } else if(distance3 < 25){
      digitalWrite(motorIzquierdoPin1, LOW);
      digitalWrite(motorIzquierdoPin2, HIGH);
      digitalWrite(motorDerechoPin1, HIGH);
      digitalWrite(motorDerechoPin2, LOW);
    }else {
      digitalWrite(motorIzquierdoPin1, LOW);
      digitalWrite(motorIzquierdoPin2, HIGH);
      digitalWrite(motorDerechoPin1, HIGH);
      digitalWrite(motorDerechoPin2, LOW);
    }


    delay(10);
  }

