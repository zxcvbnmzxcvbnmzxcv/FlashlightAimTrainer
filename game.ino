const int ledCathode = 9; 
const int ledAnode = 10;   

void setup() {
  Serial.begin(9600);
}

int readLightViaDischarge() {
  pinMode(ledAnode, OUTPUT);
  pinMode(ledCathode, OUTPUT);
  digitalWrite(ledCathode, HIGH);
  digitalWrite(ledAnode, LOW);
  delayMicroseconds(100); 


  pinMode(ledAnode, INPUT);   
  digitalWrite(ledCathode, LOW); 

  unsigned long count = 0;
  while (digitalRead(ledAnode) == HIGH) {
    count++;
    if (count > 30000) break; 
  }
  return count;
}

void loop() {
  int reading = readLightViaDischarge();
  Serial.println(reading);
  delay(200);
}