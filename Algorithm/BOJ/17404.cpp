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
using namespace std;
#define inf 2000000000
#define mod 1000000007
int dp[1004][3];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, mini=inf, arr[1004][3];
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	
	for(int k=0;k<3;k++){
		for(int l=0;l<3;l++){
			if(l != k) dp[0][l] = inf;
			else dp[0][k] = arr[0][k];
		}
		for (int i = 1; i < n; ++i){
			dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}
		for(int l=0;l<3;l++) if(l != k) mini = min(dp[n-1][l], mini);
	}

	cout << mini;
	return 0;
}
