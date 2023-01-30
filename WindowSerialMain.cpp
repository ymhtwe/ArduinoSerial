/* 
1. Check if connection with Teensy is made
2. If Teesny is connected then take input from user in a String
3. Make a char array of the size of string + 1
4. Copy the whole string into the char array
5. Add escape sequence \n because this represents the end of a line in Serial Comm port
6. Write the whole char array into the buffer (a buffer takes the info forward to the Serial Comm Port)
7. Read from the Teensy if data is received successfully or if the action is taken as per needed
*/


#include<iostream>
#include<string>
#include<stdlib.h>
#include"SerialPort.h"
using namespace std;

void sendData(void);
void receiveData(void);

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];
char port[] = "\\\\.\\COM6";                           //Change with your COM port later
SerialPort arduino(port);                              //create arduino object

int main()
{
	
	if (arduino.isConnected()) {                           
		cout << "Arduino Device Detected" << endl << endl;         //Output connection Successful
	}
	else {
		cout << "Error in port name" << endl << endl;              //Output connection error
	}
	
	/*Print Messaging Protocol*/
	cout << "< Command Descriptions >" << endl;
	cout << "scanport : Scan the available serial port of Teensy " << endl;
	cout << "device1r : Read serial port 1 of Teensy " << endl;
	cout << "device2r : Read serial port 2 of Teensy " << endl;
	cout << "device3r : Read serial port 3 of Teensy " << endl;
	cout << "device4r : Read serial port 4 of Teensy " << endl;
	cout << "device5r : Read serial port 5 of Teensy " << endl;
	cout << "device6r : Read serial port 6 of Teensy " << endl;
	cout << "device7r : Read serial port 7 of Teensy " << endl;
	cout << "devicear : Read all serial ports of Teensy " << endl;
	cout << "device1w_ledon  : Turn On LED   " << endl;
	cout << "device1w_ledoff : Turn Off LED  " << endl;
	

	while (arduino.isConnected()) {
		
		cout << "Enter your command: " ;
		sendData();
		Sleep(1000);
		receiveData();

	}
	return 0;
}

void sendData(void) {
	/*Send data to USB serial port(arduino)*/
	string data;
	cin >> data;                                         //Store incoming data from window terminal

	/*Create stop bits, end of line charater. '\n' */
	char* charArray = new char[data.size() + 1];         //Create CharArray  
	copy(data.begin(), data.end(), charArray);           //Copy all from data to CharArray
	charArray[data.size()] = '\n';                       //Put '\n' at the end of charArray 
	arduino.writeSerialPort(charArray, MAX_DATA_LENGTH); //Write to serial port
	cout << endl;                                        //Line Feed
	cout << "Command Sent" << endl;                      //Output feedback

	delete[] charArray;                                  //Clear charArray
}
void receiveData(void) {
	/* Receive data from USB serial port (arduino) */
	arduino.readSerialPort(output, MAX_DATA_LENGTH);     //Store incoming data
	Sleep(1000);										 //1 sec delay
	cout << ">> " << output << endl;                     //Output incoming data
	for (int i = 0; i < MAX_DATA_LENGTH; i++)            //Clear output 
	{ 
		output[i] = 0; 
	}
	
}

