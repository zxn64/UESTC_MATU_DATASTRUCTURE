#include <iostream>

#define max_n 505
#define mod 1000000007

using namespace std;
long long dp[max_n][max_n];
int ans[max_n][max_n];

void dfs(int l, int r, int out[], int &idx) {
    if (l == r) {
        out[idx++] = l;
        return;
    }
    out[idx++] = -1;
    dfs(l, ans[l][r], out, idx);
    dfs(ans[l][r] + 1, r, out, idx);
    out[idx++] = -2;
}

void solve(int n, int p[], int out[]) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) dp[i][j] = 0;
            else dp[i][j] = 0x3f3f3f3f3f3f3f3f;
        }
    }
    long long new_value;
    for (int len = 1; len < n; ++len) {
        for (int i = 1, j = i + len; j <= n; ++i, ++j) {
            for (int k = i; k < j; ++k) {
                new_value = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (new_value < dp[i][j]) {
                    dp[i][j] = new_value;
                    ans[i][j] = k;
                }
            }
        }
    }
    out[0] = dp[1][n] % mod;
    int idx = 1;
    dfs(1, n, out, idx);
}