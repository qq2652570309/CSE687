/////////////////////////////////////////////////////
// Executive.cpp - Entry point for Package Demo
// ver 1.0
// Jim Fawcett, CSE687 demo, Spring 2019
/////////////////////////////////////////////////////
/*
*  Package Responsibilities:
* ---------------------------
*  Demonstrate how to construct packages
*
*  Required Files:
* -----------------
*  Executive.cpp
*  Convert.h, Convert.cpp
*
*  Maintenance History:
* ----------------------
*  ver 1.0 : 25 Jan 2019
*  - first release
*
*/
#include "../Convert/Convert.h"
#include <iostream>

int main(int argc, char* argv[])
{
  Convert cvt;
  cvt.doConversion();
  std::cout << "\n\n";
}