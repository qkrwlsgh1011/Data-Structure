#include <iostream>
#include <string>
using namespace std;

class Array {
public:
	int n;		//배열 내 원소 수
	int* arr;	//배열

	Array(int size) {
		this->n = 0;					//배열 내 원소 수 0으로 초기화
		this->arr = new int[size];		//크기가 size인 배열 할당
		for (int i = 0; i < size; i++) {//배열 원소 0으로 초기화
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