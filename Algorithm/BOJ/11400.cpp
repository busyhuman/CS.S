// https://www.crocus.co.kr/1164 참고함.
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
int v, e, num;
vector<int> arr[100001];
vector< pair<int,int> > ans;
int check[100001];

int dfs(int curr, int prev){
	check[curr] = ++num;
	int mini = check[curr];
	for(int togo : arr[curr]){
		if( togo == prev) continue;
		
		if(check[togo] ){
			mini = min(mini, check[togo] );
			continue;
		}
		
		int temp = dfs(togo, curr);
		
		if(temp > check[curr])
			ans.push_back( make_pair(min(curr,togo), max(curr, togo)) );
		
		mini = min(mini,temp);
	}
	return mini;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> e;
	for(int i=0;i<e;i++){
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	
	for(int i=1;i<=v;i++)
		if(!check[i])
			dfs(i,0);
	
	sort(ans.begin(), ans.end() );
	
	int len = ans.size();
    
	cout << len << '\n';
	for(int i=0;i<len;i++)
		cout << ans[i].first << ' '  << ans[i].second << '\n';
}
