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

int getLen(long long su){
	if(!su) return 0;
	return getLen(su/2)+1;
}

long long getAns(long long su, int len){
	long long bit = 1, dan=1, ans=0;
	
	while(len--){
		if(su & bit) ans += dan*(su/(dan*2)) + (su % dan) + 1;
		else ans += dan*(su/(dan*2));
		dan = dan << 1;
		bit = bit << 1;
	}
	return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a, b;
	cin >> a >> b;
	int alen = getLen(a), blen = getLen(b);
	cout << getAns(b, blen) - getAns(a-1, alen);
}
