
#define LED 0
#define BTN 1

#define dataPin 2
#define shiftPin 3
#define storePin 4

int data0[8] = {0,0,0,0,0,0,0,1};

unsigned long previousMillis = 0;
int dataState = 0;
int btnTranslatedState = HIGH;
bool btnState = false;
bool btnIsHigh = false;

void setup() {
  
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
  
  pinMode(storePin, OUTPUT);
  pinMode(shiftPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
 
}

void loop() {

  btnState = digitalRead(BTN);
  if(btnState){
    btnIsHigh = true;
  }
  if(!btnState && btnIsHigh){
    btnIsHigh = false;
    if(btnTranslatedState == HIGH){
      btnTranslatedState = LOW;
    }else{
      btnTranslatedState = HIGH;
    }
  }

  
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 1000 && btnTranslatedState) {
    
    previousMillis = currentMillis;
    if (dataState < 7) {
      dataState ++;
    }else{
      dataState = 0;
    }
  }

  digitalWrite(LED, btnTranslatedState);

  switch(dataState) {
    case 0:
      data0[7] = 0;
      data0[6] = 1;
      break;
    case 1:
      data0[6] = 0;
      data0[5] = 1;
      break;
    case 2:
      data0[5] = 0;
      data0[4] = 1;
      break;
    case 3:
      data0[4] = 0;
      data0[3] = 1;
      break;
    case 4:
      data0[3] = 0;
      data0[2] = 1;
      break;
    case 5:
      data0[2] = 0;
      data0[1] = 1;
      break;
    case 6:
      data0[1] = 0;
      data0[0] = 1;
      break;
    case 7:
      data0[0] = 0;
      data0[7] = 1;
      break; 
  }
  SerialStore(data0);
}

void SerialStore(int data[8]) {
  digitalWrite(storePin, LOW); 

  for (int i=0; i<8; i++) {
    digitalWrite(shiftPin, LOW);
    digitalWrite(dataPin, data[i]);
    digitalWrite(shiftPin, HIGH);
  }
  digitalWrite(storePin, HIGH);
}
