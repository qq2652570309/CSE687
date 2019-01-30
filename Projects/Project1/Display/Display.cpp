// Display.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Display.h"

#ifdef TEST_TESTPROJECT
int main()
{
	Display player("c:/Program Files (x86)/Google/Chrome/Application/chrome.exe");
	for (int i = 0; i < 3; i++) {
		player.showHtml("c:/Users/wentian/Desktop/EDU687/Projects/Project1/convertedPages/Proj1Helper.h.html");
	}
	return 0;
}
#endif // TEST_TESTPROJECT
