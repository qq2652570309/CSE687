// Display.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Display.h"

#ifdef TEST_TESTPROJECT
int main()
{
	Display player("c:/Program Files (x86)/Google/Chrome/Application/chrome.exe");
	player.showHtml(" --new-window c:/Users/wbai1/OneDrive/Desktop/CSE687/Projects/Project1/Display/test.html");
	return 0;
}
#endif // TEST_TESTPROJECT
