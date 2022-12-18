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
			cout << "큐가 비어있습니다.";
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
	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // 큐에 삽입
	}
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
}
