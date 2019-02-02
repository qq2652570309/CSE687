///////////////////////////////////////////////////////////////////////
// Executive.cpp - class used to execute all operations in project1  //
// ver 1.0                                                           //
// Wentian Bai, CSE687 - Object Oriented Design, Spring 2019         //
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Executive.h"

#ifdef TEST_EXECUTIVE
int main(int argc, char* argv[])
{
	try
	{
		std::string htmlFolder = "../convertedPages/";
		Executive exe(argc, argv);

		exe.convertFiles(htmlFolder);

		std::cout << "\n  Will start browser to open all html files and each time wait for termination.";
		std::cout << "\n  You need to kill each window (upper right button) to continue.";
		std::cout << "\n  Press key to start";
		getchar();
		exe.displayHtml(htmlFolder);

		std::cout <<std::endl << "Press key to exist";
		getchar();

		return 0;
	}
	catch (const std::exception& e)
	{
		std::cout << "execption caught\n\n" << e.what();
		return 1;
	}
	catch (...)
	{
		std::cout << "unknown exception\n\n";
		return 1;
	}
}
#endif // TEST_EXECUTIVE
