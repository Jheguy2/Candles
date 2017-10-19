int amountOfBlowingA0 = 0;
int amountOfBlowingA1 = 0;
int amountOfBlowingA2 = 0;
int amountOfBlowingA3 = 0;
boolean lightForA0 = false;
boolean lightForA1 = false;
boolean lightForA2 = false;
boolean lightForA3 = false;

void setup() {
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {

  Serial.println(amountOfBlowingA3);
  
  amountOfBlowingA0 = analogRead(A0);
  amountOfBlowingA1 = analogRead(A1);
  amountOfBlowingA2 = analogRead(A2);
  amountOfBlowingA3 = analogRead(A3);    
  
  if(amountOfBlowingA0 < 600){//check to see if a0 is being blown ;)
    lightForA0 = !lightForA0;
  }
  
  if(amountOfBlowingA1 < 600){//check to see if a1 is being blown ;)
    lightForA1 = !lightForA1;
  }

  if(amountOfBlowingA2 < 600){//check to see if a2 is being blown ;)
    lightForA2 = !lightForA2;
  }

  if(amountOfBlowingA3 < 600){//check to see if a3 is being blown ;)
    lightForA3 = !lightForA3;
  }

  if(lightForA0){
    digitalWrite(4,HIGH);
  }
  else{
    digitalWrite(4,LOW);
  }
  if(lightForA1){
    digitalWrite(5,HIGH);
  }
  else{
    digitalWrite(5,LOW);
  }
  if(lightForA2){
    digitalWrite(6,HIGH);
  }
  else{
    digitalWrite(6,LOW);
  }
  if(lightForA3){
    digitalWrite(7,HIGH);
  }
  else{
    digitalWrite(7,LOW);
  }
  delay(250);
}
