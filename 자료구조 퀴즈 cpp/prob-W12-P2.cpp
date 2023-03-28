#include <iostream>

#define MAX 353333
#define AVAILABLE 2
#define ISITEM 1
#define NOITEM 0
using namespace std;

class cell {
public:
	int key;
	int value;
	int flag;
	cell() {
		key = -1;
		value = -1;
		flag = NOITEM;
	}
	~cell() {
	}
};

cell HashArr[MAX];

int hashfunc(int idx) {
	return idx % MAX;
}
int hashfunc2(int idx) {
	return(17 - (idx % 17));
}

void insertHash(int idx) {
	int probing = 1;
	while (HashArr[hashfunc(hashfunc(idx)+(probing-1)*hashfunc2(idx))].flag == ISITEM) {
		probing++;
	}
	if (HashArr[hashfunc(hashfunc(idx) + (probing - 1) * hashfunc2(idx))].flag == NOITEM) {
		HashArr[hashfunc(hashfunc(idx) + (probing - 1) * hashfunc2(idx))].key = idx;	//원래자연수 key에 저장
		HashArr[hashfunc(hashfunc(idx) + (probing - 1) * hashfunc2(idx))].value = idx + probing - 1;//변환해서 어디에 저장하는지
		HashArr[hashfunc(hashfunc(idx) + (probing - 1) * hashfunc2(idx))].flag = ISITEM;
	}
}

void searchHash(int idx) {
	int probing = 1;
	while (HashArr[hashfunc(hashfunc(idx) + (probing - 1) * hashfunc2(idx))].flag == ISITEM ||
		HashArr[hashfunc(hashfunc(idx) + (probing - 1) * hashfunc2(idx))].flag == AVAILABLE) {
		if (HashArr[hashfunc(hashfunc(idx) + (probing - 1) * hashfunc2(idx))].key == idx) {
			break;
		}
		probing += 1;
	}
	if (HashArr[hashfunc(hashfunc(idx) + (probing - 1) * hashfunc2(idx))].flag == NOITEM) {
		cout << 0 << " " << probing << endl;
	}
	else {
		cout << 1 << " " << probing << endl;
	}
}

void deleteHash(int idx) {
	int probing = 1;
	while (HashArr[hashfunc(idx + probing - 1)].flag == ISITEM
		|| HashArr[hashfunc(idx + probing - 1)].flag == AVAILABLE) {
		if (HashArr[hashfunc(idx + probing - 1)].key == idx) {
			break;
		}
		probing += 1;
	}

	if (HashArr[hashfunc(idx + probing - 1)].key == idx) {
		HashArr[hashfunc(idx + probing - 1)].key = -1;
		HashArr[hashfunc(idx + probing - 1)].flag = AVAILABLE;
		cout << 1 << " " << probing << endl;
	}
	else {
		cout << 0 << " " << probing << endl;
	}
}

void clearTable() {
	for (int i = 0; i < MAX; i++) {
		HashArr[i].key = -1;
		HashArr[i].value = -1;
		HashArr[i].flag = NOITEM;
	}
}

int main() {
	int much;
	int intmany;
	int value;
	cin >> much;
	while (much--) {
		cin >> intmany;
		while (intmany--) {
			cin >> value;
			insertHash(value);
		}
		cin >> intmany;
		while (intmany--) {
			cin >> value;
			searchHash(value);
		}
		clearTable();
	}
	return 0;
}