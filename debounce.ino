//////////////////////////Define/////////////////////////////////
int ButtonState;
int lastState = HIGH;
int Button = 10;
long lastDebounceTime = 0;
int countDelay = 200;
long debounceDelay = 75;
int count = 0;
int rise = 0;
int fall = 0;
long lastCountTime = 0;
long lastFallTime = 0;
/////////////////////////////////////////////////////////////////
//**************************************************************
///////////////////////////Setup////////////////////////////////
void setup() {
  pinMode(Button, INPUT_PULLUP);
}
////////////////////////////////////////////////////////////////
//**************************************************************
////////////////////////////Loop////////////////////////////////
void loop() {
  ButtonState = digitalRead(Button);
  if (ButtonState == LOW && lastState == HIGH){
    if ( (millis() - lastDebounceTime) > debounceDelay) {
      rise ++;
    }
    lastState = ButtonState;
    lastDebounceTime = millis();
  } else if (ButtonState == HIGH && lastState == LOW){
    if ( (millis() - lastFallTime) > debounceDelay) {
      fall ++;
      lastFallTime = millis();
    }
    lastState = ButtonState;
  } else if (ButtonState == LOW && lastState == LOW){
    if ( (millis() - lastCountTime) > countDelay) {
      count ++;
      lastCountTime = millis();
    }
    lastState = ButtonState;
  }
}
//////////////////////////////////////////////////////////////////