#include <iostream>
#include "Converter.h"

#ifdef TEST_TESTCONVERT
int main()
{
	Converter conv;
	conv.convert2html("../Convert/Converter.cpp", "../Convert/Converter");
	return 0;
}
#endif