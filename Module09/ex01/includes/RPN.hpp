#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <fstream>
#include <sstream>
#include <exception>

class RPN
{
	public:
		RPN(void);
		~RPN(void);
		void checkInput(std::string input);

	private:
		RPN(RPN const &obj);
		RPN& operator=(RPN const &obj);
		std::stack<int> _stack;
};

#endif
