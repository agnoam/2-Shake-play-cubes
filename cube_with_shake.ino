//general
int buttonState = 0;
int statefc1 = 0;
int stateTwo = 0;
int button = 13;
int startup = 0;
int ShakePin = 7;
int ShakesCounter = 0;
int ShakeReader = 0;
long  measurement = 0;
//**************************************************//

//cubeOne (Yello)
const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const int ledPin4 = 5;

//**************************************************//

//cubeTwo (Red)
const int ledPin5 = 9;
const int ledPin6 = 10;
const int ledPin7 = 6;
const int ledPin8 = 8;

//**************************************************//
const int readyPin = 11;
const int workingPin = 12;
//*************************************************//
void setup() {
  
  pinMode(button, INPUT);
//  pinMode(acceloState, INPUT);
  pinMode(buttonState, INPUT);
//  pinMode(statefc1, INPUT);
//  pinMode(stateTwo, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  pinMode(startup, INPUT);
  pinMode(ShakePin, INPUT);
  pinMode(workingPin, OUTPUT);
  pinMode(readyPin, OUTPUT);
  Serial.begin(9600);
  //Serial.begin(4800);

}

void loop() {
    if(startup == 0){ 
      startup = 1;
      
      for(int i=7;  i>=0;  i--){
        light_cube1(i);
        light_cube2(i);
        delay(300);
      }
    }
    
    buttonState = digitalRead(button);
    ShakeReader = digitalRead(ShakePin);
    measurement = pulseIn (ShakePin, HIGH);
    ShakesCounter = ShakesCounter + ShakeReader + measurement;
    
  if(buttonState == 1 || ShakesCounter > 0){
    digitalWrite(workingPin, HIGH);
    
    statefc1 = random (1,7);
    stateTwo = random (1,7);
    
    delay(200);
    light_cube1(statefc1);
    light_cube2(stateTwo);
    
    ShakesCounter = ShakesCounter /4;
    
    statefc1 = random (1,7);
    stateTwo = random (1,7);
    
    light_cube1(statefc1);
    light_cube2(stateTwo);
    digitalWrite(readyPin, HIGH);
  }else{
    digitalWrite(workingPin, LOW);
    digitalWrite(readyPin, HIGH);
  }

  Serial.println(ShakesCounter);
}
  /* loop done */ 
  // TheExplane
  // Cube 1
  void light_cube1(int state){
    
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);

    switch(state){
      case 1:
        digitalWrite(ledPin1, HIGH);
        break;

      case 2:
        digitalWrite(ledPin2, HIGH);
        break;

      case 3:
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        break;

      case 4:
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, HIGH);
        break;

      case 5:
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, HIGH);
        break; 

      case 6:
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, HIGH);
        digitalWrite(ledPin4, HIGH);

      case 7:
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        digitalWrite(ledPin3, HIGH);
        digitalWrite(ledPin4, HIGH);
        break;
    }  
  }
//__________________________________________________//
  
  // Cube 2  

 void light_cube2(int stateTwo){

    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
    
    switch(stateTwo){
      case 1:
        digitalWrite(ledPin5, HIGH);
        break;

      case 2:
        digitalWrite(ledPin6, HIGH);
        break;

      case 3:
        digitalWrite(ledPin5, HIGH);
        digitalWrite(ledPin6, HIGH);
        break;

      case 4:
        digitalWrite(ledPin6, HIGH);
        digitalWrite(ledPin7, HIGH); 
        break;

      case 5:
        digitalWrite(ledPin5, HIGH);
        digitalWrite(ledPin6, HIGH);
        digitalWrite(ledPin7, HIGH);  
        break;

      case 6:
        digitalWrite(ledPin6, HIGH);
        digitalWrite(ledPin7, HIGH);
        digitalWrite(ledPin8, HIGH);
        break;

      case 7:
        digitalWrite(ledPin5, HIGH);
        digitalWrite(ledPin6, HIGH);
        digitalWrite(ledPin7, HIGH);
        digitalWrite(ledPin8, HIGH);
        break;
    }
}
