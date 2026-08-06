const int ledPins[] = {A0, A1, A2, A3, A4, A5};
const int numLeds = 6;

// fine-tune
const int hitThresholds[] = {
  520, // A0 - Blue (green black wires) 475
  370, // A1 - Red  359 (brown yellow wires)
  475, // A2 - White (white blue wires)
  485, // A3 - White (Orange black wires)
  475, // A4 - Blue (yellow black wires) 475
  250  // A5 - red fine-tuned for ambient light. 250 (white red wires)
};

const unsigned long onTime = 8000;   
const unsigned long senseTime = 500;

bool isHitOut[numLeds] = {false, false, false, false, false, false}; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  for (int i = 0; i < numLeds; i++) {
    if (!isHitOut[i]) {
      pinMode(ledPins[i], OUTPUT);
      digitalWrite(ledPins[i], HIGH);
    }
  }
  delayMicroseconds(onTime);

  
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], INPUT); 
    delayMicroseconds(senseTime);
    int reading = analogRead(ledPins[i]);

    if (reading > hitThresholds[i] && !isHitOut[i]) {
      isHitOut[i] = true;
      Serial.print("HIT on LED ");
      Serial.println(i);
    }
  }
}