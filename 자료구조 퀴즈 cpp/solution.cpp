#include <iostream>
#include <string>
#include <vector>

using namespace std;
enum direction { MIN = 1, MAX = -1 };					// min heap or max heap�� ������ ��. cf) a > b�� -a < -b�� ����� ����.

class Heap {
private:
	vector<int> v;
	int heap_size;
	int root_index;
	int direction;								// min, max�� ���� Heap�� ������ ������.
public:
	Heap(int direction) {
		v.push_back(-1);						// dummy variable
		this->heap_size = 0;
		this->root_index = 1;
		this->direction = direction;
	}
	void swap(int idx1, int idx2) {				// dummy variable�� �̿��Ͽ� swap.
		v[0] = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = v[0];
	}
	void upHeap(int idx) {						// for insert
		if (idx == root_index) return;
		else {
			int parent = idx / 2;
			if (v[parent] * direction > v[idx] * direction) {
				swap(parent, idx);
				upHeap(parent);
			}
		}
	}
	void downHeap(int idx) {					// for remove
		int left = idx * 2;
		int right = idx * 2 + 1;
		if (right <= heap_size) {									// ���ʿ� ��� ���� �ִ� ���
			if (v[left] * direction <= v[right] * direction) {			// �ڽ��� ���Ͽ� ���� �ڽ��� �� ����� �ǰ�(�ڽ��� ���� ������� ������ ��)
				if (v[left] * direction < v[idx] * direction) {		// ���� �ڽİ� ���Ͽ� heap������ �������� ������
					swap(left, idx);								// swap�� �ϰ�,
					downHeap(left);									// ���� �ڽĳ�忡�� �ٽ� downHeap�� ������.
				}
				else return;
			}
			else {													// ������ �ڽ��� �� �� ����� �ǰ�
				if (v[right] * direction < v[idx] * direction) {	// ������ �ڽİ� �ڱ� �ڽ��� ���Ͽ� heap ������ �������� ������
					swap(right, idx);								// swap�� �ϰ�,
					downHeap(right);								// ������ �ڽĳ�忡�� �ٽ� downHeap�� ��.
				}
				else return;										// �׷��� ������ finish
			}
		}
		else if (left <= heap_size) {								// ���ʿ��� ���� �ִ� ���
			if (v[left] * direction < v[idx] * direction) {			// �ڽŰ� ���Ͽ� �ڽ��� ���� ������
				swap(left, idx);									// Min Heap�� ���� �����̹Ƿ� swap
				downHeap(left);										// �ڽ� ��忡�� �ٽ� downHeap�� ��.
			}
			else return;											// �׷��� ������ finish
		}
		else return;												// ���� ��� ���� ��� finish		
	}
	void insert(int e) {
		v.push_back(e);
		heap_size++;
		upHeap(heap_size);
	}
	int pop() {
		int top = v[root_index];
		v[root_index] = v[heap_size]; heap_size--;
		v.pop_back();
		downHeap(root_index);
		return top;
	}
	int top() {
		return v[root_index];
	}
	int size() {
		return heap_size;
	}
	bool isEmpty() {
		if (heap_size == 0) return true;
		else return false;
	}
	void print() {
		if (isEmpty() == false) {
			for (int i = root_index; i < heap_size; i++) {
				cout << v[i] << ' ';
			}
			cout << v[heap_size] << endl;
		}
		else cout << -1 << endl;
	}
};

int main() {
	Heap PQ(MIN);
	int cmdNum;
	cin >> cmdNum;
	while (cmdNum--) {
		string cmd;
		cin >> cmd;
		if (cmd == "insert") {
			int input;
			cin >> input;
			PQ.insert(input);
		}
		else if (cmd == "size") {
			cout << PQ.size() << endl;
		}
		else if (cmd == "isEmpty") {
			if (PQ.isEmpty() == true) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (cmd == "pop") {
			if (PQ.isEmpty() == false) cout << PQ.pop() << endl;
			else cout << -1 << endl;
		}
		else if (cmd == "top") {
			if (PQ.isEmpty() == false) cout << PQ.top() << endl;
			else cout << -1 << endl;
		}
		else if (cmd == "print") {
			PQ.print();
		}
		else {
			cout << "Your command is wrong, try again." << endl;
		}
	}
	system("pause");
	return 0;
}