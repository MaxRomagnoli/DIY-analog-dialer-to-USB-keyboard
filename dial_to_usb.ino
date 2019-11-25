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
    if (count >= 10) {
      count = 0;
    }
    Keyboard.print(String(count));
    count = 0;
  }
}
