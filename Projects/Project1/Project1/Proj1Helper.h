#pragma once
/////////////////////////////////////////////////////////////////////
// Proj1Helper.h  - will become webified                           //
//                                                                 //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2019       //
/////////////////////////////////////////////////////////////////////

#include <string>

class X {
public:
  X();
  X(const std::string& str);
  std::string str();
private:
  std::string str_;
};