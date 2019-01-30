#include <iostream>
#include "Executive.h"

int main(int argc, char* argv[])
{
	if (argc < 3) {
		std::cout << "\n error: miss path of loading flies or path of browser\n";
		return 1;
	}

	std::string load_path = argv[1];
	std::string browser_path = argv[2];



    std::cout << "Hello World!\n"; 
	return 0;
}
