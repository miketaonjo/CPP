#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <limits>
# include <cstdlib>
# include <sys/time.h>

class PmergeMe
{
	public:
		PmergeMe(void);
		~PmergeMe(void);

		void checkArgs(int argc, char **args);
		void sortingSequence(std::vector<int> &container);
		void sortingSequence(std::deque<int> &container);

	private:
		PmergeMe(PmergeMe const &obj);
		PmergeMe& operator=(PmergeMe const &obj);
		std::vector<int> _vsequence;
		std::deque<int> _dsequence;
};

#endif
