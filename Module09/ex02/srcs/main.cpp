#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error : Not enough argument" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe sort;
		sort.checkArgs(argc, argv);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
	return (0);
}
