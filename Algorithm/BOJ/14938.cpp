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
#define inf 1000000000
#define mod 1000000007
int n,m,r,ans;
int item[101], arr[101][101];

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> r;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arr[i][j] = inf;
			if(i==j) arr[i][j] = 0;			
		}
	}
	
	for(int i=1;i<=n;i++) cin >> item[i];
	for(int i=0;i<r;i++){
		int x, y, z;
		cin >> x >> y >> z;
		arr[y][x] = arr[x][y] = min(arr[x][y],z);
	}
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(arr[i][k] + arr[k][j] < arr[i][j]) arr[i][j] = arr[i][k] + arr[k][j];
	
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=n;j++) if(arr[i][j] <= m) sum += item[j];	
		ans = max(ans,sum);
	}

	cout << ans;
}
