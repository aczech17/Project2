#ifndef TEXT
#define TEXT
#include <utility> //pair
#include <string>
#include <vector>
typedef std::vector< std::pair <std::string, std::string> > stringPairs;//wektor par stringow
class Text
{	
	stringPairs replacementsVector;
	std::string textString;
	char separator;
	int findNextReplacement(std::string::iterator&);
	int replaceWord(std::string::iterator, std::string::iterator);
public:
	Text(stringPairs reps, const std::string txtStr = "", char sep = '*') : replacementsVector(reps), textString(txtStr), separator(sep) {}
	void replaceAllWords();
	std::string text();
};
#endif