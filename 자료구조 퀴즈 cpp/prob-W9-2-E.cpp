#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Heap {
public:
	vector <int> list;
	vector <int> list2;
	int heap_size;
	int root_index;
	int heap_size2;

	Heap() {
		list.push_back(-1);
		list2.push_back(-1);
		this->heap_size = 0;
		this->heap_size2 = 0;
		this->root_index = 1;
	}

	void swap(int X, int Y) {
		list[0] = list[Y];
		list[Y] = list[X];
		list[X] = list[0];
	}

	void insert(int idx) {
		list.push_back(idx);
		heap_size++;
		upheap(heap_size);
	}

	void upheap(int idx) {
		if (idx == root_index) {
			return;
		}
		else {
			int parent = idx / 2;
			if (list[parent] > list[idx]) {
				swap(parent, idx);
				upheap(parent);
			}
		}
	}

	void downheap(int idx) {
		int left = idx * 2;
		int right = idx * 2 + 1;
		if (right <= heap_size) {	//둘다 있음
			if (list[left] <= list[right]) {
				if (list[left] < list[idx]) {
					swap(left, idx);
					downheap(left);
				}
				else return;
			}
			else {
				if (list[right] < list[idx]) {
					swap(right, idx);
					downheap(right);
				}
				else return;
			}
		}
		else if (left <= heap_size) {
			if (list[left] < list[idx]) {
				swap(left, idx);
				downheap(left);
			}
			else return;
		}
		else return;
	}

	int order() {
		int top = list[root_index];
		list[root_index] = list[heap_size];
		heap_size--;
		list .pop_back();
		downheap(root_index);
		return top;
	}
};

int main() {
	int much = 0;
	int many = 0;
	int time = 0;
	int idx = 0;
	cin >> much;
	for (int i = 0; i < much; i++) {
		Heap* heap = new Heap;
		Heap* heap2 = new Heap;
		cin >> many;
		cin >> time;
		for (int j = 0; j < many; j++) {
			cin >> idx;
			heap->insert(idx);
		}
		cout << heap->list[time] << endl;
		int size = heap->heap_size;
		int min = 0;
		while (size--) {
			min = heap->order();
			heap2->insert(min);
		}
		cout << heap2->list[time] << endl;
		delete heap;
	}
	return 0;
}