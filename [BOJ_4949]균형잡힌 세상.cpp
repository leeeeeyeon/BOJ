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
				if (c != '(' && c != '[' && c != ')' && c != ']') continue; // 괄호가 아닐 때

				else if (c == '(' || c == '[') { // 여는 괄호 나옴
					st.push(c);
				}
				else if (c == ')' || c == ']') { // 닫는 괄호 나옴
					if (st.empty()) { // 스택 비어있음
						result = "no";
						break;
					}
					else if ((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[')) { // 짝이 맞음
						st.pop();
					}
					else if ((c == ')' && st.top() == '[') || (c == ']' && st.top() == '(')) { // 짝이 안 맞음
						result = "no";
						break;
					}
				}
			}
			if (!st.empty()) { // 종료했는데 스택이 비어있지 않음
				result = "no";
			}
			cout << result << '\n';
		}
	}
	return 0;
}