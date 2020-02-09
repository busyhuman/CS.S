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
int n, a[21][21];

int dfs(int now, int cnt, int size, vector<int>& arr){
	if(cnt == size){
		vector<int> brr;
		bool check[21]={false};
		int alen = arr.size(), blen = n-alen;

		for(int i=0;i<alen;i++)
			check[arr[i]]=true;
		
		for(int i=0;i<n;i++)
			if(check[i] == false) brr.push_back(i);
		
		int sum1=0, sum2=0;
		for(int i=0;i<alen;i++)
            for(int j=i+1;j<alen;j++)
                sum1 += a[arr[i]][arr[j]] + a[arr[j]][arr[i]];
		
		for(int i=0;i<blen;i++)
            for(int j=i+1;j<blen;j++)
                sum2 += a[brr[i]][brr[j]] + a[brr[j]][brr[i]];

		return abs(sum1-sum2);
	}
	
	int mini = inf;
	for(int i=now;i<n;i++){
		arr.push_back(i);
		mini = min(mini,dfs(i+1,cnt+1,size,arr) );
		arr.pop_back();
	}
	return mini;
}

int main() {
    cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> a[i][j];
	int ans = inf;
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			vector<int> arr;
			ans = min(ans,dfs(i,0,j,arr) );
		}
	}
	cout << ans;
}
