#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

#define X first
#define Y second
using namespace std;

int board[500][500] = { 0 };
bool vis[500][500]; // 1 - 방문
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int board[500][500] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	} // 판 잘 만들어짐, 1이 색칠된 부분

	queue<pair<int, int>> q;
	pair<int, int> start;
	int num = 0; // 그림의 개수
	int mx = 0; // 그림의 넓이 (최대)
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == 0 && board[i][j] == 1) {
				start = { i,j };
				q.push(start);
				vis[i][j] = 1;
				num++;
			}

			int area = 0; // 그림의 넓이
			while (!q.empty()) {
				pair<int, int> cur = q.front(); // (0, 0)
				q.pop();
				area++;

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위를 벗어남
					if (vis[nx][ny] || board[nx][ny] != 1) continue;
					// 이미 방문했거나 색칠되지 않을 경우
					vis[nx][ny] = 1;
					q.push({ nx,ny });
				} // for문 - 상하좌우 탐색
			} // 그림 하나 찾기
			mx = max(mx, area);

		}
	}
	cout << num << '\n';
	cout << mx << '\n';
	return 0;
}