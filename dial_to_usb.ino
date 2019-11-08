#include "Keyboard.h"

#define counterButton   3
#define openButton      4
byte count = 0;
bool lastIsOpen = true;

void setup()
{
  pinMode(counterButton, INPUT_PULLUP);
  pinMode(openButton, INPUT_PULLUP);
  Keyboard.begin();
}

void loop()
{
  if (digitalRead(openButton) == LOW) {
    if (digitalRead(counterButton) == LOW) {
      if (!lastIsOpen) {
        lastIsOpen = true;
        count++;
        delay(10);
      }
    }
    else {
      lastIsOpen = false;
    }
  }
  else if (count > 0) {
    if (count == 1) {
      Keyboard.print('1');
    }
    else if (count == 2) {
      Keyboard.print('2');
    }
    else if (count == 3) {
      Keyboard.print('3');
    }
    else if (count == 4) {
      Keyboard.print('4');
    }
    else if (count == 5) {
      Keyboard.print('5');
    }
    else if (count == 6) {
      Keyboard.print('6');
    }
    else if (count == 7) {
      Keyboard.print('7');
    }
    else if (count == 8) {
      Keyboard.print('8');
    }
    else if (count == 9) {
      Keyboard.print('9');
    }
    else if (count == 10) {
      Keyboard.print('0');
    }
    count = 0;
  }
}
