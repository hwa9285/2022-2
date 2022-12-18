#include <iostream>
using namespace std;

class BaseArray {
	int size;
	int* p;
protected:
	BaseArray(int size) {
		this->size = size;
		p = new int[size];
	}//배열 생성
	~BaseArray() { delete[]p; }
	void put(int index, int val) {
		p[index] = val;
	}
	int get(int index) {
		return p[index];
	}
	int getSize() {
		return size;
	}

};

class MyStack :public BaseArray {
	int top = 0;
public:
	MyStack(int size) : BaseArray(size) { ; }
	void push(int n) {
		put(top, n);
		top++;
	}

	int capacity() {
		return getSize();
	}

	int length() {
		return top;
	}

	int pop() {
		top--;
		return get(top);
	}
};

int main() {
	MyStack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n); // 스택에 푸시
	}
	cout << "스택 용량:" << mStack.capacity() << ", 스택 크기:" << mStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력한다>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' '; // 스택에서 팝
	}
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}
