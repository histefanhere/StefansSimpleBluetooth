/*
    Bluetooth.h - Library for simple bluetooth communication.
    Made specifically for Electric Vechile Project *eveloctiy*
    Created by Stefan Zdravkovic, July 25, 2019.
*/

#ifndef Bluetooth_h
#define Bluetooth_h

#include "Arduino.h"

class Bluetooth
{
  public:
    Bluetooth();
    void begin();

    void send(String message);
    void sendln(String message);
    void sendln(int message);

    bool waitingData();
    void getData();
    bool isData(char message[]);
    void clearData();

  private:
    char data[15];
};

#endif
