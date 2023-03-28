#include <iostream>
#include <string>
using namespace std;

int main() {
	int many;
	cin >> many;
	for (int i = 0; i < many; i++) {
		int arr[100] = { 0 };
		int arraysize;
		int sumK = 0;
		int sumJ = 0;
		int sumC = 0;
		int avgK = 0;
		int avgJ = 0;
		int avgC = 0;
		int countK = 0;
		int countJ = 0;
		int countC = 0;
		cin >> arraysize;
		for (int j = 0; j < arraysize; j++) {
			cin >> arr[j];
			if (j % 3 == 0 && arr[j] != 0) {
				sumK += arr[j];
				countK++;
			}
			else if (j % 3 == 1 && arr[j] != 0) {
				sumJ += arr[j];
				countJ++;
			}
			else if(j % 3 == 2 && arr[j] != 0) {
				sumC += arr[j];
				countC++;
			}
		}
		if (sumK == 0) {
			avgK = 0;
		}
		else {
			avgK = sumK / countK;
		}

		if (sumJ == 0) {
			avgJ = 0;
		}
		else {
			avgJ = sumJ / countJ;
		}

		if (sumC == 0) {
			avgC = 0;
		}
		else {
			avgC = sumC / countC;
		}

		cout << sumK << " " << sumJ << " " << sumC << endl;
		cout << avgK << " " << avgJ << " " << avgC << endl;
	}
	return 0;
}