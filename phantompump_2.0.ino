#include <IRremote.h>

const int solenoidValvePin1 = 2;
const int solenoidValvePin2 = 3;
const int solenoidValvePin3 = 4;
const int solenoidValvePin4 = 5;
const int vacuumPumpPin1 = 6;
const int vacuumPumpPin2 = 7;
const int IRreceiverPin = 9;

IRrecv irrecv(IRreceiverPin);
decode_results results;

void setup() {
  pinMode(solenoidValvePin1, OUTPUT);
  pinMode(solenoidValvePin2, OUTPUT);
  pinMode(solenoidValvePin3, OUTPUT);
  pinMode(solenoidValvePin4, OUTPUT);
  pinMode(vacuumPumpPin1, OUTPUT);
  pinMode(vacuumPumpPin2, OUTPUT);
  irrecv.enableIRIn();
}

void loop() {

  valveState = !valveState;+

  if (valveState) {
    digitalWrite(solenoidValvePin1, HIGH);
    digitalWrite(solenoidValvePin2, LOW);
    digitalWrite(solenoidValvePin3, LOW);
    digitalWrite(solenoidValvePin4, HIGH);
  } else {
    digitalWrite(solenoidValvePin1, LOW);
    digitalWrite(solenoidValvePin2, HIGH);
    digitalWrite(solenoidValvePin3, HIGH);
    digitalWrite(solenoidValvePin4, LOW);
  }

  digitalWrite(vacuumPumpPin1, HIGH);
  digitalWrite(vacuumPumpPin2, HIGH);
  
   if (irrecv.decode(&results)) {
    // Handle IR remote input
    switch (results.value) {
      case btn1: 
        delay(1000); // Adjust the delay for Button 1
        break;
      case btn2: 
        delay(1200); // Adjust the delay for Button 2
        break;
      case btn3: 
        delay(1400); // Adjust the delay for Button 3
        break;
      case btn4: 
        delay(1600); // Adjust the delay for Button 4
        break;
      case btn5: 
        delay(1800); // Adjust the delay for Button 5
        break;
      case btn6: 
        delay(2000); // Adjust the delay for Button 6
        break;
      case btn7: 
        delay(2200); // Adjust the delay for Button 7
        break;
      case btn8: 
        delay(2400); // Adjust the delay for Button 8
        break;
      case btn9: 
        delay(2600); // Adjust the delay for Button 9
        break;  
      default:
        // unrecognized input handled here
        break;
    }
    irrecv.resume(); // receive the next value
  }

}