template <typename T>
Array<T>::Array(void)
{
	this->len = 0;
	this->array = NULL;
}

template <typename T>
Array<T>::Array(unsigned int i)
{
	this->len = i;
	this->array = new T[i];
}

template <typename T>
Array<T>::Array(Array<T> const &obj)
{
	this->len = obj.size();
	this->array = new T[this->len];
	for(unsigned int i = 0; i < len; i++)
		this->array[i] = obj[i];
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> const &obj)
{
	if (this != &obj)
	{
		this->len = obj.size();
		for (unsigned int i = 0; i < len; i++)
			delete this->array[i];
		this->array = NULL;
		this->array = new T[this->len];
		for (unsigned int i = 0; i < len; i++)
			this->array[i] = obj[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] this->array;
	this->array = NULL;
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (this->len);
}

template <typename T>
T& Array<T>::operator[](unsigned int i) const
{
	if (i >= this->len)
		throw std::out_of_range("Over the array size");
	return (array[i]);
}
