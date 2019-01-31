#include <iostream>
#include "Executive.h"

int main(int argc, char* argv[])
{
	if (argc < 4) {
		std::cout << "\n error: miss path of loading flies or path of browser\n";
		return 1;
	}

	std::string pattern = argv[1];
	std::string load_path = argv[2];
	std::string browser_path = argv[3];

	// using DirExploreN to find all target files with their paths
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

    
	return 0;
}
