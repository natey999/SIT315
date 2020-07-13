const byte ledPin = 8;
const byte interruptButtonPin = 3;
const byte interruptSensorPin = 2;
volatile byte LEDstate = LOW;
volatile byte motionState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptButtonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptButtonPin), blink1, FALLING);
  Serial.begin(9600);
  
  pinMode(interruptSensorPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptSensorPin), motionSensed, CHANGE);
}

void loop() {
  digitalWrite(ledPin, LOW);
  digitalWrite(interruptSensorPin,LOW);
}

void blink1() {
  digitalWrite(ledPin,HIGH);
  Serial.println("Button Press");
} 

void motionSensed(){
  digitalWrite(interruptSensorPin,HIGH);
  Serial.println("Motion Sensed");
}
