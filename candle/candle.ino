boolean light1 = false;
boolean light2 = false;
boolean light3 = false;
boolean light4 = false;

long duration1;
long duration2;
long duration3;
long duration4;
int distance[4];

void getDistance(){
  
int add1[3];
int add2[3];
int add3[3];
int add4[3];

int states[4];

for(int x = 0; x < 3; x++){
  digitalWrite(1, LOW);
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  digitalWrite(10, LOW);
delayMicroseconds(2);
  digitalWrite(1, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH);
delayMicroseconds(10);
  digitalWrite(1, LOW);
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  digitalWrite(10, LOW);
duration1 = pulseIn(2, HIGH);
duration2 = pulseIn(5, HIGH);
duration3 = pulseIn(8, HIGH);
duration4 = pulseIn(11, HIGH);

add1[x] = duration1*0.034/2;
add2[x] = duration2*0.034/2;
add3[x] = duration3*0.034/2;
add4[x] = duration4*0.034/2;
}
distance[0] = min(min(add1[0],add1[1]),min(add1[1],add1[2]));
distance[1] = min(min(add2[0],add2[1]),min(add2[1],add2[2]));
distance[2] = min(min(add3[0],add3[1]),min(add3[1],add3[2]));
distance[3] = min(min(add4[0],add4[1]),min(add4[1],add4[2]));
}


void setup() {
pinMode(1, OUTPUT);
pinMode(4, OUTPUT);
pinMode(7, OUTPUT);
pinMode(10, OUTPUT);

pinMode(2, INPUT);
pinMode(5, INPUT);
pinMode(8, INPUT);
pinMode(11, INPUT);

pinMode(3, OUTPUT);
pinMode(6, OUTPUT);
pinMode(9, OUTPUT);
pinMode(12, OUTPUT);

Serial.begin(9600);
}
void loop() {

getDistance();

// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");
//Serial.println(distance);
if(distance[0] < 20){
  Serial.println("1 TRIGGERED");
  light1 = !light1;
  digitalWrite(3, light1);
  while(distance[0] < 20){
    getDistance();
  }
}
if(distance[1] < 20){
  Serial.println("2 TRIGGERED");

  light2 = !light2;
  digitalWrite(6, light2);
  while(distance[1] < 20){
    getDistance();
  }
}
if(distance[2] < 20){
  Serial.println("3 TRIGGERED");

  light3 = !light3;
  digitalWrite(9, light3);
  while(distance[2] < 20){
    getDistance();
  }
}
if(distance[3] < 20){
  Serial.println("4 TRIGGERED");

  light4 = !light4;
  digitalWrite(12, light4);
  while(distance[3] < 20){
    getDistance();
  }
}

}
