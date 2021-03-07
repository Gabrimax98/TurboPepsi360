
#include <USBComposite.h>

USBHID HID;
HIDJoystick Joystick(HID);
USBXBox360 XBox360;
bool analogpepsi;



void setup() { 
  //stick
  pinMode(PB12,INPUT_PULLUP);
  pinMode(PB13,INPUT_PULLUP);
  pinMode(PB14,INPUT_PULLUP);
  pinMode(PB15,INPUT_PULLUP); 
  //buttons
  pinMode(PB3,INPUT_PULLUP);
  pinMode(PB4,INPUT_PULLUP);
  pinMode(PB6,INPUT_PULLUP);
  pinMode(PB7,INPUT_PULLUP);
  pinMode(PB8,INPUT_PULLUP);
  pinMode(PB9,INPUT_PULLUP);
  pinMode(PB10,INPUT_PULLUP);
  pinMode(PB11,INPUT_PULLUP);
   pinMode(PB0,OUTPUT);
  USBComposite.setProductString("Microsoft(TM) Xbox(R) TurboPepsi 360");
// USBComposite.setProductString("Turbo");
  XBox360.begin();
    adc_set_sample_rate(ADC1, ADC_SMPR_13_5); // ADC_SMPR_13_5, ADC_SMPR_1_5
    XBox360.setManualReportMode(true);
    
  while(true){
    if (digitalRead(PB7)==LOW && digitalRead(PB4)==LOW && digitalRead(PB6)==LOW && digitalRead(PB3)==HIGH && digitalRead(PB11)==HIGH && digitalRead(PB9)==HIGH && digitalRead(PB10)==HIGH && digitalRead(PB8)==HIGH){
      if (analogpepsi){
      digitalWrite(PB0,LOW);
      analogpepsi=false;
      delay(500);
      }else{
      digitalWrite(PB0,HIGH);
      analogpepsi=true;
      delay(500);
      }
    }
    
    if (analogpepsi==false){
      if (digitalRead(PB13) == LOW) XBox360.button(XBOX_DUP,true);
 else XBox360.button(XBOX_DUP,false);
  if (digitalRead(PB12) == LOW) XBox360.button(XBOX_DDOWN,true);
 else XBox360.button(XBOX_DDOWN,false);
  if (digitalRead(PB15) == LOW) XBox360.button(XBOX_DLEFT,true);
 else XBox360.button(XBOX_DLEFT,false);
  if (digitalRead(PB14) == LOW) XBox360.button(XBOX_DRIGHT,true);
 else XBox360.button(XBOX_DRIGHT,false);
    }else{
  if (digitalRead(PB13) == LOW) XBox360.Y(32767);
  else if (digitalRead(PB12) == LOW) XBox360.Y(-32768);
  else XBox360.Y(0);
  if (digitalRead(PB15) == LOW) XBox360.X(-32768);
  else if (digitalRead(PB14) == LOW) XBox360.X(32767);
 else XBox360.X(0);
    }
    
  if (digitalRead(PB3) == LOW) XBox360.button(XBOX_START,true);
 else XBox360.button(XBOX_START,false);
  if (digitalRead(PB4) == LOW) XBox360.button(XBOX_BACK,true);
 else XBox360.button(XBOX_BACK,false);
  if (digitalRead(PB11) == LOW) XBox360.button(XBOX_A,true);
 else XBox360.button(XBOX_A,false);
  if (digitalRead(PB9) == LOW) XBox360.button(XBOX_B,true);
 else XBox360.button(XBOX_B,false);
  if (digitalRead(PB10) == LOW) XBox360.button(XBOX_X,true);
 else XBox360.button(XBOX_X ,false);
   if (digitalRead(PB8) == LOW) XBox360.button(XBOX_Y,true);
 else XBox360.button(XBOX_Y ,false);
    if (digitalRead(PB7) == LOW) XBox360.button(XBOX_LSHOULDER,true);
 else XBox360.button(XBOX_LSHOULDER ,false);
     if (digitalRead(PB6) == LOW) XBox360.button(XBOX_RSHOULDER,true);
 else XBox360.button(XBOX_RSHOULDER ,false);
 XBox360.send();
  }
}

void loop() {
}
