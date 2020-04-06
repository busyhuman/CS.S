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
int dp[33001][5];

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	dp[0][0]=1;
	for(int i=1;i<=182;i++)
		for(int j=i*i;j<=33000;j++)
			for(int k=1;k<=4;k++)
				dp[j][k] += dp[j-i*i][k-1];
	int n;
	while(true){
		cin >> n;
		if(!n) break;
		cout << dp[n][1]+dp[n][2]+dp[n][3]+dp[n][4] << '\n';
	}
}
