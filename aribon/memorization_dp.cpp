#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int rec(
	int i, int j, const vector<int>& v, const vector<int>& w, int n, vector<vector<int>>& dp) {
	if (i == n) {
		return 0;
	}
	if (dp[i][j] >= 0) {
		return dp[i][j];
	}
	if (j < w[i]) {
		return dp[i][j] = rec(i + 1, j, v, w, n, dp);
	}
	else {
		return dp[i][j] =
				   max(rec(i + 1, j - w[i], v, w, n, dp) + v[i], rec(i + 1, j, v, w, n, dp));
	}
}

int main() {
	int n, W;
	cin >> n >> W;
	vector<int> w(n), v(n);
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	vector<vector<int>> dp;
	for (int i = 0; i < n; ++i) {
		vector<int> row(W + 1, -1);
		dp.push_back(row);
	}
	rec(0, W, w, v, n, dp);

	cout << dp[0][W] << endl;
}