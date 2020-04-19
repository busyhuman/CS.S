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
vector<int> arr;
bool check[1121];
int dp[190][1121][15], len, n, m;
int dfs(int now, int sum, int cnt){

	if(cnt == m){
		if(sum == n) return 1;
		else return 0;
	}
	if(sum == n || now == len) return 0;

	int& ret = dp[now][sum][cnt];
	if(ret != -1 ) return ret;
	
	ret = dfs(now+1,sum,cnt);
	if(sum + arr[now] <= n) ret += dfs(now+1,sum+arr[now], cnt+1);
	
	return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i=2;i<=1120;i++){
		if(check[i] == false){
			arr.push_back(i);
			for(int j=i;j<=1120;j+=i)
				check[j]=true;
		}
	}
	len = arr.size();
	int t;
	cin >> t;

	while(t--){
		memset(dp, -1, sizeof(dp) );
		cin >> n >> m;
		cout << dfs(0, 0, 0) << '\n';
	}
}
