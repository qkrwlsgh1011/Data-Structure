#include<iostream>
#include<vector>

#define MAX 353333
#define NOITEM 0		// cell�� ���� : ��������, ���絵 ���� ���� ����
#define ISITEM 1		// cell�� ���� : ���� ���� �ִ� ����
#define AVAILABLE 2		// cell�� ���� : ������ ���� �־�����, ����� ���� ����

using namespace std;

class cell {
public:
	int key;
	int value;
	int flag;			// cell�� ���� ����
	cell() {			// cell Ŭ������ ������ : ��� ���� �ʱ�ȭ
		key = -1;
		value = -1;
		flag = NOITEM;
	}
	~cell() {}			// cell Ŭ������ �Ҹ��� : ó���� ���� ����
};

class Table {
public:
	cell hashArr[MAX];		// MAX(353333) ���� cell�� �̷���� �迭 ���� (�ؽ� ���̺�)

	Table() {

	}
	~Table(){
	}

	int hashfunc(int idx) {
		return idx % MAX;	// ù ��° hash function
	}

	int hashfunc2(int idx) {
		return (17 - (idx % 17));	// �� ��° hash function
	}

	// Linear probing�� ����� ���� ����
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

	// Linear probing�� ����� Ž�� ����
	void tableSearchLinear(int key) {
		int probing = 1;
		while (hashArr[hashfunc(hashfunc(key) + probing - 1)].flag == ISITEM ||
			hashArr[hashfunc(hashfunc(key) + probing - 1)].flag == AVAILABLE) {
			if (hashArr[hashfunc(hashfunc(key) + probing - 1)].key == key) {
				break;
			}
			probing += 1;
		}

		if (hashArr[hashfunc(hashfunc(key) + probing - 1)].key == key) {	//��ã��
			cout << 1 << " " << probing << endl;
		}
		else {
			cout << 0 << " " << probing << endl;
		}
	}

	// Linear probing�� ����� ���� ����
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

	// Double hashing�� ����� ���� ����
	void tableInsertDouble(int key) {

	}

	// Double hashing�� ����� Ž�� ����
	void tableSearchDouble(int key) {

	}

	// �ؽ� ���̺��� hashArr �迭�� ��� cell�� ���� �ʱ�ȭ
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