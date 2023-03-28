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

	int at(int idx) {
		if (arr[idx] == 0)
			return 0;
		else
			return arr[idx];
	}

	void set(int idx, int X) {			//해당 index에 저장된 값 덮어씌우기
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