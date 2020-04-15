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
int t,ans;
long long dp[8][100001];
vector<int> arr[8];

int dfs(int now, int cnt){
	if(cnt == t){
		if(now == 0) return 1;
		return 0;
	}
	long long& temp = dp[now][cnt];
	if(temp != -1) return temp;
	temp = 0;
	
	for(int su : arr[now]){
		temp += dfs(su, cnt+1);
		temp %= mod;
	}
	return temp%mod;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	memset(dp,-1,sizeof(dp) );
	arr[0].push_back(1);
	arr[1].push_back(0);
	
	arr[0].push_back(2);
	arr[2].push_back(0);
	
	arr[1].push_back(2);
	arr[2].push_back(1);
	
	arr[1].push_back(3);
	arr[3].push_back(1);
	
	arr[2].push_back(3);
	arr[3].push_back(2);
	
	arr[4].push_back(2);
	arr[2].push_back(4);
	
	arr[3].push_back(4);
	arr[4].push_back(3);
	
	arr[3].push_back(5);
	arr[5].push_back(3);
	
	arr[4].push_back(5);
	arr[5].push_back(4);
	
	arr[5].push_back(6);
	arr[6].push_back(5);
	
	arr[6].push_back(7);
	arr[7].push_back(6);
	
	arr[4].push_back(7);
	arr[7].push_back(4);
	
	cout << dfs(0,0) << '\n';
}
