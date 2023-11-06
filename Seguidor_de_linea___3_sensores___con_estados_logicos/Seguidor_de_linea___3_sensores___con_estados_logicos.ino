#define enA 10 // Habilitar1 Pin L293 enA

#define in1 5 // Motor1 Pin L293 in1

#define in2 6 // Motor1 Pin L293 in2

#define in3 4 // Motor2 Pin L293 in3

#define in4 3 // Motor2 Pin L293 in4

#define enB 11 // Habilitar2 Pin L293 enB

#define R_S A1 // Sensor IR Derecho

#define C_S A2 // Sensor del centro

#define L_S A3 // Sensor IR Izquierdo

int velocidad = 100;

int estado = 0; 

void setup() {

  pinMode(R_S, INPUT);

  pinMode(L_S, INPUT);

  pinMode(enA, OUTPUT);

  pinMode(in1, OUTPUT);

  pinMode(in2, OUTPUT);

  pinMode(in3, OUTPUT);

  pinMode(in4, OUTPUT);

  pinMode(enB, OUTPUT);

  delay(1000);

}

void loop() {

  if ((digitalRead(R_S) == 1) && (digitalRead(C_S) == 1) && (digitalRead(L_S) == 1) || estado == 1) {
    detener();
    estado = 1; 
    //adelante();
  } // Si el sensor derecho y el sensor izquierdo están en color blanco, llamará a la función adelante

  if ((digitalRead(R_S) == 1) && (digitalRead(C_S) == 0) && (digitalRead(L_S) == 0 || estado == 2)) {
    girarIzquierda(10);
    estado = 2; 
    //girarDerecha();
  } // Si el sensor derecho está en negro y el sensor izquierdo está en blanco, llamará a la función girar a la derecha

  if ((digitalRead(R_S) == 1) && (digitalRead(C_S) == 1) && (digitalRead(L_S) == 0) || estado == 3) {
    girarIzquierda(20);
    estado = 3;
    //girarDerecha();
  } 

  if ((digitalRead(R_S) == 0) && (digitalRead(C_S) == 0) && (digitalRead(L_S) == 1) || estado == 4) {
    girarDerecha(10);
    estado = 4; 
    //girarIzquierda();
  } // Si el sensor derecho está en blanco y el sensor izquierdo está en negro, llamará a la función girar a la izquierda


  if ((digitalRead(R_S) == 0) && (digitalRead(C_S) == 1) && (digitalRead(L_S) == 1) || estado == 5) {
    girarDerecha(20);
    estado = 5; 
    //girarIzquierda();
  } 
  if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1) && (digitalRead(C_S) == 0) || estado == 6) {
    adelante();
    estado = 6; 
    //detener();
  } // Si el sensor derecho y el sensor izquierdo están en color negro, llamará a la función detener

}

void adelante() { // adelante

  digitalWrite(in1, HIGH); // Pin del motor derecho hacia adelante

  digitalWrite(in2, LOW); // Pin del motor derecho hacia atrás

  digitalWrite(in3, LOW); // Pin del motor izquierdo hacia atrás

  digitalWrite(in4, HIGH); // Pin del motor izquierdo hacia adelante

  analogWrite(enA, velocidad);

  analogWrite(enB, velocidad);
}

void girarDerecha(int factor) { // girar a la derecha

  digitalWrite(in1, LOW); // Pin del motor derecho hacia adelante

  digitalWrite(in2, HIGH); // Pin del motor derecho hacia atrás

  digitalWrite(in3, LOW); // Pin del motor izquierdo hacia atrás

  digitalWrite(in4, HIGH); // Pin del motor izquierdo hacia adelante
  
  analogWrite(enA, velocidad - factor);

  analogWrite(enB, velocidad - factor);

}

void girarIzquierda(int factor) { // girar a la izquierda

  digitalWrite(in1, HIGH); // Pin del motor derecho hacia adelante

  digitalWrite(in2, LOW); // Pin del motor derecho hacia atrás

  digitalWrite(in3, HIGH); // Pin del motor izquierdo hacia atrás

  digitalWrite(in4, LOW); // Pin del motor izquierdo hacia adelante

  analogWrite(enA, velocidad - factor);

  analogWrite(enB, velocidad - factor);

}

void detener() { // detener

  digitalWrite(in1, LOW); // Pin del motor derecho hacia adelante

  digitalWrite(in2, LOW); // Pin del motor derecho hacia atrás

  digitalWrite(in3, LOW); // Pin del motor izquierdo hacia atrás

  digitalWrite(in4, LOW); // Pin del motor izquierdo hacia adelante

  analogWrite(enA, velocidad);

  analogWrite(enB, velocidad);
}


