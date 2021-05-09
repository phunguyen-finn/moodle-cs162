#ifndef INCLUDE_VECTOR_H
#define INCLUDE_VECTOR_H

#include <stdlib.h>
#include <functional>
#include <assert.h>

using namespace std;

template <typename T> class Vector {
public:

	T* arr;
	int capacity;
	int current;

	Vector() {
		arr = new T[1];
		capacity = 1;
		current = 0;
	}

	void clear_all() {
		delete[] arr;
		arr = new T[1];
		capacity = 1;
		current = 0;
	}

	void erase(int index) {
		for (int i = index; i < current - 1; i++) {
			arr[i] = arr[i + 1];
		}
		current--;
	}

	void reserve() {
		T* temp = new T[capacity*(int)2];
		for (int i = 0; i < capacity; i++)
			temp[i] = arr[i];

		delete[] arr;
		capacity *= 2;
		arr = temp;
	}

	T& operator[](int index) {
		if (index >= current) {
			abort();
		}
		return arr[index];
	}

	void push(T data) {
		if (current == capacity) reserve();
		arr[current++] = data;
	}

	void pop() {
		current--;
	}

	int size() {
		return current;
	}

	int getCapacity() {
		return capacity;
	}

	T find(function<bool(T)> f) {
		for (int i = 0; i < current; i++) {
			if (f(arr[i])) return arr[i];
		}
	}

	Vector<T> filter(function<bool(T)> f) {
		Vector<T> filtered;
		for (int i = 0; i < current; i++) {
			if (f(arr[i])) filtered.push(arr[i]);
		}
		return filtered;
	}

	~Vector() {
		delete [] arr;
	}
};

#endif