#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int kInf = 101;

int bfs(int n, int m, int sx, int sy, int gx, int gy, const vector<vector<char>>& k,
	vector<vector<int>>& d) {
	queue<pair<int, int>> q;

	q.push(make_pair(sx, sy));

	int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

	while (q.size() > 0) {
		pair<int, int> p = q.front();
		q.pop();

		if (p.first == gx && p.second == gy) {
			break;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = p.first + dx[i], ny = p.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (k[nx][ny] == '#' || d[nx][ny] != kInf) {
				continue;
			}
			d[nx][ny] = d[p.first][p.second] + 1;
			q.push(make_pair(nx, ny));
		}
	}

	return d[gx][gy];
}

/*
 * ƒXƒ^[ƒg(S)‚©‚çƒS[ƒ‹(G)‚Ü‚Å‚ÌÅ’ZŒo˜H‚ð‹‚ß‚é
 */
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> k(n);
	for (int i = 0; i < n; ++i) {
		vector<char> row(m);
		for (int j = 0; j < m; ++j) {
			cin >> row[j];
		}
		k[i] = row;
	}

	int i = 0, j = 0;
	while (k[i][j] != 'S') {
		if (j == m - 1) {
			j = 0;
			++i;
		} else {
			++j;
		}
	}

	int sx = i, sy = j;

	i = 0, j = 0;
	while (k[i][j] != 'G') {
		if (j == m - 1) {
			j = 0;
			++i;
		} else {
			++j;
		}
	}

	int gx = i, gy = j;

	vector<vector<int>> d(n);
	for (int i = 0; i < n; ++i) {
		vector<int> row(m, kInf);
		d[i] = row;
	}
	d[sx][sy] = 0;

	int ans = bfs(n, m, sx, sy, gx, gy, k, d);

	cout << ans << endl;
}