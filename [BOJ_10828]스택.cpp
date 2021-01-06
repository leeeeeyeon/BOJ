#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<int> st;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.compare("push") == 0) {
			int x;
			cin >> x;
			st.push(x);
		}

		else if (s.compare("pop") == 0) {
			if (st.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << st.top() << '\n';
			st.pop();
		}

		else if (s.compare("size") == 0) {
			cout << st.size() << '\n';
		}

		else if (s.compare("empty") == 0) {
			if (st.empty()) {
				cout << 1;
				continue;
			}
			cout << 0 << '\n';
		}

		//else if (s.compare("top") == 0)
		else {
			if (st.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << st.top() << '\n';
		}
	}
	return 0;
}