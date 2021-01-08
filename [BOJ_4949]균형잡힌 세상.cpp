#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		stack<char> st;
		string result = "yes";

		string s;
		getline(cin, s);

		if (s == ".") break;
		else {
			result = "yes";
			for (auto c : s) {
				if (c != '(' && c != '[' && c != ')' && c != ']') continue; // ��ȣ�� �ƴ� ��

				else if (c == '(' || c == '[') { // ���� ��ȣ ����
					st.push(c);
				}
				else if (c == ')' || c == ']') { // �ݴ� ��ȣ ����
					if (st.empty()) { // ���� �������
						result = "no";
						break;
					}
					else if ((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[')) { // ¦�� ����
						st.pop();
					}
					else if ((c == ')' && st.top() == '[') || (c == ']' && st.top() == '(')) { // ¦�� �� ����
						result = "no";
						break;
					}
				}
			}
			if (!st.empty()) { // �����ߴµ� ������ ������� ����
				result = "no";
			}
			cout << result << '\n';
		}
	}
	return 0;
}