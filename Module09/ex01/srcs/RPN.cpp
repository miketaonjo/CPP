#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

RPN::RPN(void)
{
}

RPN::~RPN(void)
{
}

static bool onlyDigits(std::string s)
{
	for (std::string::iterator it = s.begin(); it != s.end(); ++it)
	{
		while (*it == 32)
			++it;
		if (!std::isdigit(*it) && (*it != '/' && *it != '*' && *it != '-' && *it != '+'))
			return (false);
	}
	return (true);
}

static bool checkSigns(std::string s)
{
	for (std::string::iterator it = s.begin(); it != s.end(); ++it)
	{
		switch (*it)
		{
			case '+':
			case '-':
			case '*':
			case '/':
				return (true);
			default:
				break;
		}
	}
	return (false);
}

void RPN::checkInput(std::string input)
{
	std::string cpy;

	cpy.reserve(input.length());
	cpy.assign(input);

	if (!onlyDigits(cpy) || !checkSigns(input) || !isdigit(cpy[0]))
		throw std::logic_error("Incorrect RPN format");
	for (size_t i = 0; i < cpy.length(); i++)
	{
		if (isdigit(cpy[i]) || cpy[i] == 32)
		{
			int n = 0;
			while (i < cpy.length() && isdigit(cpy[i]))
			{
				n = n * 10 + (cpy[i] - 48);
				i++;
				this->_stack.push(n);
			}
		}
		else if (cpy[i] == '/' || cpy[i] == '*' || cpy[i] == '-' || cpy[i] == '+')
		{
			int j = 0;
			int result;
			int k = 0;
			j = this->_stack.top();
			this->_stack.pop();
			k = this->_stack.top();
			this->_stack.pop();
			switch (cpy[i])
			{
				case '/':
					if (j != 0)
						result = k / j;
					else
						throw std::logic_error("Cannot divide by 0");
					break;
				case '*':
					result = k * j;
					break;
				case '-':
					result = k - j;
					break;
				case '+':
					result = k + j;
					break;
				default:
					break;
			}
			this->_stack.push(result);
		}
		else
			throw std::logic_error("Incorrect RPN format");
	}
	//std::cout << this->_stack.size() << std::endl;
	std::cout << this->_stack.top() << std::endl;
}

/*
static bool checkDigits(std::string s)
{
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
            continue;
        if (s[i] < '0' || s[i] > '9')
            return (false);
		if (i != s.length() && isdigit(s[i]) && (s[i + 1] != 32 && s[i + 1] != '\0'))
			return (false);
	}
    return (true);
}

// check pour connaître le nombre total de chiffre dans la string ?
// static int countDigits(std::string s)
// {
// 	int count = 0;
// 	for (std::string::iterator it = s.begin(); it != s.end(); ++it)
// 	{
// 		if (std::isdigit(*it))
// 			++count;
// 	}
// 	return (count);
// }

static bool checkRPNFormat(std::string s)
{
	//int count = 0;

	for (size_t i = 0; i < s.length(); i++)
	{
		// check pour n'avoir toujours que 2 chiffres max pour faire une opération ?
		// if (isdigit(s[i]))
		// 	count++;
		// else if (!isdigit(s[i]) && s[i] != 32)
		// 	count = 0;
		// if (count > 2)
		// 	return (false);
		if (!isdigit(s[0]) || !isdigit(s[2]))
			return (false);
		if (i == (s.length() - 1) && isdigit(s[i]))
			return (false);
	}
	return (true);
}
*/

