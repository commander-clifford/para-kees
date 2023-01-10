/**
  * HID Computer Interface
  * https://github.com/NicoHood/HID/wiki/Consumer-API
*/
#include <HID-Project.h>
#include <HID-Settings.h>

const int button_1_pin = 7;
const int button_2_pin = 10;
const int button_3_pin = 16;
const int button_4_pin = 6;
const int button_5_pin = 9;
const int button_6_pin = 14;
const int button_7_pin = 5;
const int button_8_pin = 8;
const int button_9_pin = 15;

bool button_1_state;
bool button_2_state;
bool button_3_state;
bool button_4_state;
bool button_5_state;
bool button_6_state;
bool button_7_state;
bool button_8_state;
bool button_9_state;

bool last_button_1_state = HIGH;
bool last_button_2_state = HIGH;
bool last_button_3_state = HIGH;
bool last_button_4_state = HIGH;
bool last_button_5_state = HIGH;
bool last_button_6_state = HIGH;
bool last_button_7_state = HIGH;
bool last_button_8_state = HIGH;
bool last_button_9_state = HIGH;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 10; // the debounce time; increase if the output flickers

// button_1_actions(char action){
//  Keyboard.press(KEY_RIGHT_CTRL);
//   Keyboard.press(KEY_LEFT_GUI);
//   Keyboard.press(KEY_LEFT_SHIFT);
//   Keyboard.press('M');
//   Keyboard.press(KEY_RIGHT_ALT);
//   Keyboard.press(KEY_SPACE);                 
// }
// button_1_actions(char action){
//   Consumer.write(MEDIA_PREVIOUS);
// }


void button_1_actions(char action){
  Serial.println("button_1_action");                                                                                                          
  if(action == 1){
    Keyboard.press(KEY_ESC);
  } else {
    Keyboard.release(KEY_ESC);
  }
}
void button_2_actions(char action){                                        
  Serial.println("button_2_action");       
  if(action == 1){
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_RIGHT_SHIFT);
    Keyboard.press('P');
  } else {
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release(KEY_RIGHT_SHIFT);
    Keyboard.release('P');
  }
}
void button_3_actions(char action){
  Serial.println("button_3_action");
  if(action == 1){
    Keyboard.press(KEY_ENTER);
  } else {
    Keyboard.release(KEY_ENTER);
  }
}

void button_4_actions(char action){
  Serial.println("button_4_action");
  if(action == 1){
    Keyboard.press(KEY_RIGHT_SHIFT);
  } else {
    Keyboard.release(KEY_RIGHT_SHIFT);
  }
}
void button_5_actions(char action){
  Serial.println("button_5_action");
  if(action == 1){
    Keyboard.press(KEY_UP_ARROW);
  } else {
    Keyboard.release(KEY_UP_ARROW);
  }  
}
void button_6_actions(char action){
  Serial.println("button_6_action");
  if(action == 1){
    Keyboard.press(KEY_RIGHT_GUI);
  } else {
    Keyboard.release(KEY_RIGHT_GUI);
  }  
}

void button_7_actions(char action){
  Serial.println("button_7_action");
  if(action == 1){
    Keyboard.press(KEY_LEFT_ARROW);
  } else {
    Keyboard.release(KEY_LEFT_ARROW);
  }  
}
void button_8_actions(char action){
  Serial.println("button_8_action");
  if(action == 1){
    Keyboard.press(KEY_DOWN_ARROW);
  } else {
    Keyboard.release(KEY_DOWN_ARROW);
  }
}
void button_9_actions(char action){
  Serial.println("button_9_action");
  if(action == 1){
    Keyboard.press(KEY_RIGHT_ARROW);
  } else {
    Keyboard.release(KEY_RIGHT_ARROW);
  }  
}



void setup() {

  pinMode(button_1_pin, INPUT_PULLUP);
  pinMode(button_2_pin, INPUT_PULLUP);
  pinMode(button_3_pin, INPUT_PULLUP);
  pinMode(button_4_pin, INPUT_PULLUP);
  pinMode(button_5_pin, INPUT_PULLUP);
  pinMode(button_6_pin, INPUT_PULLUP);
  pinMode(button_7_pin, INPUT_PULLUP);
  pinMode(button_8_pin, INPUT_PULLUP);
  pinMode(button_9_pin, INPUT_PULLUP);

  Serial.begin(9600);

  Serial.println("**** para-kees ****");

  Consumer.begin(); //initialize computer connection
  delay(1000);
  Keyboard.begin();

}

void loop() {

  


  int reading_1 = digitalRead(button_1_pin);
  if (reading_1 != last_button_1_state) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading_1 != button_1_state) {
      button_1_state = reading_1;
      if (button_1_state == LOW) {
        button_1_actions(1);
      }
      if (button_1_state == HIGH) {
        button_1_actions(0);
      } 
    }
  }
  last_button_1_state = reading_1;


  int reading_2 = digitalRead(button_2_pin);
  if (reading_2 != last_button_2_state) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading_2 != button_2_state) {
      button_2_state = reading_2;
      if (button_2_state == LOW) {
        button_2_actions(1);
      }
      if (button_2_state == HIGH) {
        button_2_actions(0);
      } 
    }
  }
  last_button_2_state = reading_2;


  int reading_3 = digitalRead(button_3_pin);
  if (reading_3 != last_button_3_state) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading_3 != button_3_state) {
      button_3_state = reading_3;
      if (button_3_state == LOW) {
        button_3_actions(1);
      }
      if (button_3_state == HIGH) {
        button_3_actions(0);
      } 
    }
  }
  last_button_3_state = reading_3;


  int reading_4 = digitalRead(button_4_pin);
  if (reading_4 != last_button_4_state) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading_4 != button_4_state) {
      button_4_state = reading_4;
      if (button_4_state == LOW) {
        button_4_actions(1);
      }
      if (button_4_state == HIGH) {
        button_4_actions(0);
      }
    }
  }
  last_button_4_state = reading_4;


  int reading_5 = digitalRead(button_5_pin);
  if (reading_5 != last_button_5_state) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading_5 != button_5_state) {
      button_5_state = reading_5;
      if (button_5_state == LOW) {
        button_5_actions(1);
      }
      if (button_5_state == HIGH) {
        button_5_actions(0);
      } 
    }
  }
  last_button_5_state = reading_5;


  int reading_6 = digitalRead(button_6_pin);
  if (reading_6 != last_button_6_state) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading_6 != button_6_state) {
      button_6_state = reading_6;
      if (button_6_state == LOW) {
        button_6_actions(1);
      }
      if (button_6_state == HIGH) {
        button_6_actions(0);
      } 
    }
  }
  last_button_6_state = reading_6;


  int reading_7 = digitalRead(button_7_pin);
  if (reading_7 != last_button_7_state) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading_7 != button_7_state) {
      button_7_state = reading_7;
      if (button_7_state == LOW) {
        button_7_actions(1);
      }
      if (button_7_state == HIGH) {
        button_7_actions(0);
      }
    }
  }
  last_button_7_state = reading_7;


  int reading_8 = digitalRead(button_8_pin);
  if (reading_8 != last_button_8_state) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading_8 != button_8_state) {
      button_8_state = reading_8;
      if (button_8_state == LOW) {
        button_8_actions(1);
      }
      if (button_8_state == HIGH) {
        button_8_actions(0);
      } 
    }
  }
  last_button_8_state = reading_8;

  
  int reading_9 = digitalRead(button_9_pin);
  if (reading_9 != last_button_9_state) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading_9 != button_9_state) {
      button_9_state = reading_9;
      if (button_9_state == LOW) {
        button_9_actions(1);
      }
      if (button_9_state == HIGH) {
        button_9_actions(0);
      } 
    }
  }
  last_button_9_state = reading_9;  
}





