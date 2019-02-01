#pragma once
///////////////////////////////////////////////////////////////////////
// Display.h - class used to display html in browser                 //
// ver 1.0                                                           //
// Wentian Bai, CSE687 - Object Oriented Design, Spring 2019         //
///////////////////////////////////////////////////////////////////////
/*
*  Package Operations:
*  -------------------
* This package provides a class, Display, used to open html file and show
* it in target browser.
*
*  Required Files:
*  ---------------
*  Display.h, Display.cpp
*  Process.h
*
*  Maintenance History:
*  --------------------
*  ver 1.0 : 31 Jan 2019
*  - first release
*/

#include <vector>
#include <string>
#include "Process.h"

class Display
{
public:
	Display() {};
	~Display() {};
	void setBrowser(std::string file);
	void showHtml(std::string file);
private:
	Process processor;
};

// add target browser into processor class
void Display::setBrowser(std::string app) {
	processor.application(app);
}

// open target html file and show it in broswer
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