#include <iostream>
#include <map>

bool isValid(std::string s)
{
	int openP = 0;
	int closeP = 0;
	int openS = 0;
	int closeS = 0;
	int openC = 0;
	int closeC = 0;
	
	for (char c : s) {
		switch (c) {
		case '(' :
			openP++;
			break;
		case ')' :
			closeP++;
			break;
		case '[' :
			openS++;
			break;
		case ']' :
			closeS++;
			break;
		case '{' :
			openC++;
			break;
		case '}' :
			closeC++;
			break;
		}
	}

	if (openP != closeP || openS != closeS || openC != closeC) {
		return false;
	}

	if (openP + closeP + openS + closeS + openC + closeC == 0) {
		return false;
	}

	char last;
	for (char c : s) {
		if (last == '(' && (c == ']' || c == '}'))
			return false;
		if (last == '[' && (c == ')' || c == '}'))
			return false;
		if (last == '{' && (c == ']' || c == ')'))
			return false;
		last = c;
	}

	return true;
}

int main()
{
	//checking some cases
	if (isValid(""))
		std::cout << "null string: true" << std::endl;
	else
		std::cout << "null string: false" << std::endl;
	
	if (isValid("()[]{}"))
		std::cout << "()[]{}: true" << std::endl;
	else
		std::cout << "()[]{}: false" << std::endl;

	if (isValid("("))
		std::cout << "(: true" << std::endl;
	else
		std::cout << "(: false" << std::endl;

	if (isValid("({})"))
		std::cout << "({}): true" << std::endl;
	else
		std::cout << "({}): false" << std::endl;

	if (isValid("([)]"))
		std::cout << "([)]: true" << std::endl;
	else
		std::cout << "([)]: false" << std::endl;
}