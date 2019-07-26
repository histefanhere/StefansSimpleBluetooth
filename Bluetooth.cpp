/*
    Bluetooth.h - Library for simple bluetooth communication.
    Made specifically for Electric Vechile Project *eveloctiy*
    Created by Stefan Zdravkovic, July 25, 2019.
*/

#include "Arduino.h"
#include "Bluetooth.h"

Bluetooth::Bluetooth()
{
//    Serial.begin(9600);
  return;
}

void Bluetooth::begin() {
  Serial.begin(9600);
}

void Bluetooth::send(String message)
{
  Serial.print(message);
}

void Bluetooth::sendln(String message) {
  Serial.println(message);
}
void Bluetooth::sendln(int message) {
  Serial.println(message);
}

bool Bluetooth::waitingData()
{
  if (Serial.available() > 0) {
    return true;
  }
  else
  {
    return false;
  }
}

void Bluetooth::getData()
{
  if (Serial.available() > 0) {
    data[15];
    byte i = 0;
    while (Serial.available() > 0) {
      // character is the read character, and we need to make sure that it's valid and not some random ASCII symbol.
      char character = Serial.read();
      data[i] = character;
      i++;

      // pretty much just ensures that all the data has been sent, and that some lonely character isn't being left out
      delay(3);
    }
    data[i] = '\0';
  }
}

bool Bluetooth::isData(char message[])
{
  if (!strcmp(data, message)) {
    return true;
  }
  else {
    return false;
  }
}

void Bluetooth::clearData()
{
  data[0] = (char)0;
}
