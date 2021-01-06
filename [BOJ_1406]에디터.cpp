#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int m;
	list<char>l;
	cin >> s >> m; // abcd 3
	for (char c : s) l.push_back(c); // {a, b, c, d}
	auto t = l.end(); // 맨 마지막의 다음 원소

	for (int i = 0; i < m; i++) {
		char a;
		cin >> a;
		switch (a) {
		case 'L':
			if (t == l.begin()) break;
			--t;
			break;

		case 'D':
			if (t != l.end()) ++t;
			break;

		case 'B':
			if (t == l.begin()) break;
			--t;
			t = l.erase(t);
			break;

		case 'P':
			char nw;
			cin >> nw;
			l.insert(t, nw);
			break;
		}
	}
	auto p1 = begin(l);
	while (p1 != end(l)) {
		cout << *p1;
		++p1;
	}
	return 0;
}