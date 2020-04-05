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
int fact[9]={1}, ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i=1;i<=8;i++)
		fact[i] = i*fact[i-1];
	
	for(int i=8;i>=1;i--){
		while(fact[i] <= n){
			n -= fact[i];
			ans++;
		}
	}
	cout << ans;
}
