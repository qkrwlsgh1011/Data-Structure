#include <iostream>
#include <string>
using namespace std;

class Array {
public:
	int n;		//�迭 �� ���� ��
	int* arr;	//�迭

	Array(int size) {
		this->n = 0;					//�迭 �� ���� �� 0���� �ʱ�ȭ
		this->arr = new int[size];		//ũ�Ⱑ size�� �迭 �Ҵ�
		for (int i = 0; i < size; i++) {//�迭 ���� 0���� �ʱ�ȭ
			arr[i] = 0;
		}
	}

	int at(int idx) {
		if (arr[idx] == 0)
			return 0;
		else
			return arr[idx];
	}

	void set(int idx, int X) {			//�ش� index�� ����� �� ������
		if (arr[idx] == 0)
			cout << "0" << endl;
		else {
			arr[idx] = X;
		}
	}

	void add(int idx, int NUM) {
		if (n == 0) {
			arr[n] = NUM;
		}
		else {
			if (n <= idx) {
				arr[n] = NUM;
			}
			else {
				for (int j = n - 1; j >= idx; j--) {
					arr[j + 1] = arr[j];
				}
				arr[idx] = NUM;
			}
		}
		n++;
	}

	void remove(int idx) {
		if (arr[idx] == 0) {
			cout << "0" << endl;
		}
		else {
			int temp = arr[idx];
			for (int i = idx; i < n; i++) {
				arr[i] = arr[i + 1];
			}
			n--;
			cout << temp << endl;
		}
	}

	void printArray() {
		if (n == 0) {
			cout << "0" << endl;
		}
		else {
			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	Array array1(10000);
	int many;
	cin >> many;
	for (int i = 0; i < many; i++) {
		string tmp;
		cin >> tmp;
		if (tmp == "at") {
			int idx1;
			cin >> idx1;
			cout << array1.at(idx1) << endl;
		}
		else if (tmp == "set") {
			int idx2;
			int x;
			cin >> idx2 >> x;
			array1.set(idx2, x);
		}
		else if (tmp == "add") {
			int idx3;
			int _NUM;
			cin >> idx3 >> _NUM;
			array1.add(idx3, _NUM);
		}
		else if (tmp == "remove") {
			int idx4;
			cin >> idx4;
			array1.remove(idx4);
		}
		else if (tmp == "printArray") {
			array1.printArray();
		}
	}
	return 0;
}