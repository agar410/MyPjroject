#ifndef NSSTACK_H_INCLUDED
#define NSSTACK_H_INCLUDED

#include "./nsDLL.h"

template<typename T>
class MyStack {
private:
		DLL<T> pool;
public:
	void push(const T e) {
		pool.insEnd(e);
	}
	void pop() {
		pool.delEnd();
	}
	T& top() {
		return pool.getEnd();
	}
	int size() {
		return pool.size();
	}
	void show() {
		pool.show();
	}
};

#endif // NSSTACK_H_INCLUDED
