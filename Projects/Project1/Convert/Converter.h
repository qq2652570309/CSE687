#include <fstream>
#include <regex>
#include <string>

class Converter
{
public:
	Converter() {}
	~Converter() {}
	void convert2html(std::string input_path, std::string output_path);
};

//----< insert <pre></pre> elememt and converting content >------------
void insertPreElem(std::ofstream &html, std::ifstream &source) {
	std::string line;

	html << "<pre>\n";
	while (getline(source, line)) {
		for (char c : line) {
			switch (c) {
				case '<':
					html << "&lt";
					break;
				case '>':
					html << "&gt";
					break;
				default:
					html << c;
					break;
			}
		}
		html << "\n";
	}
	html << "</pre>\n";
}

//----< convert target file into html file >---------------------------
void Converter::convert2html(std::string input, std::string output) {
	std::string line;
	std::ifstream emptyHtml("../Convert/empty.html");
	std::ifstream sourceFile(input);
	std::ofstream htmlFile(output);

	std::regex body_regex("\\s*<body>");
	std::smatch body_match;

	if (emptyHtml.is_open()) {
		while (getline(emptyHtml, line)) {
			htmlFile << line << "\n";
			if (std::regex_match(line, body_match, body_regex)) {
				insertPreElem(htmlFile, sourceFile);
			}
		}
		emptyHtml.close();
	}
	else {
		std::cout << "Unable to open file";
	}
}

