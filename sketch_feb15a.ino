//#include <arduino-timer.h>
//everything works now
#include <TrueRandom.h>
//compiles, connect and check for functionality
#define MS_TO_S 1000
//too long, do 6s * 10
//delay works now
#define S_TO_M1 6 //was 60
#define S_TO_M2 10
// PIN for 0 to 11 o'clock
//PIN 0 and 1 ALWAYS high when serial print active!!!
#define PIN0 0 //was 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define PIN8 8
#define PIN9 9
#define PIN10 10
#define PIN11 11

//use A5 and 13 for clock face indicator
// A5 for front, morning. 13 for back, afternoon.
#define PIN_Front 19 //A5
#define PIN_BACK 13

//use A0 to A4 for weather, A0 is 14
#define PIN_SUNNY 14
#define PIN_RAINY 15
#define PIN_CLOUDY 16
#define PIN_SNOWY 17
#define PIN_STORM 18

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN0, OUTPUT);
  pinMode(PIN1, OUTPUT);
  pinMode(PIN2, OUTPUT);
  pinMode(PIN3, OUTPUT);
  pinMode(PIN4, OUTPUT);
  pinMode(PIN5, OUTPUT);
  pinMode(PIN6, OUTPUT);
  pinMode(PIN7, OUTPUT);
  pinMode(PIN8, OUTPUT);
  pinMode(PIN9, OUTPUT);
  pinMode(PIN10, OUTPUT);
  pinMode(PIN11, OUTPUT);

  pinMode(PIN_Front, OUTPUT);
  pinMode(PIN_BACK, OUTPUT);

  pinMode(PIN_SUNNY, OUTPUT);
  pinMode(PIN_RAINY, OUTPUT);
  pinMode(PIN_CLOUDY, OUTPUT);
  pinMode(PIN_SNOWY, OUTPUT);
  pinMode(PIN_STORM, OUTPUT);
  // the seed need non 0 number input
  //randomSeed(10);
  //have some debug code
  //Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
  // may need resistor, especially for indicator and weather 
  // set a timer, then make a iterator state machine
  // use arduino delay(ms), digital write (high/low), 5V
  // turn current time and 2 time before ON

  //weather ALWAYS 2
  //int weather = random(0, 5);
  int weather = TrueRandom.random(0, 5);
  int i;
  // remember to turn EVERYTHING off at the end of loop
  //Serial.println(weather);
  switch(weather) {
    case 0:
      digitalWrite(PIN_SUNNY, HIGH);
      break;

    case 1:
      digitalWrite(PIN_RAINY, HIGH);
      break;

    case 2:
      digitalWrite(PIN_CLOUDY, HIGH);
      break;
    
    case 3:
      digitalWrite(PIN_SNOWY, HIGH);
      break;

    default:
      digitalWrite(PIN_STORM, HIGH);
      break;
  }

  //turn front clock face ON
  digitalWrite(PIN_Front, HIGH);
  //0 and 1 not turn off correctly
  digitalWrite(PIN0, LOW);
  digitalWrite(PIN1, LOW);
  //0 o'clock
  digitalWrite(PIN10, HIGH);
  digitalWrite(PIN11, HIGH);
  digitalWrite(PIN0, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //1 o'clock
  //turn previous off
  digitalWrite(PIN10, LOW);
  digitalWrite(PIN1, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //2 o'clock
  digitalWrite(PIN11, LOW);
  digitalWrite(PIN2, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //3 o'clock
  digitalWrite(PIN0, LOW);
  digitalWrite(PIN3, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //4 o'clock
  digitalWrite(PIN1, LOW);
  digitalWrite(PIN4, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //5 o'clock
  digitalWrite(PIN2, LOW);
  digitalWrite(PIN5, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //6 o'clock
  digitalWrite(PIN3, LOW);
  digitalWrite(PIN6, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //7 o'clock
  digitalWrite(PIN4, LOW);
  digitalWrite(PIN7, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //8 o'clock
  digitalWrite(PIN5, LOW);
  digitalWrite(PIN8, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //9 o'clock
  digitalWrite(PIN6, LOW);
  digitalWrite(PIN9, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //10 o'clock
  digitalWrite(PIN7, LOW);
  digitalWrite(PIN10, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //11 o'clock
  digitalWrite(PIN8, LOW);
  digitalWrite(PIN11, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //switch AM to PM
  digitalWrite(PIN_Front, LOW);
  digitalWrite(PIN_BACK, HIGH);

  //12 o'clock
  digitalWrite(PIN9, LOW);
  digitalWrite(PIN0, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //13 o'clock
  digitalWrite(PIN10, LOW);
  digitalWrite(PIN1, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //13 o'clock
  digitalWrite(PIN11, LOW);
  digitalWrite(PIN2, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //15 o'clock
  digitalWrite(PIN0, LOW);
  digitalWrite(PIN3, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //16 o'clock
  digitalWrite(PIN1, LOW);
  digitalWrite(PIN4, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //17 o'clock
  digitalWrite(PIN2, LOW);
  digitalWrite(PIN5, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //18 o'clock
  digitalWrite(PIN3, LOW);
  digitalWrite(PIN6, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //19 o'clock
  digitalWrite(PIN4, LOW);
  digitalWrite(PIN7, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //20 o'clock
  digitalWrite(PIN5, LOW);
  digitalWrite(PIN8, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //21 o'clock
  digitalWrite(PIN6, LOW);
  digitalWrite(PIN9, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //22 o'clock
  digitalWrite(PIN7, LOW);
  digitalWrite(PIN10, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //23 o'clock
  digitalWrite(PIN8, LOW);
  digitalWrite(PIN11, HIGH);
  //delay 1 minute
  for (i = 0; i < S_TO_M2; i++) { 
    delay(1 * MS_TO_S * S_TO_M1);
  } 

  //end, turn everything off
  digitalWrite(PIN_BACK, LOW);
  digitalWrite(PIN9, LOW);
  digitalWrite(PIN10, LOW);
  digitalWrite(PIN11, LOW);
  digitalWrite(PIN0, LOW);
  digitalWrite(PIN1, LOW);
  //turn weather off
  switch(weather) {
    case 0:
      digitalWrite(PIN_SUNNY, LOW);
      break;

    case 1:
      digitalWrite(PIN_RAINY, LOW);
      break;

    case 2:
      digitalWrite(PIN_CLOUDY, LOW);
      break;
    
    case 3:
      digitalWrite(PIN_SNOWY, LOW);
      break;

    default:
      digitalWrite(PIN_STORM, LOW);
      break;
  }
}
