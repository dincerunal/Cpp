#ifndef STACK_H_
#define STACK_H_

template <typename T>
class Stack {
	//...
private:
	T *m_p;
	T *m_sp;
	size_t m_size;
};

#endif // STACK_H_
