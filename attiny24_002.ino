#define LED 0
#define BTN 1

#define dataPin 2
#define shiftPin 3
#define storePin 4

bool leds[8] = {0,0,0,0,0,0,0,0};

unsigned long millisCounter0 = 0;
byte ledOn = 0;
bool btnState = false;
byte level = 0;
byte endLevel = 0;
short interval;

void setup() {
  
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
  
  pinMode(storePin, OUTPUT);
  pinMode(shiftPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
 
}

void loop() {
  if(level == 0){
    ledOn = 0;
    rstLeds();
    SerialStore(leds);
    delay(200);
    shwLvl(1);
    level = 1;
    delay(3000);
    rstLeds();
    SerialStore(leds);
    delay(200);
  }

  btnState = digitalRead(BTN);
  
  unsigned long currentMillis = millis();

  if (currentMillis - millisCounter0 >= interval && level > 0) {

    if(level <= 15){
      interval = 2000/level;
    }
    
    millisCounter0  = currentMillis;
    if (ledOn < 7) {
      ledOn ++;
    }else{
      ledOn = 0;
    }
    rstLeds();
    leds[ledOn] = 1;
  }
  if(btnState){
    delay(1000);
    
    if(ledOn == 0){
      rstLeds();
    SerialStore(leds);
    delay(200);
      level ++;
      shwLvl(level);
      delay(3000);
      rstLeds();
    SerialStore(leds);
    delay(200);
      
    }else{
      endLevel = level;
      rstLeds();
      SerialStore(leds);
      delay(200);
      for (byte i=0; i<8; i++) {
        level = endLevel;
        shwLvl(level);
        delay(100);
        level = 0;
        shwLvl(level);
        delay(100);
      }
      rstLeds();
      SerialStore(leds);
      delay(200);
    }
    
  }
  SerialStore(leds);
}

void SerialStore(bool data[8]) {
  digitalWrite(storePin, LOW); 

  for (byte i=0; i<8; i++) {
    digitalWrite(shiftPin, LOW);
    digitalWrite(dataPin, data[7 - i]);
    digitalWrite(shiftPin, HIGH);
  }
  digitalWrite(storePin, HIGH);
}

void rstLeds() {
  for (byte i=0; i<8; i++) {
    leds[i] = 0;
  }
  SerialStore(leds);
}

void shwLvl(byte lvl){
  rstLeds();
  for (byte i=0; i<8; i++) {
    leds[i] = bitRead(lvl, i);
  }
  SerialStore(leds);
}
