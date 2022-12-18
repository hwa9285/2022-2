#include <iostream>
using namespace std;

class SortedArray {
	int size; // ���� �迭�� ũ��
	int* p; // ���� �迭�� ���� ������
	void sort(); // ���� �迭�� ������������ ����
public:
	SortedArray() {
		size = 0;
		p = NULL;
	}// p�� NULL�� size�� 0���� �ʱ�ȭ

	SortedArray(SortedArray& src) {
		this->size = src.size;
		this->p = new int[this->size];
		for (int i = 0; i < this->size; i++)
			this->p[i] = src.p[i];

	} // ���� ������

	SortedArray(int p[], int size) {
		this->size = size;
		this->p = new int[size];
		for (int i = 0; i < size; i++) {
			this->p[i] = p[i];
		}
	} // ������. ���� �迭�� ũ�⸦ ���޹���
	~SortedArray() {
		delete[]p;
	} // �Ҹ���

	SortedArray operator + (SortedArray& op2);
	SortedArray& operator = (const SortedArray& op2); // ���� �迭�� op2 �迭�� ����
	void show(); // �迭�� ���� ���
};

SortedArray SortedArray::operator+(SortedArray& op2) {
	SortedArray tmp;
	tmp.p = new int[this->size + op2.size];
	tmp.size = this->size + op2.size;
	for (int i = 0; i < this->size; ++i)
		tmp.p[i] = this->p[i];
	for (int i = 0; i < op2.size; ++i)
		tmp.p[i + this->size] = op2.p[i];
	return tmp;
}

SortedArray& SortedArray::operator=(const SortedArray& op2) {
	delete[]p;
	this->size = op2.size;
	this->p = new int[this->size];
	for (int i = 0; i < this->size; i++)
		this->p[i] = op2.p[i];
	return *this;
}

void SortedArray::sort() {
	int swp;
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (p[i] < p[j] || p[i] == p[j]);
			else {
				swp = p[i];
				p[i] = p[j];
				p[j] = swp;
			}
		}
	}
}

void SortedArray::show() {
	sort();
	cout << "�迭 ���: ";
	for (int i = 0; i < size; i++) {
		cout << p[i]<<" ";
	}
	cout << endl;
}

int main() {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b; // +, = ������ �ۼ� �ʿ�
	// + �����ڰ� SortedArray ��ü�� �����ϹǷ� ���� ������ �ʿ�

	a.show();
	b.show();
	c.show();
}
