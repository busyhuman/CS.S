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
using namespace std;
#define inf 2000000000
#define mod 10007
int n, m, h, dp[51][50001];
vector<int> arr[51];

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> h;
	cin.ignore(1);
	string s;
	
	for(int i=0;i<n;i++){
		getline(cin, s);
		int len = s.size(),sum=0;
		for(int j=0;j<len-1;j++){
			if(s[j] == ' '){
				arr[i].push_back(sum);
				sum=0;
			}
			else{
				sum *= 10;
				sum += (s[j] - '0');
			}
		}
		sum *= 10;
		sum += (s[len-1] - '0');
		arr[i].push_back(sum);
	}

	for(int i=1;i<=n;i++){
		for(int j : arr[i-1]){
			dp[i][j]++;
			dp[i][j] %= mod;
			for(int k=0;k<=h;k++){
				dp[i][k+j] += dp[i-1][k];
				dp[i][k+j] %= mod;
			}
		}
		for(int k=0;k<=h;k++){
			dp[i][k] += dp[i-1][k];
			dp[i][k] %= mod;
		}
	}
	
	cout << dp[n][h];
}
