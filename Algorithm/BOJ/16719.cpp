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
string str;
int len;
bool check[101];

void print(){
	for(int i=0;i<len;i++)
		if(check[i]) cout << str[i];
	cout << '\n';
}
void dfs(int curr){
	bool b = true;
	
	while(b) {
		b = false;
		int mini = inf, minidx = 0;
		bool bb = false;
		
		for(int i=curr;i<len;i++){
			if(check[i] == false && mini > str[i]){
				mini = str[i];
				minidx = i;
				bb = true;
				b = true;
			}
		}
		
		if(!bb) return;

		check[minidx] = true;
		print();

		for(int i=minidx;i<len;i++) dfs(i);
	}
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> str;
	len = str.size();
	dfs(0);
}
