boolean blow = false;
boolean light = false;
boolean blowstill = false;
void setup() {
  pinMode(2, OUTPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {


blow = digitalRead(12);

if(blow){
  light = !light;
}

if(light){

digitalWrite(2, HIGH);
  delay(500);

}else{
digitalWrite(2, LOW);
    delay(500);
 
}
}







