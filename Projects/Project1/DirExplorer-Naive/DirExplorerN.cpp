/////////////////////////////////////////////////////////////////////
// DirExplorerN.cpp - Naive directory explorer                     //
// ver 1.2                                                         //
// Jim Fawcett, CSE687 - Object Oriented Design, Fall 2018         //
/////////////////////////////////////////////////////////////////////

#ifdef TEST_DIREXPLORERN  // only compile the following when defined

#include "DirExplorerN.h"
#include "StringUtilities.h"
#include "CodeUtilities.h"

using namespace Utilities;
using namespace FileSystem;

int main(int argc, char *argv[])
{
  Title("Demonstrate DirExplorer-Naive, " + DirExplorerN::version());

  ProcessCmdLine pcl(argc, argv);

  if (pcl.parseError())
  {
    pcl.usage();
    std::cout << "\n\n";
    return 1;
  }

  DirExplorerN de(pcl.path());
  for (auto patt : pcl.patterns())
  {
    de.addPattern(patt);
  }

  if (pcl.hasOption('s'))
  {
    de.recurse();
  }

  de.search();
  de.showStats();

  std::vector<std::string> targetFiles = de.getTargetFiles();
  std::cout << "\n\n all target files:\n";
  auto it = targetFiles.begin();
  while (it != targetFiles.end()) {
	  std::cout << *it << "\n";
	  it++;
  }

  std::cout << "\n\n";
  return 0;
}

#endif