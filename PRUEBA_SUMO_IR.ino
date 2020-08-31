int trigA = 2;
int echoA = 3;
int duracionA;
int distanciaA;


void AVANSAR() {
  digitalWrite(9,HIGH);
  digitalWrite(8,LOW);
  analogWrite(5,255);
  digitalWrite(7,HIGH);
  digitalWrite(4,LOW);
  analogWrite(6,255);
}


void RETROCEDER() {
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  analogWrite(5,110);
  digitalWrite(7,LOW);
  digitalWrite(4,HIGH);
  analogWrite(6,110);
  delay(1300);
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  analogWrite(5,130);
  digitalWrite(7,HIGH);
  digitalWrite(4,LOW);
  analogWrite(6,130);
  delay(500);
  
  
}

void BUSCAR() {
  
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  analogWrite(5,130);
  digitalWrite(7,HIGH);
  digitalWrite(4,LOW);
  analogWrite(6,130);
}

void setup()
{
  pinMode(2, OUTPUT);
pinMode(3, INPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
pinMode(5, OUTPUT);
pinMode(7, OUTPUT);
pinMode(4, OUTPUT);
pinMode(6, OUTPUT);
pinMode(11, INPUT);

}

void loop()
{
  
  digitalWrite(trigA, HIGH);
  delay(1);
  digitalWrite(trigA, LOW);
  duracionA = pulseIn(echoA, HIGH);
  distanciaA = duracionA / 58.2;

 
    
    if (((distanciaA < 40) && (distanciaA > 0))) {
  
      AVANSAR();
    }
    
    else if (((distanciaA > 40 ) && (distanciaA < 400))) {
      BUSCAR();
    }

    if (digitalRead(11)==HIGH) {
      RETROCEDER();
    }

    if ((distanciaA < 10) && (digitalRead(11)==HIGH)){
      RETROCEDER();
    }
 }
