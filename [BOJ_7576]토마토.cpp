#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second
using namespace std;

int board[1002][1002] = { 0 };
bool vis[1002][1002];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>> q;

	// 시작점이 여러 개 - 모든 시작점을 큐에 넣고 BFS를 돌리자
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && !vis[i][j]) {
				vis[i][j] = 1;
				q.push({ i,j });
			}
		}
	}

	// BFS
	while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || board[nx][ny] < 0) continue;
					board[nx][ny] = board[cur.X][cur.Y] + 1;
					vis[nx][ny] = 1;
					q.push({ nx,ny });
				}
	}
	
	int max=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] > 0 && vis[i][j]) {
				if (board[i][j] > max) max = board[i][j];
			}
		}
	
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) max = 0;
		}

	}
	cout << max - 1;
	return 0;
}