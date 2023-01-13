// https://github.com/NicoHood/HID
#include <HID-Project.h>

// Add or Remove pins as needed 
const int buttonPins[] = {7, 10, 16, 6, 9, 14, 5, 8, 15};
// Add or Remove pins as needed 

void default_function(char action){
  Serial.println("default");
  // Consumer.write(MEDIA_PREVIOUS);
  // Keyboard.press(KEY_RIGHT_CTRL);
  // Keyboard.press(KEY_LEFT_GUI);
  // Keyboard.press(KEY_LEFT_SHIFT);
  // Keyboard.press('M');
  // Keyboard.press(KEY_RIGHT_ALT);
  // Keyboard.press(KEY_SPACE);
}
// Add or Remove functions as needed 
void button_function_1(char action){
  Serial.println("button_1_action");                                                                                                          
  if(action == 1){
    Keyboard.press(KEY_ESC);
  } else {
    Keyboard.release(KEY_ESC);
  }
}
void button_function_2(char action){
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
void button_function_3(char action){
  Serial.println("button_3_action");
  if(action == 1){
    Keyboard.press(KEY_ENTER);
  } else {
    Keyboard.release(KEY_ENTER);
  }
}
void button_function_4(char action){
  Serial.println("button_4_action");
  if(action == 1){
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('D');
  } else {
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.release('D');
  }
}
void button_function_5(char action){
  Serial.println("button_5_action");
  if(action == 1){
    Keyboard.press(KEY_UP_ARROW);
  } else {  
    Keyboard.release(KEY_UP_ARROW);
  }  
}
void button_function_6(char action){
  Serial.println("button_6_action");
  if(action == 1){
    Keyboard.press(KEY_RIGHT_ALT);
    Keyboard.press(KEY_RIGHT_SHIFT);
    Keyboard.press(KEY_DOWN_ARROW);
  } else {
    Keyboard.release(KEY_RIGHT_ALT);
    Keyboard.release(KEY_RIGHT_SHIFT);
    Keyboard.release(KEY_DOWN_ARROW);
  }  
}
void button_function_7(char action){
  Serial.println("button_7_action");
  if(action == 1){
    Keyboard.press(KEY_LEFT_ARROW);
  } else {
    Keyboard.release(KEY_LEFT_ARROW);
  }  
}
void button_function_8(char action){
  Serial.println("button_8_action");
  if(action == 1){
    Keyboard.press(KEY_DOWN_ARROW);
  } else {
    Keyboard.release(KEY_DOWN_ARROW);
  }
}
void button_function_9(char action){
  Serial.println("button_9_action");
  if(action == 1){
    Keyboard.press(KEY_RIGHT_ARROW);
  } else {
    Keyboard.release(KEY_RIGHT_ARROW);
  }  
}
// Add or Remove functions as needed 

class Button {
public:
  int pin;
  int state;
  bool lastState;
  unsigned long lastDebounceTime;
  int debounceDelay;
};

constexpr int NUM_BUTTONS = sizeof(buttonPins) / sizeof(buttonPins[0]);
typedef void (*ButtonFunction)(char);
ButtonFunction buttonFunctions[NUM_BUTTONS];
Button buttons[NUM_BUTTONS];

void setup() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    buttons[i].pin = buttonPins[i];
    pinMode(buttons[i].pin, INPUT_PULLUP);
    buttons[i].lastState = HIGH;
    buttons[i].debounceDelay = 20;
    buttonFunctions[i] = default_function;
  }

  // Add or Remove functions as needed 
  buttonFunctions[0] = button_function_1;
  buttonFunctions[1] = button_function_2;
  buttonFunctions[2] = button_function_3;
  buttonFunctions[3] = button_function_4;
  buttonFunctions[4] = button_function_5;
  buttonFunctions[5] = button_function_6;
  buttonFunctions[6] = button_function_7;
  buttonFunctions[7] = button_function_8;
  buttonFunctions[8] = button_function_9;
  // Add or Remove functions as needed 

}

void loop() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    int reading = digitalRead(buttons[i].pin);
    if (reading != buttons[i].lastState) {
      buttons[i].lastDebounceTime = millis();
    }
    if ((millis() - buttons[i].lastDebounceTime) > buttons[i].debounceDelay) {
      if (reading != buttons[i].state) {
        buttons[i].state = reading;
        if (buttons[i].state == LOW) {
          buttonFunctions[i](1);
        } else {
          buttonFunctions[i](0);
        }
      }
    }
    buttons[i].lastState = reading;
  }
}

