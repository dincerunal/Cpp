#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>
#include <cstdlib>
#include <cstring>

template <typename T, size_t SIZE = 10>
class Array {
public:	
	size_t GetSize() const { return SIZE; }
	T &operator [](size_t index);
	const T &operator [](size_t index) const;
private:
	static void controlBounds(const char * str);
private:
	T m_p[SIZE];	
};

template <typename T, size_t SIZE>
void Array<T, SIZE>::controlBounds(const char *str)
{
	std::cerr << str << std::endl;
	exit(EXIT_FAILURE); //Exception konusuna kadar sabýr
}


template <typename T, size_t SIZE>
T &Array<T, SIZE>::operator [](size_t index)
{
	if (index >= SIZE)
		controlBounds("out of range");
		
	return m_p[index];
}

template <typename T, size_t SIZE>
const T &Array<T, SIZE>::operator [](size_t index) const
{
	if (index >= SIZE)
		controlBounds("const out of range");

	return m_p[index];
}

#endif // ARRAY_HPP_
