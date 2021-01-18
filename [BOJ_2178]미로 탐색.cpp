#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second
using namespace std;

int board[100][100] = { 0 };
bool vis[100][100]; // 1 - 방문
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	char k[100];
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < m; j++) {
			board[i][j] = k[j] - '0';
		}
	}
	
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 && vis[i][j]) continue; // 시작점
			vis[i][j] = 1;
			q.push({ i,j });

			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || board[nx][ny] != 1) continue;
					board[nx][ny] = board[cur.X][cur.Y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	cout << board[n - 1][m - 1];

	return 0;
}