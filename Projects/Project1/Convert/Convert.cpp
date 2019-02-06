/////////////////////////////////////////////////////////////////////
// Convert.cpp - Convert input file into html file                 //
// ver 1.0                                                         //
// Wentian Bai, CSE687 - Object Oriented Design, Spring 2019       //
/////////////////////////////////////////////////////////////////////

#include "Convert.h"

#ifdef TEST_CONVERT
int main() 
{
	Convert conv;
	conv.convert2html("../TestFiles/Proj1Helper.h", "../convertedPages/");
	std::cout << "\nfinish!!!\n\n";
}
#endif // TEST_CONVERT