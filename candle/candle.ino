boolean light = false;
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;

int getDistance(){
int add[3];
for(int x = 0; x < 3; x++){
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
add[x] = duration*0.034/2;
}
return min(min(add[0],add[1]),min(add[1],add[2]));
}


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
pinMode(3, OUTPUT);
}
void loop() {

distance = getDistance();

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if(distance < 20){

  light = !light;
  digitalWrite(3, light);
  while(distance < 20){
    distance = getDistance();
  }
  Serial.println("OUT");
}
}
