// bt_count:
// Example sketch for StefansSimpleBluetooth
// Written in C++ for Arduino, ment for use with MIT App Inventor 2
// Made for use in Electronic Kart Project

#include "Bluetooth.h"

Bluetooth bt;

bool count = false;
int i = 0;

void setup() {
  // Initialize bluetooth communication (this will also initalize Serial, so doing this manually is unneccesarry)
  bt.begin();

  bt.sendln("Example Commands:");
  bt.sendln("start - start the counter");
  bt.sendln("stop - stop the counter");
  bt.sendln("reset - reset the counter to 0");
}

void loop() {
    // Check if any data is waiting to be recieved
  if (bt.waitingData()) {
    
    // Tell the library to get the data that has been sent to this Arduino
    bt.getData();

    // Find out what that data is and carry out the corresponding command
    if (bt.isData("start")) {
      bt.sendln("starting counter");
      count = true;
    }
    else if (bt.isData("stop")) {
      bt.sendln("stopped counter");
      count = false;
    }
    else if (bt.isData("reset")) {
      bt.sendln("reset counter to 0!");
      i = 0;
    }
    
    // If it exists, clear the stored data. not strictly neccessary, but will help
    bt.clearData();
  }

  // Count!
  if (count) {
    bt.sendln(i);
    i += 1;
    delay(1000);
  }
}