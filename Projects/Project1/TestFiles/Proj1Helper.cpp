/////////////////////////////////////////////////////////////////////
// Proj1Helper.cpp - will become webified                          //
//                                                                 //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2019       //
/////////////////////////////////////////////////////////////////////

#include "Proj1Helper.h"

X::X() 
{ 
  str_ = ""; 
}

X::X(const std::string& str) : str_(str) 
{
}

std::string X::str()
{
  return str_;
}

#include <iostream>

int main()
{
  std::cout << "\n  Class to be Webified";
  std::cout << "\n ----------------------";

  X x("instance of X here");
  std::cout << "\n  " << x.str();
  std::cout << "\n\n";
}
