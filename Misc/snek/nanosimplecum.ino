// Defines pins numbers
const int stepPin = 4;
const int dirPin = 3; 
const int switchPin = 5;
int customDelay,customDelayMapped; // Defines variables
int switchState = 0;
 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(switchPin,INPUT_PULLUP);
  digitalWrite(dirPin,LOW); //Enables the motor to move in a particular direction
}


void loop() {
  customDelayMapped = speedUp(); // Gets custom delay values from the custom speedUp function
  //Makes pules with custom delay, depending on the Potentiometer, from which the speed of the motor depends
  digitalWrite(stepPin, HIGH);
  delay(customDelayMapped);
  digitalWrite(stepPin, LOW);
  delay(customDelayMapped);
}


// Function for reading the Potentiometer
int speedUp() {
  int customDelay = analogRead(A0); // Reads the potentiometer
  int newCustom = map(customDelay, 0, 1023, 1000,1); // Convrests the read values of the potentiometer from 0 to 1023
  return newCustom;  
}
