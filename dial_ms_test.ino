#define counterButton   3
#define openButton      4
byte count = 0;
bool lastIsOpen = true;
unsigned long ms = 0;

void setup()
{
  pinMode(counterButton, INPUT_PULLUP);
  pinMode(openButton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(openButton) == LOW) {
    if (digitalRead(counterButton) == LOW) {
      if (!lastIsOpen) {
        lastIsOpen = true;
        count++;
        ms = millis();
      }
    }
    else {
      if (lastIsOpen) {
        lastIsOpen = false;
        if (count > 0) {
          Serial.print("Count n.");
          Serial.print(count);
          Serial.print(": ");
          Serial.println(millis() - ms);
          ms = millis();
        }
      }
    }
  }
  else {
    count = 0;
    ms = millis();
  }
}
