#pragma once
#include <vector>
#include <string>
#include "../Process/Process.h"

class Display
{
public:
	Display();
	~Display() {};
	void showHtml(std::string file);
private:
	Process processor;
};

Display::Display() {
	std::string appPath =
		"c:/Program Files (x86)/Google/Chrome/Application/chrome.exe";
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