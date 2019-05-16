#include "text.h"
std::string Text::text()
{
	return textString;
}

void Text::replaceAllWords()
{
	std::string::iterator It = textString.begin();
	while (It != textString.end())
	{
		int shift = findNextReplacement(It);
		It += shift ;
	}
}

int Text::findNextReplacement(std::string::iterator& repBegin)
{
	std::string::iterator repEnd = repBegin;
	while (repBegin != textString.end() && *repBegin != separator)
	{
		repBegin++;
		repEnd++;
	}
	if (repBegin == textString.end())
		return 0;
	repEnd++;
	while (*repEnd != separator)
	{
		repEnd++;
	}
	//*slowo do zastapienia*
	//^                    ^
	//|                    |
	//b                    e
	return replaceWord(repBegin, repEnd);
}

int Text::replaceWord(std::string::iterator repBegin, std::string::iterator repEnd)
{
	std::string wordToBeReplaced = "";
	for (std::string::iterator i = repBegin + 1; i != repEnd; i++)
	{
		wordToBeReplaced = wordToBeReplaced + (*i);
	}

	std::string wordToReplace;
	
	for (stringPairs::iterator i = replacementsVector.begin(); i != replacementsVector.end(); i++)
	{
		std::pair<std::string, std::string> replacementPair = *i;
		if (replacementPair.first == wordToBeReplaced)
		{
			wordToReplace = replacementPair.second;
			break;
		}//if
	}//for
	//mamy wordToBeReplaced i wordToReplace
	textString.replace(repBegin, repEnd+1, wordToReplace);
	return wordToReplace.size();
}