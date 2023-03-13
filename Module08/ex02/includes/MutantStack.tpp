template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &obj) : std::stack<T>(obj)
{
	(void)obj;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &obj)
{
	(void)obj;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}
