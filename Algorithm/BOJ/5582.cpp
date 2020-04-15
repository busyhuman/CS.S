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
#include <regex>
#include <set>
#include <map>
using namespace std;
#define inf 2000000000
#define mod 1000000007
string a, b;
int dp[4001][4001], ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a;
	cin >> b;
	int alen = a.size(), blen = b.size();
	
	for(int i=1;i<=alen;i++){
		for(int j=1;j<=blen;j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
				ans = max(ans,dp[i][j]);
			}
			else dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1]) );
		}
	}
	cout << ans;
}
