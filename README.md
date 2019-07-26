# StefansSimpleBluetooth
Arduino Library for simple Bluetooth communication

This library is Written in C++ for Arduino, and ment to be used with MIT App Inventor 2 for 2-way communication

The intention of this library was for use in a highschool Electronic Kart Project

Yes, I know this is badly written and all that, but it is just meant for a one-time use by me and my friend. Okay, I may use this acouple more times but that's it.

##Usage
See example sketch in `examples` subfolder

Basic commands include:
- begin: begin the library
- send & sendln: send a message to Serial

- waitingData(): returns bool if there is data to be recieved or not.
- getData(): tell the library to retrive the data and store it internally
- isData(): compare if the data stored internally in the library matches the given phrase
- clearData(): clear the data stored internally in the library

**NOTE:** This is designed to only recieve small commands, and send commands/larger data (this depends on how the other side is being handled). This library becomes very unefficient and memory-intensive if large data packet sending is attempted. Only send short commands such as "start", "stop" (or even better, one-letter commands such as "y" and "n") as per in the example!

##Contribution
Ultamitley I'd like this library to be able to accept longer messages more efficently (and at all :P), but I'm not sure if libraries like this already exist.