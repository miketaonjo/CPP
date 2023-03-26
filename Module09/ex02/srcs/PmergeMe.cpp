#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe(void)
{
}

static bool checkDigits(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (!isdigit(s[i]))
			return (false);
		i++;
	}
	if (i == 0)
		return (false);
	return (true);
}

template <typename T>
static typename T::iterator findMid(T& container)
{
	typename T::iterator mid = container.begin();
	std::advance(mid, container.size() / 2);
	--mid;
	return (mid);
}

template <typename T>
static int findSize(T& container)
{
	int i = 0;
	typename T::iterator it;
    for (it = container.begin(); it != container.end(); ++it)
		i++;
	i++;
	return (i);
}

template <typename T>
static void insertSort(T& container)
{
	typename T::iterator	it1,
							it2,
							key;
    for (it1 = container.begin() + 1; it1 != container.end(); ++it1)
	{
		key = it1;
		it2 = it1 - 1;
		while (it2 >= container.begin() && *it2 > *key)
		{
			std::swap(*it2, *key);
			key--;
			it2--;
		}
	}
}

template <typename T>
static void mergeSort(T& container, T& container1, T& container2)
{
	int size1 = findSize(container1);
	int size2 = findSize(container2);
	typename T::iterator 	it1 = container1.begin(),
							it2 = container2.begin();

	while (size1 > 0 && it1 != container1.end())
	{
		while (size2 > 0 && it2 != container2.end())
		{
			if (*it1 > *it2)
			{
				if (it2 != container2.end())
					container.push_back(*it2);
				if (++it2 != container2.end())
					size2--;
				else
				{
					while (it1 != container1.end())
					{
						container.push_back(*it1);
						it1++;
					}
				}
			}
			else
			{
				if (it1 != container1.end())
					container.push_back(*it1);
				if (++it1 != container1.end())
					size1--;
				else
				{
					while (it2 != container2.end())
					{
						container.push_back(*it2);
						it2++;
					}
				}
			}
		}
	}
}

static void printSequence(std::vector<int> &container, char c)
{
	if (c == 'b')
	{
		std::cout << "Before: ";
		std::vector<int>::iterator be;
    	for (be = container.begin(); be != container.end(); ++be)
			std::cout << *be << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "After: ";
		std::vector<int>::iterator af;
		for (af = container.begin(); af < container.end(); ++af)
			std::cout << *af << " ";
		std::cout << std::endl;
	}
}

template <typename T>
static void startSort(T& container)
{
	if (container.size() > 10)
	{
		typename T::iterator	first = container.begin(),
								last = container.end(),
								mid = findMid(container);

		T container1(first, ++mid);
		T container2(mid, last);
		startSort(container1);
		startSort(container2);

		container.clear();
		mergeSort(container, container1, container2);
	}
	else
		insertSort(container);
}

void PmergeMe::sortingSequence(std::deque<int> &container)
{
	struct timeval d1;
	if (gettimeofday(&d1, NULL) == -1)
		throw std::runtime_error("Error gettimeofday");
	
	startSort(container);
	
	struct timeval d2;
  	if (gettimeofday(&d2, NULL) == -1)
		throw std::runtime_error("Error gettimeofday");
	double time = (d2.tv_sec - d1.tv_sec) * 1000.0 + (d2.tv_usec - d1.tv_usec) / 1000.0;
	std::cout << "Time to process a range of " << container.size() << " elements with std::deque : " << time << " ms" << std::endl;
}

void PmergeMe::sortingSequence(std::vector<int> &container)
{	
	struct timeval v1;
	if (gettimeofday(&v1, NULL) == -1)
		throw std::runtime_error("Error gettimeofday");
	printSequence(container, 'b');
	
	startSort(container);
	
	printSequence(container, 'a');
	struct timeval v2;
  	if (gettimeofday(&v2, NULL) == -1)
		throw std::runtime_error("Error gettimeofday");
	double time = (v2.tv_sec - v1.tv_sec) * 1000.0 + (v2.tv_usec - v1.tv_usec) / 1000.0;
	std::cout << "Time to process a range of " << container.size() << " elements with std::vector : " << time << " ms" << std::endl;
}

void PmergeMe::checkArgs(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (!checkDigits(argv[i]))
		{
			std::cout << "Error : Invalid integer value" << std::endl;
			return ;
		}
	}
	for (int i = 1; i < argc; ++i)
	{	
        long n = strtol(argv[i], NULL, 10);
        if (n < 0 || n > std::numeric_limits<int>::max())
		{
            std::cout << "Error : Invalid integer value" << std::endl;
            return ;
        }
        _vsequence.push_back(n);
        _dsequence.push_back(n);
	}
	sortingSequence(_vsequence);
	sortingSequence(_dsequence);
}
