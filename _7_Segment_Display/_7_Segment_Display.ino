/* 7_Segment_Neon
 
 */

// constants won't change. Used here to 
// set pin numbers:
const int ledPin =  13;      // the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 1000;           // interval at which to blink (milliseconds)

int pi_decimal[] = {
  1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,2,7,9,5,0,2,8,8,4,1};
int e_decimal[] = {
  7,1,8,2,8,1,8,2,8,4,5,9,0,4,5,2,3,5,3,6,0,2,8,7,4,7,1,3,5,2,6,6,2,4,9,7,7}; //37 digits
int cc[] = {4,3,1,7,3,3,1,0,1,2,0,2,1,6,0,8}; //16
int nums[] = {9,1,1,9,1,1,9,1,1,6,6,6,9,1,1,9,1,1,5,0,5,0,5,0,5,0,5,0}; //28
int fibonacci[] = {0,1,1,2,3,5,8,1,3,2,1,3,4,5,5,8,9,1,4,4,2,3,3,3,7,7}; //26

int RELAY_ON = LOW;
int RELAY_OFF = HIGH;

bool isSolidState = true;

int pin_1 = 2;
int pin_2 = 3;
int pin_3 = 4;
int pin_4 = 5;
int pin_5 = 6;
int pin_6 = 7;
int pin_7 = 8;
int pin_8 = 9;

void setup() {

  if (isSolidState) {
      RELAY_ON = HIGH;
      RELAY_OFF = LOW;
  }
  
  // set the LED pin as output:
  pinMode(ledPin, OUTPUT);  

  // set up segments as outputs
  for (int i = 0 ; i < 7 ; i++) {
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);
}

void loop()
{
  // here is where you'd put code that needs to be running all the time.

  int slow = 3000;
  int med = 1000;
  int fast = 500;

  binarySequence(10, slow);
  
  spinCW(fast);
  spinCCW(fast);
  wiggle(fast);
  allOff(med);
  
  //PI
  digit(3, med);
  middle(med);
  digitSequence(pi_decimal, 35, med);

  upDown(med);
  downUp(med);
  
  //e
  digit(2, med);
  middle(med);
  digitSequence(e_decimal, 37, med);

  doubleSpinCW(med);
  doubleSpinCCW(med);
  allOff(med);
  
  //867-5309
  song(fast);
  wiggle(fast);
  song(fast);
  wiggle(fast);
  allOff(med);
  
  //911
  digitSequence(nums, 28, fast);
  spinCW(fast);
  spinCW(fast);
  
  //CC
  digitSequence(cc, 16, fast);
  spinCCW(fast);
  spinCCW(fast);
  
  //fibonacci
  digitSequence(fibonacci, 26, med, 100);
  
  swirl1(fast);
  swirl2(fast);
  
}

void digit(int num, int ms) {
  
  Serial.println(num);
  
  switch (num) {
  case 0:
    digitalWrite(pin_1, RELAY_ON);
    digitalWrite(pin_2, RELAY_ON);
    digitalWrite(pin_3, RELAY_ON);
    digitalWrite(pin_4, RELAY_OFF);
    digitalWrite(pin_5, RELAY_ON);
    digitalWrite(pin_6, RELAY_ON);
    digitalWrite(pin_7, RELAY_ON);
    break;
  case 1:
    digitalWrite(pin_1, RELAY_OFF);
    digitalWrite(pin_2, RELAY_OFF);
    digitalWrite(pin_3, RELAY_ON);
    digitalWrite(pin_4, RELAY_OFF);
    digitalWrite(pin_5, RELAY_OFF);
    digitalWrite(pin_6, RELAY_ON);
    digitalWrite(pin_7, RELAY_OFF);
    break;
  case 2:
    digitalWrite(pin_1, RELAY_ON);
    digitalWrite(pin_2, RELAY_OFF);
    digitalWrite(pin_3, RELAY_ON);
    digitalWrite(pin_4, RELAY_ON);
    digitalWrite(pin_5, RELAY_ON);
    digitalWrite(pin_6, RELAY_OFF);
    digitalWrite(pin_7, RELAY_ON);
    break;
  case 3:
    digitalWrite(pin_1, RELAY_ON);
    digitalWrite(pin_2, RELAY_OFF);
    digitalWrite(pin_3, RELAY_ON);
    digitalWrite(pin_4, RELAY_ON);
    digitalWrite(pin_5, RELAY_OFF);
    digitalWrite(pin_6, RELAY_ON);
    digitalWrite(pin_7, RELAY_ON);
    break;
  case 4:
    digitalWrite(pin_1, RELAY_OFF);
    digitalWrite(pin_2, RELAY_ON);
    digitalWrite(pin_3, RELAY_ON);
    digitalWrite(pin_4, RELAY_ON);
    digitalWrite(pin_5, RELAY_OFF);
    digitalWrite(pin_6, RELAY_ON);
    digitalWrite(pin_7, RELAY_OFF);
    break;
  case 5:
    digitalWrite(pin_1, RELAY_ON);
    digitalWrite(pin_2, RELAY_ON);
    digitalWrite(pin_3, RELAY_OFF);
    digitalWrite(pin_4, RELAY_ON);
    digitalWrite(pin_5, RELAY_OFF);
    digitalWrite(pin_6, RELAY_ON);
    digitalWrite(pin_7, RELAY_ON);
    break;
  case 6:
    digitalWrite(pin_1, RELAY_OFF);
    digitalWrite(pin_2, RELAY_ON);
    digitalWrite(pin_3, RELAY_OFF);
    digitalWrite(pin_4, RELAY_ON);
    digitalWrite(pin_5, RELAY_ON);
    digitalWrite(pin_6, RELAY_ON);
    digitalWrite(pin_7, RELAY_ON);
    break;
  case 7:
    digitalWrite(pin_1, RELAY_ON);
    digitalWrite(pin_2, RELAY_OFF);
    digitalWrite(pin_3, RELAY_ON);
    digitalWrite(pin_4, RELAY_OFF);
    digitalWrite(pin_5, RELAY_OFF);
    digitalWrite(pin_6, RELAY_ON);
    digitalWrite(pin_7, RELAY_OFF);
    break;
  case 8:
    digitalWrite(pin_1, RELAY_ON);
    digitalWrite(pin_2, RELAY_ON);
    digitalWrite(pin_3, RELAY_ON);
    digitalWrite(pin_4, RELAY_ON);
    digitalWrite(pin_5, RELAY_ON);
    digitalWrite(pin_6, RELAY_ON);
    digitalWrite(pin_7, RELAY_ON);
    break;       
  case 9:
    digitalWrite(pin_1, RELAY_ON);
    digitalWrite(pin_2, RELAY_ON);
    digitalWrite(pin_3, RELAY_ON);
    digitalWrite(pin_4, RELAY_ON);
    digitalWrite(pin_5, RELAY_OFF);
    digitalWrite(pin_6, RELAY_ON);
    digitalWrite(pin_7, RELAY_OFF);
    break;           
  }
  delay(ms);
}

void allOff(int ms) {

  Serial.println("allOff");

  
  digitalWrite(pin_1, RELAY_OFF);
  digitalWrite(pin_2, RELAY_OFF);
  digitalWrite(pin_3, RELAY_OFF);
  digitalWrite(pin_4, RELAY_OFF);
  digitalWrite(pin_5, RELAY_OFF);
  digitalWrite(pin_6, RELAY_OFF);
  digitalWrite(pin_7, RELAY_OFF);
  delay(ms);


}

void top(int ms) {

  digitalWrite(pin_1, RELAY_ON);
  digitalWrite(pin_2, RELAY_OFF);
  digitalWrite(pin_3, RELAY_OFF);
  digitalWrite(pin_4, RELAY_OFF);
  digitalWrite(pin_5, RELAY_OFF);
  digitalWrite(pin_6, RELAY_OFF);
  digitalWrite(pin_7, RELAY_OFF);
  delay(ms);

}

void middle(int ms) {

  digitalWrite(pin_1, RELAY_OFF);
  digitalWrite(pin_2, RELAY_OFF);
  digitalWrite(pin_3, RELAY_OFF);
  digitalWrite(pin_4, RELAY_ON);
  digitalWrite(pin_5, RELAY_OFF);
  digitalWrite(pin_6, RELAY_OFF);
  digitalWrite(pin_7, RELAY_OFF);
  delay(ms);

}

void bottom(int ms) {

  digitalWrite(pin_1, RELAY_OFF);
  digitalWrite(pin_2, RELAY_OFF);
  digitalWrite(pin_3, RELAY_OFF);
  digitalWrite(pin_4, RELAY_OFF);
  digitalWrite(pin_5, RELAY_OFF);
  digitalWrite(pin_6, RELAY_OFF);
  digitalWrite(pin_7, RELAY_ON);
  delay(ms);

}

void upperLeft(int ms) {

  digitalWrite(pin_1, RELAY_OFF);
  digitalWrite(pin_2, RELAY_ON);
  digitalWrite(pin_3, RELAY_OFF);
  digitalWrite(pin_4, RELAY_OFF);
  digitalWrite(pin_5, RELAY_OFF);
  digitalWrite(pin_6, RELAY_OFF);
  digitalWrite(pin_7, RELAY_OFF);
  delay(ms);

}

void lowerLeft(int ms) {

  digitalWrite(pin_1, RELAY_OFF);
  digitalWrite(pin_2, RELAY_OFF);
  digitalWrite(pin_3, RELAY_OFF);
  digitalWrite(pin_4, RELAY_OFF);
  digitalWrite(pin_5, RELAY_ON);
  digitalWrite(pin_6, RELAY_OFF);
  digitalWrite(pin_7, RELAY_OFF);
  delay(ms);

}

void upperRight(int ms) {

  digitalWrite(pin_1, RELAY_OFF);
  digitalWrite(pin_2, RELAY_OFF);
  digitalWrite(pin_3, RELAY_ON);
  digitalWrite(pin_4, RELAY_OFF);
  digitalWrite(pin_5, RELAY_OFF);
  digitalWrite(pin_6, RELAY_OFF);
  digitalWrite(pin_7, RELAY_OFF);
  delay(ms);

}

void lowerRight(int ms) {

  digitalWrite(pin_1, RELAY_OFF);
  digitalWrite(pin_2, RELAY_OFF);
  digitalWrite(pin_3, RELAY_OFF);
  digitalWrite(pin_4, RELAY_OFF);
  digitalWrite(pin_5, RELAY_OFF);
  digitalWrite(pin_6, RELAY_ON);
  digitalWrite(pin_7, RELAY_OFF);
  delay(ms);

}

void slash(int ms) {

  digitalWrite(pin_1, RELAY_OFF);
  digitalWrite(pin_2, RELAY_OFF);
  digitalWrite(pin_3, RELAY_ON);
  delay(10);
  digitalWrite(pin_4, RELAY_ON);
  delay(10);
  digitalWrite(pin_5, RELAY_ON);
  digitalWrite(pin_6, RELAY_OFF);
  digitalWrite(pin_7, RELAY_OFF);
  delay(ms);
}

void backslash(int ms) {

  digitalWrite(pin_1, RELAY_OFF);
  digitalWrite(pin_2, RELAY_ON);
  delay(10);
  digitalWrite(pin_3, RELAY_OFF);
  digitalWrite(pin_4, RELAY_ON);
  delay(10);
  digitalWrite(pin_5, RELAY_OFF);
  digitalWrite(pin_6, RELAY_ON);
  digitalWrite(pin_7, RELAY_OFF);
  delay(ms);

}

void spinCW(int ms) {

  Serial.println("spinCW");
  
  top(ms);
  upperRight(ms);
  lowerRight(ms);
  bottom(ms);
  lowerLeft(ms);
  upperLeft(ms);

}

void spinCCW(int ms) {

  Serial.println("spinCCW");
  
  top(ms);
  upperLeft(ms);
  lowerLeft(ms);
  bottom(ms);
  lowerRight(ms);
  upperRight(ms);

}

void wiggle(int ms) {

  Serial.println("wiggle");  
  
  slash(ms);
  backslash(ms);
  slash(ms);
  backslash(ms);
  slash(ms);
  backslash(ms);
  slash(ms);
  backslash(ms);

}

void digitSequence( int* numbers, int count, int ms) {

  for (int i = 0 ; i < count ; i++) {
    digit(numbers[i], ms); 
  }

} 

void digitSequence( int* numbers, int count, int ms, int offTime) {

  for (int i = 0 ; i < count ; i++) {
    digit(numbers[i], ms); 
  }
  allOff(offTime);
} 

void binarySequence(int count, int ms) {

  for (int i = 0 ; i < count ; i++) {

    int oneOrZero = random(1000);

    Serial.print(oneOrZero);
    Serial.print(" ");
    
    if (oneOrZero > 500)
      oneOrZero = 0;
    else
      oneOrZero = 1;
    Serial.println(oneOrZero);
    
    digit(oneOrZero, ms); 
  }

}

void digitSequence(int count, int ms) {

  for (int i = 0 ; i < count ; i++) {

    int num = random(10);
    digit(num, ms); 
    Serial.print(num, DEC);
  }

}

void swirl1(int ms) {

  Serial.println("swirl1");

  
  top(ms);
  upperRight(ms);
  middle(ms);
  lowerLeft(ms);
  bottom(ms);
  lowerRight(ms);
  middle(ms);
  upperLeft(ms);

}

void swirl2(int ms) {

  Serial.println("swirl2");  
  
  top(ms);
  upperLeft(ms);
  middle(ms);
  lowerRight(ms);
  bottom(ms);
  lowerLeft(ms);
  middle(ms);
  upperRight(ms);

}

void doubleSpinCW(int ms) {
  
  Serial.println("doubleSpinCW");
  
  twoSegments(0,6,ms);
  twoSegments(2,4,ms);
  twoSegments(1,5,ms);
  twoSegments(0,6,ms);
  twoSegments(2,4,ms);
  twoSegments(1,5,ms);
  
}

void doubleSpinCCW(int ms) {
  
  Serial.println("doubleSpinCCW");  
  
  twoSegments(0,6,ms);
  twoSegments(1,5,ms);
  twoSegments(2,4,ms);
  twoSegments(0,6,ms);
  twoSegments(1,5,ms);
  twoSegments(2,4,ms);
  
}

void upDown(int ms) {
  
  Serial.println("upDown");
  
  bottom(ms);
  twoSegments(4,5,ms);
  twoSegments(1,2,ms);
  top(ms);
  twoSegments(1,2,ms);
  twoSegments(4,5,ms);
  bottom(ms);
  
}

void downUp(int ms) {
  
  Serial.println("downUp");
  top(ms);
  twoSegments(1,2,ms);
  twoSegments(4,5,ms);
  bottom(ms);
  twoSegments(4,5,ms);
  twoSegments(1,2,ms);  
  top(ms);
  
}

void twoSegments(int seg1, int seg2, int ms) {

  for (int i = 0 ; i < 7 ; i++) {
    if (i == seg1 || i == seg2)
      digitalWrite(i+2, RELAY_ON);
    else
      digitalWrite(i+2, RELAY_OFF);
  }
  delay(ms);
}

void song(int ms) {
  
  Serial.println("song");  
  
  digit(8, ms);
  digit(6, ms);
  digit(7, ms);
  middle(ms);
  digit(5, ms);
  digit(3, ms);
  digit(0, ms);
  digit(9, ms);
  
}  

