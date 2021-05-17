char incomingByte; // for incoming serial data
String musictone = "";
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(13, INPUT);//leftbutton
  pinMode(12, INPUT);//rightbutton
  pinMode(A5, INPUT);//lightsensor
  pinMode(11, OUTPUT);//light
  pinMode(10, OUTPUT); //speaker
}
long previousmillis = 0;

void loop() {
  incomingByte = Serial.read();

  //Plays music
  if (incomingByte != 'X' && incomingByte >= 0) {
    musictone = musictone + incomingByte;
  }
  if (incomingByte == 'X') {
    if (musictone.toInt() != 0) {
      tone(10, musictone.toInt());
    }
    else {
      noTone(10);
    }
    musictone = "";
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

  
  //Refreshes the newest lightsensor data every second
  int lichtsterkte = analogRead(A5);
  unsigned long currentmillis = millis();
  if (currentmillis - previousmillis > 1000) {
    previousmillis = millis();
    Serial.flush();
    Serial.print(lichtsterkte);
  }
}
