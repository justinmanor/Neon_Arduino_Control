/* Binary Neon sign code
 
Runs 0101 neon sign by Justin Manor

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

int RELAY_ON = LOW;
int RELAY_OFF = HIGH;

bool isSolidState = true;

char* myStrings[]={"SILK ROAD DELIVERIES IN BACK", //28
"NO ARTIFICIALS", //14
"NULL POINTER", //12
"NO ENCRYPTION HERE"}; //18

int lengths[] = {28,14,12,18};

char* testStrings[]={"ABCDEFGHIJKLMNOPQRSTUVXYZ", "1b8dj47639h@$!%"};

int lengths2[] = {26, 15};

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
  for (int i = 0 ; i < 8 ; i++) {
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);  

}

void loop()
{
  // here is where you'd put code that needs to be running all the time.

  int numStrings = 4;
  
  for (int i = 0 ; i < numStrings ; i ++) {
    playString(myStrings[i], lengths2[i], 4000);
    allOff(5000);
  }
  
  //binaryDigit('B', 5000);
  //allOn(4000);
  //allOff(5000);
}

void playString(char *msg, int length, int ms) {
 
  for (int i = 0 ; i < length ; i++) {
      binaryDigit(msg[i], ms); 
      //allOff(250);
  }
  delay(ms);
}

void binaryDigit(int num, int ms) {
 
 Serial.println(num);   
 
 int longFlag = false; 
  
 if (num > 79) {
   longFlag = true;
   num = num & B00001111;
   ms = ms*3;
   Serial.println("Character > N");
 } 
  
 Serial.println(num, BIN); 

 int digit1 = ( num & B0001 );
 int digit2 = ( num & B0010 ) > 1;
 int digit3 = ( num & B0100 ) > 2;
 int digit4 = ( num & B1000 ) > 3;
 
 Serial.print(digit4);
 Serial.print(digit3);
 Serial.print(digit2);
 Serial.println(digit1);
 
 
 if (digit4 == 1) {
   digitalWrite(pin_1, RELAY_OFF);
   digitalWrite(pin_5, RELAY_ON);
 } else {
   digitalWrite(pin_1, RELAY_ON);
   digitalWrite(pin_5, RELAY_OFF);  
 } 
 
 if (digit3 == 1) {
   digitalWrite(pin_2, RELAY_OFF);
   digitalWrite(pin_6, RELAY_ON);
 } else {
   digitalWrite(pin_2, RELAY_ON);
   digitalWrite(pin_6, RELAY_OFF);  
 } 

 if (digit2 == 1) {
   digitalWrite(pin_3, RELAY_OFF);
   digitalWrite(pin_7, RELAY_ON);
 } else {
   digitalWrite(pin_3, RELAY_ON);
   digitalWrite(pin_7, RELAY_OFF);  
 } 

 if (digit1 == 1) {
   digitalWrite(pin_4, RELAY_OFF);
   digitalWrite(pin_8, RELAY_ON);
 } else {
   digitalWrite(pin_4, RELAY_ON);
   digitalWrite(pin_8, RELAY_OFF);  
 } 
 
 delay(ms);
}


void allOff(int ms) {

  digitalWrite(pin_1, RELAY_OFF);
  digitalWrite(pin_2, RELAY_OFF);
  digitalWrite(pin_3, RELAY_OFF);
  digitalWrite(pin_4, RELAY_OFF);
  digitalWrite(pin_5, RELAY_OFF);
  digitalWrite(pin_6, RELAY_OFF);
  digitalWrite(pin_7, RELAY_OFF);
  digitalWrite(pin_8, RELAY_OFF);
  delay(ms);

}

void allOn(int ms) {

  digitalWrite(pin_1, RELAY_ON);
  digitalWrite(pin_2, RELAY_ON);
  digitalWrite(pin_3, RELAY_ON);
  digitalWrite(pin_4, RELAY_ON);
  digitalWrite(pin_5, RELAY_ON);
  digitalWrite(pin_6, RELAY_ON);
  digitalWrite(pin_7, RELAY_ON);
  digitalWrite(pin_8, RELAY_ON);
  delay(ms);

}

