#include <iostream>
using std::cin;
using std::cout;
using std::cout;

int maxValue(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}


int fuction(int size, int capacity, int* weight, int* itemsPrice) {
	int* K = new int[capacity + 1];
	for (int i = 0; i <= capacity; i++) {
		K[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		for (int j = capacity; j >= weight[i]; j--) {
			if (weight[i] <= j) {
				K[j] = maxValue(K[j], K[j - weight[i]] + itemsPrice[i]);
			}
		}
	}
	int result = K[capacity];
	delete[] K;
	return result;
}


int main() {
	while (true) {
		
		int size;
		cin >> size;

		int* itemsPrice = new int[size];
		int* weight = new int[size];
		
		for (int i = 0; i < size; i++) {
			cin >> itemsPrice[i];
		}
		
		for (int i = 0; i < size; i++) {
			cin >> weight[i];
		}
		
		int capacity;
		cin >> capacity;
		cout << fuction(size, capacity, weight, itemsPrice) << std::endl;
		delete[] itemsPrice;
		delete[] weight;

	}
	return 0;
}
