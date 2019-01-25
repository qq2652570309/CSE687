#include <iostream>
#include <vector>
#include "../Convert/Converter.h"
#include "../Display/Display.h"

#ifdef TEST_TESTPROJECT
int main()
{
	std::vector<std::string> sourceFiles;
	sourceFiles.push_back("../Project1/Proj1Helper.h");
	//sourceFiles.push_back("../Project1/Proj1Helper.cpp");
	//sourceFiles.push_back("../Project1/Project1.cpp");
	sourceFiles.push_back("C:\\Users\\wbai1\\OneDrive\\Desktop\\CSE687\\Projects\\Project1\\Convert.cpp");



	Converter conv;
	Display player;

	std::vector <std::string> htmlFiles;
	std::string htmlFolder_path = "../convertedPages";

	for (std::string file : sourceFiles) {
		std::size_t found = file.rfind("/");
		std::string fileName = file.substr(found);
		std::string htmlFile = htmlFolder_path + fileName + ".html";

		conv.convert2html(file, htmlFile);
		htmlFiles.push_back(htmlFile);
	}

	for (std::string file : htmlFiles) {
		player.showHtml(file);
	}

	std::cout << "success " << "and " << "finish!!!\n";

	return 0;
}
#endif