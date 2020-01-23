#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <bitset>
#include <set>
#include <map>
#include <regex>
using namespace std;
#define inf 2000000000
#define mod 1000000007

int t,n,m,dp[2001][2001];
int comb(int n, int m){
    if(n == m || m == 0) return 1;
    if(dp[n][m]) return dp[n][m];
    return dp[n][m] = (comb(n-1,m-1) + comb(n-1,m)) % mod;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> m;
        n += --m;
        cout << comb(n,m) << '\n';
    }
}
