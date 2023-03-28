#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Heap {
public:
	vector <int> list;
	int heap_size;
	int root_index;

	Heap() {
		list.push_back(-1);
		this->heap_size = 0;
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
		if (right <= heap_size) {	//�Ѵ� ����
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

	void insert2(int idx) {	//max
		list.push_back(idx);
		heap_size++;
		upheap2(heap_size);
	}

	void upheap2(int idx) {	//max
		if (idx == root_index) {
			return;
		}
		else {
			int par = idx / 2;
			if (list[par] < list[idx]) {
				swap(par, idx);
				upheap2(par);
			}
		}
	}

	void downheap2(int idx) {//max
		int left = idx * 2;
		int right = idx * 2 + 1;
		if (right <= heap_size) {		//�Ѵ� ����
			if (list[left] >= list[right]) {	//������ �� ŭ
				if (list[left] > list[idx]) {
					swap(left, idx);
					downheap2(left);
				}
				else return;
			}
			else {								//�������� ��ŭ
				if (list[right] > list[idx]) {
					swap(right, idx);
					downheap2(right);
				}
			}
		}
		else if (left <= heap_size) {	//���ʸ� ����
			if (list[left] > list[idx]) {
				swap(left, idx);
				downheap2(left);
			}
			else return;
		}
		else return;						//�Ѵپ���
	}

	int order() {	//min����
		int top = list[root_index];
		list[root_index] = list[heap_size];
		heap_size--;
		list .pop_back();
		downheap(root_index);
		return top;
	}

	int order2() {	//max����
		int top = list[root_index];
		list[root_index] = list[heap_size];
		heap_size--;
		list.pop_back();
		downheap2(root_index);
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
		Heap* heap = new Heap;	//min��
		Heap* heap2 = new Heap;	//min����
		Heap* heap3 = new Heap;	//max��
		Heap* heap4 = new Heap;	//max����
		cin >> many;
		cin >> time;
		for (int j = 0; j < many; j++) {
			cin >> idx;
			heap->insert(idx);
			heap3->insert2(idx);
		}						//insert�ϱ�
		cout << heap->list[time] << endl;	//min�� ȣ��
		int size = heap->heap_size;
		int size2 = heap->heap_size;

		int min = 0;
		while (size--) {
			min = heap->order();
			heap2->insert(min);
		}
		cout << heap2->list[time] << endl;	//min���� ȣ��

		cout << heap3->list[time] << endl;	//max�� ȣ��

		int max = 0;
		while (size2--) {
			max = heap3->order2();
			heap4->insert2(max);
		}
		cout << heap4->list[time] << endl;	//max���� ȣ��

		delete heap4;
		delete heap3;
		delete heap2;
		delete heap;
	}
	return 0;
}