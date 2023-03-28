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

	void add(int NUM) {
		arr[n] = NUM;
		n++;
	}

	int Kor() {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (i % 3 == 0) {
				count = count + arr[i];
			}
		}
		return count;
	}

	int Jap() {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (i % 3 == 1) {
				count = count + arr[i];
			}
		}
		return count;
	}

	int Chi() {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (i % 3 == 2) {
				count = count + arr[i];
			}
		}
		return count;
	}
};

int main() {
	int many;
	cin >> many;
	for (int i = 0; i < many; i++) {
		int _size;
		cin >> _size;
		Array array1(_size);
		for (int j = 0; j < _size; j++) {
			int mount;
			cin >> mount;
			array1.add(mount);
		}
		cout << array1.Kor() << " " << array1.Jap() << " " << array1.Chi() << endl;
	}
	return 0;
}