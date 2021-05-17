char incomingByte; // for incoming serial data
String toon = "";

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(A5, INPUT);
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
}

long previousmillis = 0;

void loop() {
  incomingByte = Serial.read();

  if (incomingByte != 'X' && incomingByte >= 0) {
    toon = toon + incomingByte;
  }
  
  if (incomingByte == 'X') {
    if(toon.toInt()!=0){
    tone(10, toon.toInt());}
    else{noTone(10);}
    toon = "";
  }

  if(incomingByte=='W'){
    Serial.print(analogRead(A5));
    digitalWrite(11,HIGH);
  }

  //controller
  if (digitalRead(13) == HIGH && digitalRead(12) == HIGH) {
    Serial.print("P");
  }
  else if (digitalRead(13) == HIGH) {
    Serial.print("A");
  }
  else if (digitalRead(12) == HIGH) {
    Serial.print("D");
  }

//  int lichtsterkte = analogRead(A5);
//  //verstuurlichtsterkte
//  unsigned long currentmillis = millis();
//  if (currentmillis - previousmillis > 6000) {
//    previousmillis = millis();
//    Serial.print(lichtsterkte);
//  }
}
