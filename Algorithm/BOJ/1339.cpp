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
int ans,alpha[11],len[11],n,m,temp[31];
bool check[31];
string arr[11];

void dfs(int now){
	if(now == m){
		int sum = 0;
		for(int i=0;i<n;i++){
			int dan=1;
			for(int j=len[i]-1;j>=0;j--){
				sum += alpha[temp[arr[i][j]-'A']]*dan;
				dan*=10;
			}
		}
		ans = max(sum,ans);
		return;
	}
	
	for(int i=9;i>=0;i--){
		if(check[i] == 0){
			check[i] = 1;
			alpha[now] = i;
			dfs(now+1);
			check[i] = 0;
			alpha[now] = 0;
		}
	}
}
int main() {
    cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	memset(temp,-1,sizeof(temp));
	for(int i=0;i<n;i++) {
		cin >> arr[i];
		len[i] = arr[i].size();
		for(int j=0;j<len[i];j++){
			if(temp[arr[i][j]-'A'] == -1)
				temp[arr[i][j]-'A'] = m++;
		}
	}
	dfs(0);
	cout << ans;
}
