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
string str,str2;
int main() {
    cin.sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cin.ignore(1);
	for(int i=0;i<n;i++){
		getline(cin,str);
		str2 += str;
		str2 += '\n';
	}
	smatch m;
	regex r("<a\\shref=\"([^\"]++)\"([^<>]*)>(<\\w>)*\\s?([^<>]*)<");
	while( regex_search(str2, m , r) ){
		cout << m[1].str() << ',' << m[4].str() << '\n';
		str2 = m.suffix();
	}
}