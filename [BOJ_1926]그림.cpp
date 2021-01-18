#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

#define X first
#define Y second
using namespace std;

int board[500][500] = { 0 };
bool vis[500][500]; // 1 - �湮
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
	} // �� �� �������, 1�� ��ĥ�� �κ�

	queue<pair<int, int>> q;
	pair<int, int> start;
	int num = 0; // �׸��� ����
	int mx = 0; // �׸��� ���� (�ִ�)
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == 0 && board[i][j] == 1) {
				start = { i,j };
				q.push(start);
				vis[i][j] = 1;
				num++;
			}

			int area = 0; // �׸��� ����
			while (!q.empty()) {
				pair<int, int> cur = q.front(); // (0, 0)
				q.pop();
				area++;

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // ������ ���
					if (vis[nx][ny] || board[nx][ny] != 1) continue;
					// �̹� �湮�߰ų� ��ĥ���� ���� ���
					vis[nx][ny] = 1;
					q.push({ nx,ny });
				} // for�� - �����¿� Ž��
			} // �׸� �ϳ� ã��
			mx = max(mx, area);

		}
	}
	cout << num << '\n';
	cout << mx << '\n';
	return 0;
}