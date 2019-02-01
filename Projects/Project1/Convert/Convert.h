#pragma once
/////////////////////////////////////////////////////////////////////
// Convert.h - Convert input file into html file                   //
// ver 1.0                                                         //
// Wentian Bai, CSE687 - Object Oriented Design, Spring 2019       //
/////////////////////////////////////////////////////////////////////
/*
 * Package Operations:
 * -------------------
 * Convert provides a class, of the same name, whose convert2html function
 * reads content of input file and insertElem function adds these content
 * into a html file.
 *
 * Required Files:
 * ---------------
 * Convert.h, Convert.cpp
 *
 * Maintenance History:
 * --------------------
 * ver 1.0 : 31 Jan 2019
 * - first release
 *
*/

#include <fstream>
#include <regex>
#include <string>
#include <iostream>

class Convert
{
public:
	Convert() {}
	~Convert() {}
	void convert2html(std::string input_path, std::string output_path);
};

// insert <h3> and <pre> elememt and converting content
void insertElem(std::ofstream &html, std::ifstream &source) {
	std::string line;

	html << "<h3>";
	html << "Project #1";
	html << "</h3>";

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

// get file name from full file path
std::string fileName(std::string filePath) {
	std::size_t found = filePath.find_last_of("/\\");
	return filePath.substr(found + 1);
}

//----< convert target file into html file >---------------------------
void Convert::convert2html(std::string input, std::string output) {
	std::string fName = fileName(input);
	std::ifstream emptyHtml("../Convert/empty.html");
	std::ifstream sourceFile(input);
	std::ofstream htmlFile(output + fName + ".html");
	std::string line;

	std::regex body_regex("\\s*<body>");
	std::smatch body_match;

	if (emptyHtml.is_open() && sourceFile.is_open()) {
		while (getline(emptyHtml, line)) {
			htmlFile << line << "\n";
			if (std::regex_match(line, body_match, body_regex)) {
				insertElem(htmlFile, sourceFile);
			}
		}
		emptyHtml.close();
		sourceFile.close();
		htmlFile.close();
	}
	else {
		std::cout << "\n error: Unable to open file!!!\n";
	}
}

