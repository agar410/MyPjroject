#ifndef NSQUEUE_H_INCLUDED
#define NSQUEUE_H_INCLUDED

#include "./nsDLL.h"

template<typename T>
class MyQueue {
private:
	DLL<T> pool;
public:
	void push(const T e) {
		pool.insEnd(e);
	}
	void pop() {
		pool.delBeg();
	}
	T& top() {
		return pool.getBeg();
	}
	int size() {
		return pool.size();
	}
    void show() {
		pool.show();
	}
};

#endif // NSQUEUE_H_INCLUDED
