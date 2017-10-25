boolean light[4];
long duration[4];
int distance[4];
String answer = "";

void getDistance() {

  int add1[3];
  int add2[3];
  int add3[3];
  int add4[3];

  int states[4];

  for (int x = 0; x < 3; x++) {
    digitalWrite(A1, LOW);
    delayMicroseconds(2);
    digitalWrite(A1, HIGH);
    delayMicroseconds(10);
    digitalWrite(A1, LOW);
    duration[0] = pulseIn(2, HIGH);
    
    digitalWrite(4, LOW);
    delayMicroseconds(2);
    digitalWrite(4, HIGH);
    delayMicroseconds(10);
    digitalWrite(4, LOW);
    delayMicroseconds(2);
    duration[1] = pulseIn(5, HIGH);
    
    digitalWrite(7, LOW);
    delayMicroseconds(2);
    digitalWrite(7, HIGH);
    delayMicroseconds(10);
    digitalWrite(7, LOW);
    duration[2] = pulseIn(8, HIGH);

    
    digitalWrite(10, LOW);
    delayMicroseconds(2);
    digitalWrite(10, HIGH);
    delayMicroseconds(10);
    digitalWrite(10, LOW);
    duration[3] = pulseIn(11, HIGH);
  

    add1[x] = duration[0] * 0.034 / 2;
    add2[x] = duration[1] * 0.034 / 2;
    add3[x] = duration[2] * 0.034 / 2;
    add4[x] = duration[3] * 0.034 / 2;
  }
  distance[0] = min(min(add1[0], add1[1]), min(add1[1], add1[2]));
  distance[1] = min(min(add2[0], add2[1]), min(add2[1], add2[2]));
  distance[2] = min(min(add3[0], add3[1]), min(add3[1], add3[2]));
  distance[3] = min(min(add4[0], add4[1]), min(add4[1], add4[2]));
  //for(int temp = 0; temp < 4; temp++){
  //  Serial.println(distance[temp]);
  //}
}


void setup() {
  for (int tempAtBeginning = 0; tempAtBeginning < 4; tempAtBeginning++) {
    light[tempAtBeginning] = false;
  }

  pinMode(A1, OUTPUT);
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

  pinMode(A2, OUTPUT);

  Serial.begin(9600);
}
void loop() {

  getDistance();

  // Prints the distance on the Serial Monitor
  //Serial.print("Distance: ");
  //Serial.println(distance);

  if (light[0] == false && light[1] == false && light[2] == false && light[3] == false) {
    answer = "";
  }

  for (int x = 0; x < 4; x++) {
    if (distance[x] < 20) {
      Serial.println((x + 1) + " TRIGGERED");
      light[x] = !light[x];
      if (light[x] == true) {
        answer += x;
      }
      digitalWrite((x + 1) * 3, light[x]);
      while (distance[x] < 20) {
        getDistance();
      }
    }
  }

  if (answer == "0123") {
    digitalWrite(A2, HIGH);
    delay(1000);
    digitalWrite(A2, LOW);
    answer = "";
    Serial.println("YOU WIN YOU FUCK");
  }
}
