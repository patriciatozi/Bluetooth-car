const int motorA = 5; //velocidade motor A - de 0 a 255
const int motorB = 6; //velocidade motor B - de 0 a 255
const int dirA = 7; //direcao do motor A - HIGH ou LOW
const int dirB = 8; //direcao do motor B - HIGH ou LOW

long tempobotapet;
int botapet = 0; 
char dataIn = 'S';
const int a = 2;

void setup() {
  Serial.begin(9600);
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
}

void paraFrente() {
  digitalWrite(dirA, 0); 
  digitalWrite(dirB, 0);
  analogWrite(motorA, 127);
  analogWrite(motorB, 127);
}

void paraTras() {
  digitalWrite(dirA, 1); 
  digitalWrite(dirB, 1);
  analogWrite(motorA, 127);
  analogWrite(motorB, 127);
}

void paraDireita() {
  digitalWrite(dirA, 0);
  digitalWrite(dirB, 1);
  analogWrite(motorA, 110);
  analogWrite(motorB, 110);
}

void paraEsquerda() {
  digitalWrite(dirA, 1);
  digitalWrite(dirB, 0);
  analogWrite(motorA, 115);
  analogWrite(motorB, 115);
}

void loop() {
  if (Serial.available() > 0) {
    dataIn = Serial.read();

    switch (dataIn) {
      case 'W':
        botapet = 1;
        tempobotapet = millis();
        break;
      case 'F':
        botapet = 1;
        tempobotapet = millis();
        paraFrente();
        break;
      case 'B':
        botapet = 1;
        tempobotapet = millis();
        paraTras();
        break;
      case 'R':
        botapet = 1;
        tempobotapet = millis();
        paraDireita();
        break;
      case 'L':
        botapet = 1;
        tempobotapet = millis();
        paraEsquerda();
        break;
    }
  }

  if (millis() - tempobotapet > 200 && botapet == 1) {
    botapet = 0;
    digitalWrite(dirA, 1); 
    digitalWrite(dirB, 1);
    analogWrite(motorA, 0);
    analogWrite(motorB, 0);
  }
}
