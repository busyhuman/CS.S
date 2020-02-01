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
int n;
string str;
int calc(int a,int b,char op){
	if(op == '+') return a+b;
	if(op == '-') return a-b;
	if(op == '*') return a*b;
	return 0;
}
int dfs(int now, int sum){
//	cout << now << ' ' << sum << '\n';
	if(now > n) return sum;
	
	char op;
	int maxi = -inf;
	
	if(now==0) op = '+';
	else op = str[now-1];
	
	if(now+2 < n) maxi = max(maxi, dfs(now+4, calc(sum, calc(str[now]-'0',str[now+2]-'0',str[now+1]),op) ) );
	maxi = max(maxi,dfs(now+2,calc(sum, str[now]-'0',op)) );
	
	return maxi;
}

int main() {
    cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cin >> str;
	cout << dfs(0,0);
}
