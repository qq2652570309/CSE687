// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Process.h"

#ifdef TEST_TESTPROJECT
int main()
{
	Process p;
	std::string appPath =
		//"c:/windows/explorer.exe";  // path to application to start
		"c:/Program Files (x86)/Google/Chrome/Application/chrome.exe";
	p.application(appPath);

	std::cout << "\n open test.html 2 times\n";
	getchar();

	for (int i = 0; i < 2; i++) {
		std::string cmdLine = "/A ../Project1/test" + std::to_string(i) + ".html";
		p.commandLine(cmdLine);

		std::cout << "\n starting process\n";
		p.create();
		CBP callback = []() {};
		p.setCallBackProcessing(callback);
		p.registerCallback();

		WaitForSingleObject(p.getProcessHandle(), INFINITE);
	}

	return 0;
}
#endif