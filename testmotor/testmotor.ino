// Controlador de motor DC
//Motor A
#define rightMotor1 5 //pin driver1
#define rightMotor2  6 //pin driver2
#define rightMotorPWM 10 //pin pwmA

//Motor B 
#define leftMotor1 2 //pin driver3
#define leftMotor2 3 //pin driver4
#define leftMotorPWM 11 //pin pwmB

#define MaxSpeed 150     // Velocidad máxima del robot
#define BaseSpeed 150    // Esta es la velocidad a la que los motores deben girar cuando el robot está perfectamente en la línea

//int pot1 = A0; //Potenciometro 
int SetSpeed = 150;

void setup() {
  Serial.begin(9600);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);
  SetSpeed = 125;  // Velocidad inicial
}

void loop() {
  //Establece la velocidad a través de un potenciómetro (comentado)
  //SetSpeed = analogRead(pot1);
  //SetSpeed = map(SetSpeed, 0, 1023, 0, 255);

  // Control de movimiento de los motores
  motorKiri();
  delay(500);
  /*
  motorKanan();
  delay(500);
  
  motorKiri();
  delay(500);
  motorMaju();
  delay(500);
  motorMundur();
  delay(500);
  */
  motorStop();
  delay(1000);
  
}

void motorStop() {
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightMotorPWM, 0);
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftMotorPWM, 0);
}

void motorKanan() {
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightMotorPWM, 100);
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  analogWrite(leftMotorPWM, 100);
}

void motorKiri() {
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
  analogWrite(rightMotorPWM, 70);
  /*
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftMotorPWM, 70);
  */
}

void motorMaju() {
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightMotorPWM, SetSpeed);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftMotorPWM, SetSpeed);
}

void motorMundur() {
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
  analogWrite(rightMotorPWM, SetSpeed);
  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  analogWrite(leftMotorPWM, SetSpeed);
}
