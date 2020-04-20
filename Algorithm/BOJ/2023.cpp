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
int n, arr[4]={2,3,5,7};

bool isPrime(int su){
	if(su == 1) return false;
	
	int square = sqrt(su);
	
	for(int i=2;i<=square;i++) if( !(su%i) ) return false;
	return true;
}

void dfs(int now, int cnt){
	if( cnt == n){
		cout << now << '\n';
		return;
	}
	
	for(int i=1;i<=9;i+=2){
		if(isPrime(now*10+i) ){
			dfs(now*10+i, cnt+1);
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	
	for(int i : arr)
		dfs(i, 1);
}
