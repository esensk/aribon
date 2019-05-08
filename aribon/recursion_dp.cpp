#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(int W, const vector<int>& v, const vector<int>& w, int n, vector<vector<int>>& dp) {
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j <= W; ++j) {
			if (j < w[j]) {
				dp[i][j] = dp[i + 1][j];
			} else {
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
			}
		}
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
	for (int i = 0; i <= n; ++i) {
		vector<int> row(W + 1, 0);
		dp.push_back(row);
	}
	solve(W, w, v, n, dp);

	cout << dp[0][W] << endl;
}