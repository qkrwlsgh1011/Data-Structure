#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Array {
public:
	int n;		//�迭 �� ���� ��
	int* arr;	//�迭
	int sumK = 0;
	int sumJ = 0;
	int sumC = 0;
	int avgK = 0;
	int avgJ = 0;
	int avgC = 0;

	Array(int size) {
		this->n = 0;					//�迭 �� ���� �� 0���� �ʱ�ȭ
		this->arr = new int[size];		//ũ�Ⱑ size�� �迭 �Ҵ�
		for (int i = 0; i < size; i++) {//�迭 ���� 0���� �ʱ�ȭ
			arr[i] = 0;
		}
	}

	void add(int NUM) {
		arr[n] = NUM;
		n++;
	}

	void Kor() {
		int much = 0;
		for (int i = 0; i < n; i++) {
			if ((i % 3 == 0) && (arr[i] != 0)) {
				sumK += arr[i];
				much++;
			}
		}
		if (sumK != 0) {
			avgK = sumK / much;
		}
		else
			avgK = 0;
	}

	void Jap() {
		int much = 0;
		for (int i = 0; i < n; i++) {
			if ((i % 3 == 1) && (arr[i] != 0)) {
				sumJ += arr[i];
				much++;
			}
		}
		if (sumJ != 0) {
			avgJ = sumJ / much;
		}
		else
			avgJ = 0;
	}

	void Chi() {
		int much = 0;
		for (int i = 0; i < n; i++) {
			if ((i % 3 == 2) && (arr[i] != 0)) {
				sumC += arr[i];
				much++;
			}
		}
		if (sumC != 0) {
			avgC = sumC / much;
		}
		else
			avgC = 0;
	}

	void display() {
		Kor();
		Jap();
		Chi();
		cout << sumK << " " << sumJ << " " << sumC << endl;
		cout << avgK << " " << avgJ << " " << avgC << endl;
	}
};

int main() {
	int many;
	cin >> many;
	int _size;
	int mount;
	for (int i = 0; i < many; i++) {
		cin >> _size;
		Array* array1;
		array1 = new Array(_size);
		for (int j = 0; j < _size; j++) {
			cin >> mount;
			array1->add(mount);
		}
		array1->display();
		delete array1;
	}
	return 0;
}