/////////////////////////////////////////////////////////////////
// ReadFiles.cpp - demonstrate robust file access              //
//                                                             //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2012   //
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

//----< read a specified number of lines from file >-----------------

bool ReadFileLines(const std::string& filename, size_t numLines)
{
  std::ifstream in;
  in.open(filename.c_str());

  // test for open failure
  if(!in.good())
  {
    std::cout << "\n  can't open file " << filename.c_str() << "\n\n";
    return false;
  }
  // test succeeded so use file
  else
  {
    for(size_t j=0; j<numLines; ++j)
    {
      const size_t BuffSize = 256;
      static char buffer[BuffSize];
      in.getline(buffer,BuffSize);
      std::cout << buffer << "\n";
    }
  }
  return true;
}
//----< test >-------------------------------------------------------

int main(int argc, char* argv[])
{
  std::cout << "\n  Demonstrating Robust File Access";
  std::cout << "\n ==================================\n";

  // read relative paths specified in code

  if(!ReadFileLines("./doesNotExist",10))
    std::cout << "  ReadFileLines failed\n\n";
  else
    std::cout << "\n  ReadFileLines succeeded\n\n";
  if(!ReadFileLines("./ReadFiles.cpp",10))
    std::cout << "\n  ReadFileLines failed\n\n";
  else
    std::cout << "\n  ReadFileLines succeeded\n\n";
  
  // read relative path specified on command line

  if(argc > 1)
  {
    try
    {
      for(int i=1; i<argc; ++i)
      {
        std::cout << "\n  commandline argument = \"" << argv[i] << "\"\n\n";
        ReadFileLines(argv[i],10);
      }
    }
    catch(std::exception& ex)
    {
      std::cout << "\n\n  " << ex.what() << "\n\n";
    }
    std::cout << "\n\n";
  }
  return 0;
}