#include <iostream>
#include <iterator>
#include <string>
#include <regex>

void reg_overview()
{
	std::string s = "Some people, when confronted with a problem, think "
		"\"I know, I'll use regular expressions.\" "
		"Now they have two problems.";

	std::regex self_regex("REGULAR EXPRESSIONS",
		std::regex_constants::ECMAScript | std::regex_constants::icase);
	if (std::regex_search(s, self_regex)) {
		std::cout << "Text contains the phrase 'regular expressions'\n";
	}

	getchar();


	std::regex word_regex("(\\S+)");
	auto words_begin =
		std::sregex_iterator(s.begin(), s.end(), word_regex);
	auto words_end = std::sregex_iterator();

	std::cout << "Found "
		<< std::distance(words_begin, words_end)
		<< " words\n";

	getchar();

	const int N = 6;
	std::cout << "Words longer than " << N << " characters:\n";
	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
		std::smatch match = *i;
		std::string match_str = match.str();
		if (match_str.size() > N) {
			std::cout << "  " << match_str << '\n';
		}
	}

	getchar();

	std::regex long_word_regex("(\\w{7,})");
	std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
	std::cout << new_s << '\n';
}

void reg_iterator() {
	std::string s("this subject has a submarine as a subsequence");
	std::regex e("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

	std::regex_iterator<std::string::iterator> rit(s.begin(), s.end(), e);
	std::regex_iterator<std::string::iterator> rend;

	while (rit != rend) {
		std::cout << rit->str() << std::endl;
		++rit;
	}
}

void reg_match() {
	// Simple regular expression matching
	std::string fnames[] = { "foo.txt", "bar.txt", "baz.dat", "zoidberg" };
	std::regex txt_regex("[a-z]+\\.txt");

	for (const auto &fname : fnames) {
		std::cout << fname << ": " << std::regex_match(fname, txt_regex) << '\n';
	}
	getchar();

	// Extraction of a sub-match
	std::regex base_regex("([a-z]+)\\.txt");
	std::smatch base_match;

	for (const auto &fname : fnames) {
		if (std::regex_match(fname, base_match, base_regex)) {
			// The first sub_match is the whole string; the next
			// sub_match is the first parenthesized expression.
			if (base_match.size() == 2) {
				std::ssub_match base_sub_match = base_match[1];
				std::string base = base_sub_match.str();
				std::cout << fname << " has a base of " << base << '\n';
			}
		}
	}
	getchar();

	// Extraction of several sub-matches
	std::regex pieces_regex("([a-z]+)\\.([a-z]+)");
	std::smatch pieces_match;

	for (const auto &fname : fnames) {
		if (std::regex_match(fname, pieces_match, pieces_regex)) {
			std::cout << fname << '\n';
			for (size_t i = 0; i < pieces_match.size(); ++i) {
				std::ssub_match sub_match = pieces_match[i];
				std::string piece = sub_match.str();
				std::cout << "  submatch " << i << ": " << piece << '\n';
			}
		}
	}
}

void reg_test() {
	std::string fnames[] = {
		"test.cpp", "test.h", "test01.cpp", "test01.h", "TesT2.cpp", "TesT2.h",
		"tes_t_3.cpp", "tes_t_3.h",
		"baz.dat", "zoidberg" };
	std::regex file_regex("([a-zA-Z]|\\d|\\_)+\\.(cpp|h)");
	std::smatch file_match;

	for (const auto &fname : fnames) {
		if (std::regex_match(fname, file_match, file_regex)) {
			std::ssub_match file_sub_match = file_match[0];
			std::string file = file_sub_match.str();
			std::cout << file << "\n";
		}
	}
}

void fileFilter(std::vector<std::string> &fnames) {
	std::regex file_regex("([a-zA-Z]|\\d|\\_)+\\.(cpp|h)");
	std::smatch file_match;

	int size = fnames.size();
	for (int i = 0; i < size; i++) {
		std::string fname = fnames[i];
		if (!std::regex_match(fname, file_match, file_regex)) {
			std::cout << fname << "\n";
			/*fnames.erase(fnames.begin() + i);
			i--;*/
		}
	}
}

int main(int argc, char *argv[]) {
	//reg_iterator();
	//reg_overview();
	//reg_match();
	//reg_test();

	std::vector<std::string> fnames(argv, argv + argc);
	std::cout << "before filter\n";
	fileFilter(fnames);
	std::cout << "\n" << "after filter\n";
	for (const auto &fname : fnames) {
		std::cout << fname << "\n";
	}

	getchar();
	return 0;
}