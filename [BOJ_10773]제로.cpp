#include <iostream>
using namespace std;

int s[1000000];
int pos = 0;

void push(int x) {
	s[pos] = x;
	pos++;
}

void pop() {
	pos--;
	s[pos] = 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int n;
		cin >> n;
		if (n != 0) {
			push(n);
		}
		else {
			pop();
		}
	}

	int sum = 0;
	for (int i = 0; i < pos; i++) {
		sum += s[i];
	}
	cout << sum;
	return 0;
}