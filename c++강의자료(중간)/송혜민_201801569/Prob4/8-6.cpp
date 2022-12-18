#include <iostream>
using namespace std;

class BaseArray {
	int size;
	int* p;
protected:
	BaseArray(int size) {
		this->size = size;
		p = new int[size];
	}//�迭 ����
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
	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n); // ���ÿ� Ǫ��
	}
	cout << "���� �뷮:" << mStack.capacity() << ", ���� ũ��:" << mStack.length() << endl;
	cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' '; // ���ÿ��� ��
	}
	cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
}
