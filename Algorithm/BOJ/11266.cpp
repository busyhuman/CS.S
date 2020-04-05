// https://www.crocus.co.kr/1164로 공부함
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
int v, e, ans, num;
int numbering[10001];
bool check[10001];
vector<int> arr[10001];

int dfs(int now, bool isRoot){
	int su = numbering[now] = ++num;
	
	int cnt = 0;
	
	for(int togo : arr[now]){
		
		if(numbering[togo]){
			su = min(su, numbering[togo]);
			continue;
		}
		
		cnt++;
		
		int mini = dfs(togo, false);
		
		if(isRoot == false && mini >= numbering[now]) check[now] = true;
		
		su = min(su, mini);
	}
	
	if(isRoot && cnt >= 2) check[now] = true;
	
	return su;
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
			dfs(i, true);
	
	int cnt = 0;
	for(int i=1;i<=v;i++)
		cnt += check[i];
	
	cout << cnt << '\n';
	
	for(int i=1;i<=v;i++)
		if(check[i])
			cout << i << ' ';
}
