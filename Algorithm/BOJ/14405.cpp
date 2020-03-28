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
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	regex r("^(pi|ka|chu)");
	smatch m;
	string str;
	cin >> str;
	while(true ){
		if(regex_search(str,m,r) == true) str = m.suffix();
		else break;
	}
	if(str == "") cout << "YES";
	else cout << "NO";
}
