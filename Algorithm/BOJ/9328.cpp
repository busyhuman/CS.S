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
int t,n,m,ans,dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
char arr[103][103];
string keys;
vector< pair<int,int> > alpha[28];
bool key[28];

void bfs(){
	bool visit[103][103]={false};
	queue<int> y, x;
	y.push(0);
	x.push(0);
	visit[0][0] = true;
	
	while( !y.empty() ){
		int yf = y.front(), xf = x.front();
		y.pop(), x.pop();
	//	cout << yf << ' ' << xf << '\n';
	//	printArr();
		
		for(int i=0;i<4;i++){
			int imsiy = yf+dy[i], imsix = xf+dx[i];
			
			if(imsiy < 0 || imsiy >= n+2 || imsix < 0 || imsix >= m+2) continue;
			
			if(visit[imsiy][imsix]) continue;
			visit[imsiy][imsix] = true;
			
			char& temp = arr[imsiy][imsix];
			if(temp == '*') continue;
			if(temp >= 'A' && temp <= 'Z' && !key[temp-'A']) continue;
			
			if(temp >= 'a' && temp <= 'z'){
				key[temp-'a'] = true;
				int len = alpha[temp-'a'].size();

				for(int k=0;k<len;k++){
					int f = alpha[temp-'a'][k].first, s = alpha[temp-'a'][k].second;
					if(!visit[f][s]) continue;
					y.push(f);
					x.push(s);
					arr[f][s] = '.';
					visit[f][s] = true;
				}
			}

			if(temp == '$') ans++;
			temp = '.';
			y.push(imsiy);
			x.push(imsix);
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=m+1;j++)
				arr[i][j] = '.';
		ans=0;
		memset(key,false,sizeof(key) );
		for(int i=0;i<28;i++) alpha[i].clear();
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> arr[i][j];
				if(arr[i][j] >= 'A' && arr[i][j] <= 'Z') alpha[arr[i][j]-'A'].push_back( make_pair(i,j) );
			}
		}
		
		cin >> keys;
		for(char c : keys){
			if(c == '0') continue;
			key[c-'a'] = true;
		}		
		bfs();
		cout << ans << '\n';
	}
}
