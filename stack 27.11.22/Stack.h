#pragma once

template <class T>
class Stack
{
	T* arr;
	int size;
	int top;
public:
	Stack(int s) {
		arr = new T[s];
		size = s;
		top = 0;
	}

	~Stack() {
		delete[] arr;
	}

	bool Add (T value) {	//	Если в стеке не хватает места то метод вернет 0
		if (top <= size) {
			arr[top++] = value;
			return 1;
		}
		else return 0;
	}

	T Get() {	//	Эта функция выдает верхний элемент и всё
		if (top > 0) return arr[top - 1];
		else throw top;
	}

	T Extract() { //	Эта функция выдает верхний элемент и уменшает top на 1
		if (top > 0) return arr[--top];
		else throw top;
	}

	void Clear() {
		top = 0;
	}

	bool is_full() {
		if (top >= size) return 1; //	Почему "top >= size"? Вдруг пользователь найдет способ выйти за рамки
		return 0;
	}

	bool is_empty() {
		if (top == 0) return 1;
		return 0;
	}
};