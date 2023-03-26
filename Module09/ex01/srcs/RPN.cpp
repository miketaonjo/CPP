#include "RPN.hpp"

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

static bool checkFormat(std::string s)
{
	int count_nb = 0;
	int signs = 0;

	for (size_t i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]))
			count_nb++;
		if (count_nb == 1 && (s[i] == '/' || s[i] == '*' || s[i] == '-' || s[i] == '+'))
		 	return (false);
		else if (s[i] == '/' || s[i] == '*' || s[i] == '-' || s[i] == '+')
		{
			while ((s[i] == '/' || s[i] == '*' || s[i] == '-' || s[i] == '+') || s[i] == 32)
			{
				if (s[i] == '/' || s[i] == '*' || s[i] == '-' || s[i] == '+') 
					signs++;
				if (isdigit(s[i + 1]))
					break;
				i++;
			}
			if (signs != count_nb - 1)
				return (false);
		}
	}
	if (signs != count_nb - 1)
		return (false);
	return (true);
}

void RPN::checkInput(std::string input)
{
	std::string cpy;

	cpy.reserve(input.length());
	cpy.assign(input);

	if (!onlyDigits(cpy) || !checkSigns(input) || !isdigit(cpy[0]) || !checkFormat(cpy))
		throw std::logic_error("Incorrect RPN format");
	for (size_t i = 0; i < cpy.length(); i++)
	{
		if ((isdigit(cpy[i]) && cpy[i + 1] == 32) || cpy[i] == 32)
		{
			int n = 0;
			if (isdigit(cpy[i]))
			{
				n = n * 10 + (cpy[i] - 48);
				this->_stack.push(n);
			}
		}
		else if ((isdigit(cpy[i]) && cpy[i + 1] != 32)
				|| ((cpy[i] == '/' || cpy[i] == '*' || cpy[i] == '-' || cpy[i] == '+')
				&& cpy[i + 1] != 32 && cpy[i + 1] != '\0'))
			throw std::logic_error("Incorrect RPN format");
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
