///////////////////////////////////////////////////////////////////////
// Display.cpp - class used to display html in browser               //
// ver 1.0                                                           //
// Wentian Bai, CSE687 - Object Oriented Design, Spring 2019         //
///////////////////////////////////////////////////////////////////////

#include "Display.h"

#ifdef TEST_DISPLAY
int main()
{
	Display player;
	player.setBrowser("c:/Program Files (x86)/Google/Chrome/Application/chrome.exe");
	for (int i = 0; i < 2; i++) {
		player.showHtml(" convertedPages/Proj1Helper.h.html");
	}
	return 0;
}
#endif // TEST_DISPLAY
