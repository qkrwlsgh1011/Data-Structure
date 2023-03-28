#include<iostream>
#include<vector>

#define MAX 353333
#define NOITEM 0		// cell의 상태 : 이전에도, 현재도 값이 없는 상태
#define ISITEM 1		// cell의 상태 : 현재 값이 있는 상태
#define AVAILABLE 2		// cell의 상태 : 이전에 값이 있었으나, 현재는 없는 상태

using namespace std;

class cell {
public:
	int key;
	int value;
	int flag;			// cell의 상태 변수
	cell() {			// cell 클래스의 생성자 : 멤버 변수 초기화
		key = -1;
		value = -1;
		flag = NOITEM;
	}
	~cell() {}			// cell 클래스의 소멸자 : 처리할 내용 없음
};

class Table {
public:
	cell hashArr[MAX];		// MAX(353333) 개의 cell로 이루어진 배열 생성 (해시 테이블)

	Table() {

	}
	~Table(){
	}

	int hashfunc(int idx) {
		return idx % MAX;	// 첫 번째 hash function
	}

	int hashfunc2(int idx) {
		return (17 - (idx % 17));	// 두 번째 hash function
	}

	// Linear probing을 사용한 삽입 연산
	void tableInsertLinear(int key) {
		int probing = 1;

		while (hashArr[hashfunc(hashfunc(key) + probing - 1)].flag == ISITEM) {
			probing += 1;
			if (hashArr[hashfunc(hashfunc(key) + probing - 1)].flag == NOITEM) {
				break;
			}
		}
		if (hashArr[hashfunc(hashfunc(key) + probing - 1)].flag == NOITEM) {
			hashArr[hashfunc(hashfunc(key) + probing - 1)].flag = ISITEM;
			hashArr[hashfunc(hashfunc(key) + probing - 1)].key = key;
		}
	}

	// Linear probing을 사용한 탐색 연산
	void tableSearchLinear(int key) {
		int probing = 1;
		while (hashArr[hashfunc(hashfunc(key) + probing - 1)].flag == ISITEM ||
			hashArr[hashfunc(hashfunc(key) + probing - 1)].flag == AVAILABLE) {
			if (hashArr[hashfunc(hashfunc(key) + probing - 1)].key == key) {
				break;
			}
			probing += 1;
		}

		if (hashArr[hashfunc(hashfunc(key) + probing - 1)].key == key) {	//못찾음
			cout << 1 << " " << probing << endl;
		}
		else {
			cout << 0 << " " << probing << endl;
		}
	}

	// Linear probing을 사용한 삭제 연산
	void tableDeleteLinear(int key) {
		int probing = 1;
		while (hashArr[hashfunc(hashfunc(key) + probing - 1)].flag == NOITEM ||
			hashArr[hashfunc(hashfunc(key) + probing - 1)].flag == AVAILABLE) {
			if (hashArr[hashfunc(hashfunc(key) + probing - 1)].key == key) {
				hashArr[hashfunc(hashfunc(key) + probing - 1)].flag = AVAILABLE;
				hashArr[hashfunc(hashfunc(key) + probing - 1)].key = -1;
				break;
			}
			probing += 1;
		}
	}

	// Double hashing을 사용한 삽입 연산
	void tableInsertDouble(int key) {

	}

	// Double hashing을 사용한 탐색 연산
	void tableSearchDouble(int key) {

	}

	// 해시 테이블인 hashArr 배열의 모든 cell의 값을 초기화
	void tableClear() {

	}
};

int main() {
	int much = 0;
	int many = 0;
	int data = 0;
	cin >> much;
	while (much--) {
		Table* table = new Table();
		cin >> many;
		while (many--) {
			cin >> data;
			table->tableInsertLinear(data);
		}
		cin >> many;
		while (many--) {
			cin >> data;
			table->tableDeleteLinear(data);
		}
		delete table;
	}
	return 0;
}