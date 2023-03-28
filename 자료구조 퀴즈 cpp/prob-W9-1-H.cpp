#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Heap {
public:
	vector<int> v;
	int heap_size;
	int root_index;

	Heap() {
		v.push_back(-1);
		this->heap_size = 0;
		this->root_index = 1;
	}

	void swap(int idx1, int idx2) {
		v[0] = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = v[0];
	}

	void insert(int e) {
		v.push_back(e);
		heap_size++;
		upheap(heap_size);
	}

	void pop() {
		int data = 0;
		if (heap_size == 0) {
			cout << -1 << endl;
		}
		else if (heap_size == 1) {
			data = v[1];
			v.pop_back();
			heap_size--;
		}
		else {
			data = v[1];
			v[1] = v[heap_size];
			v.pop_back();
			heap_size--;
			downheap(1);
		}
		cout << data << endl;
	}

	void upheap(int idx) {
		if (idx == root_index) {
			return;
		}
		else {
			int parent = idx / 2;
			if (v[parent] > v[idx]) {
				swap(parent, idx);
				upheap(parent);
			}
		}
	}

	void downheap(int idx) {
		int chiL = idx * 2;
		int chiR = idx * 2 + 1;
		if (heap_size < chiL) {	//자식 둘다 없을 때
			return;
		}
		else if (heap_size < chiR) {	//왼쪽 자식만 있을 때
			if (v[idx] > v[chiL]) {
				swap(idx, chiL);
				downheap(chiL);
			}
			else {
				return;
			}
		}
		else {	//양쪽 자식 둘다 있을 때
			if (v[chiL] <= v[chiR]) {
				if (v[idx] > v[chiL]) {
					swap(idx, chiL);
					downheap(chiL);
				}
				else {
					return;
				}
			}
			else {
				if (v[idx] > v[chiR]) {
					swap(idx, chiR);
					downheap(chiR);
				}
				else {
					return;
				}
			}
		}
	}

	int size() {
		return heap_size;
	}

	void isEmpty() {
		if (heap_size == 0) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}

	void top() {
		if (heap_size == 0) {
			cout << -1 << endl;
		}
		else {
			cout << v[1] << endl;
		}
	}

	void print() {
		if (heap_size == 0) {
			cout << -1 << endl;
		}
		else {
			for (int i = 1; i < heap_size; i++) {
				cout << v[i] << " ";
			}
			cout << v[heap_size] << endl;
		}
	}
};

int main() {
	int much = 0;
	string tmp;
	int data = 0;
	Heap heap;
	cin >> much;
	for (int i = 0; i < much; i++) {
		cin >> tmp;
		if (tmp == "insert") {
			cin >> data;
			heap.insert(data);
		}
		else if (tmp == "size") {
			cout << heap.size() << endl;
		}
		else if (tmp == "isEmpty") {
			heap.isEmpty();
		}
		else if (tmp == "pop") {
			heap.pop();
		}
		else if (tmp == "top") {
			heap.top();
		}
		else if (tmp == "print") {
			heap.print();
		}
	}
	return 0;
}