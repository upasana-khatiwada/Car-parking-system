#include <LiquidCrystal.h>
#include <Servo.h>

const int irIn = 6; //IR sensor for car entrance
const int irOut = 7; //IR sensor for car exit
const int irPark1 = 8; //IR sensor for parking slot 1
const int irPark2 = 9; //IR sensor for parking slot 2
const int irPark3 = 10; //IR sensor for parking slot 3
const int irPark4 = 11; //IR sensor for parking slot 4
const int servoPin = 13; //Servo motor pin
const int lcdRS = 12;a
const int lcdEN = A0;
const int lcdD4 = 5;
const int lcdD5 = 4;
const int lcdD6 = 3;
const int lcdD7 = 2;
LiquidCrystal lcd(lcdRS, lcdEN, lcdD4, lcdD5, lcdD6, lcdD7); // Initialize the LCD library
Servo servo;

int slots = 4; //number of parking slots
int parked = 0; //number of parked cars

void setup() {
  pinMode(irIn, INPUT);
  pinMode(irOut, INPUT);
  pinMode(irPark1, INPUT);
  pinMode(irPark2, INPUT);
  pinMode(irPark3, INPUT);
  pinMode(irPark4, INPUT);
  lcd.begin(16, 2); // initialize the LCD display
  lcd.print("Parking: ");
  lcd.setCursor(0, 1);
  lcd.print(slots);
  lcd.print(" slots");
  servo.attach(servoPin); // attach the servo motor to the pin
  servo.write(0); // close the gate initially
}

void loop() {
  int irInState = digitalRead(irIn);
  int irOutState = digitalRead(irOut);
  int irPark1State = digitalRead(irPark1);
  int irPark2State = digitalRead(irPark2);
  int irPark3State = digitalRead(irPark3);
  int irPark4State = digitalRead(irPark4);
  
  if (irInState == HIGH) { //car entering the parking lot
    if (parked < slots) { //parking slots available
      servo.write(90); // open the gate
      delay(3000); // wait for the car to pass
      servo.write(0); // close the gate
      parked++; // increment the number of parked cars
      updateLCD(); // update the LCD display
    } else { //parking slots full
      lcd.clear();
      lcd.print("Parking is full");
      delay(2000);
      updateLCD();
    }
  }
  
  if (irOutState == HIGH) { //car leaving the parking lot
    if (parked > 0) { //cars parked in the parking lot
      servo.write(90); // open the gate
      delay(3000); // wait for the car to leave
      servo.write(0); // close the gate
      parked--; // decrement the number of parked cars
      updateLCD(); // update the LCD display
    } else { //no cars parked in the parking lot
      lcd.clear();
      lcd.print("No cars parked");
      delay(2000);
      updateLCD();
    }
  }
}

void updateLCD() {
  lcd.clear();
  lcd.print("Parking: ");
  lcd.setCursor(0, 1);
  lcd.print(slots - parked);
  lcd.print(" slots");
}
