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


class MyQueue:public BaseArray {
	int front = 0;
	int rear = 0;

public:
	MyQueue(int size) :BaseArray(size) { ; }

	void enqueue(int n) {
		rear++;
		put(rear, n);
	
	}
	int capacity() {
		return getSize();
	}

	int length() {
		return rear;
	}
	int dequeue() {
		if (rear < 0) {
			cout << "ť�� ����ֽ��ϴ�.";
			exit(1);
		}
		++front;
		rear--;
		return get(front);
	}

};

int main() {
	MyQueue mQ(100);
	int n;
	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // ť�� ����
	}
	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
	}
	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}
