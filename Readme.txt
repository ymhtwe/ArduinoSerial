/* Serial communication between Teensy4.0(Arduino) and window terminal(C++ on visual studio) */

>> .ino file to be compiled in Arduino IDE and sent to Teensy.
  	- Forward messages from PC to dedicated serial port
  	- Fetch messages from serial ports, merge and sent to PC
  	- Control/configure serial ports according to PC input

>> C++ file to be executed on a PC.
  	- Send messages to Teensy to control/configure serial ports
  	- Send messages to Teensy to be forwarded to dedicated serial port
  	- Split received messages from Teensy into original messages received from serial
    	  ports


>> C++ program was developed on visual studio 2022 with the following program flow
	
	1. Check if connection with Teensy is made
	2. If Teesny is connected then take input from user in a String
	3. Make a char array of the size of string + 1
	4. Copy the whole string into the char array
	5. Add escape sequence \n because this represents the end of a line in Serial Comm port
	6. Write the whole char array into the buffer (a buffer takes the info forward to the Serial Comm Port)
	7. Read from the Teensy if data is received successfully or if the action is taken as per needed

>> Default BAUD rate is 115200 and can change as you want
	