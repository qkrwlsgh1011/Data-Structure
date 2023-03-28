#include <iostream>
#include <string>
#include <vector>

using namespace std;
enum direction { MIN = 1, MAX = -1 };					// min heap or max heap을 결정할 값. cf) a > b와 -a < -b는 결과가 같다.

class Heap {
private:
	vector<int> v;
	int heap_size;
	int root_index;
	int direction;								// min, max에 따라 Heap의 종류가 결정됨.
public:
	Heap(int direction) {
		v.push_back(-1);						// dummy variable
		this->heap_size = 0;
		this->root_index = 1;
		this->direction = direction;
	}
	void swap(int idx1, int idx2) {				// dummy variable을 이용하여 swap.
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
		if (right <= heap_size) {									// 양쪽에 모두 값이 있는 경우
			if (v[left] * direction <= v[right] * direction) {			// 자식을 비교하여 왼쪽 자식이 비교 대상이 되고(자식의 값이 같은경우 왼쪽을 비교)
				if (v[left] * direction < v[idx] * direction) {		// 왼쪽 자식과 비교하여 heap조건을 만족하지 않으면
					swap(left, idx);								// swap을 하고,
					downHeap(left);									// 왼쪽 자식노드에서 다시 downHeap을 실행함.
				}
				else return;
			}
			else {													// 오른쪽 자식이 더 비교 대상이 되고
				if (v[right] * direction < v[idx] * direction) {	// 오른쪽 자식과 자기 자신을 비교하여 heap 조건을 만족하지 않으면
					swap(right, idx);								// swap을 하고,
					downHeap(right);								// 오른쪽 자식노드에서 다시 downHeap을 함.
				}
				else return;										// 그렇지 않으면 finish
			}
		}
		else if (left <= heap_size) {								// 왼쪽에만 값이 있는 경우
			if (v[left] * direction < v[idx] * direction) {			// 자신과 비교하여 자식이 값이 작으면
				swap(left, idx);									// Min Heap에 대한 위반이므로 swap
				downHeap(left);										// 자식 노드에서 다시 downHeap을 함.
			}
			else return;											// 그렇지 않으면 finish
		}
		else return;												// 양쪽 모두 없는 경우 finish		
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