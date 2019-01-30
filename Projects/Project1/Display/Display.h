#pragma once
#include <vector>
#include <string>
#include "Process.h"

class Display
{
public:
	Display(std::string appPath);
	~Display() {};
	void showHtml(std::string file);
private:
	Process processor;
};

Display::Display(std::string appPath) {
	processor.application(appPath);
}

void Display::showHtml(std::string file) {
	std::string cmdLine = "/A " + file;
	processor.commandLine(cmdLine);

	std::cout << "\n starting process\n";
	processor.create();
	CBP callback = []() {
		std::cout << "\n  --- child process exited with this message ---";
	};
	processor.setCallBackProcessing(callback);
	processor.registerCallback();

	WaitForSingleObject(processor.getProcessHandle(), INFINITE);
}