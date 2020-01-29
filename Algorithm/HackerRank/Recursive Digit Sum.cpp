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
string temp = "";
long long superDigit(string s, int k) {
    bool check = false;
    while(true){
        int len = s.size();
        if(len <= 1) break;

        long long sum = 0;

        for(int i=0;i<len;i++){
            sum += (s[i] - '0');
        }
		if(!check){
			check = true;
			sum *= k;
		}
        s = "";
        while(sum){
            s += (sum%10+'0');
            sum /= 10;
        }
    }
    return s[0] - '0';
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int k;
    cin >> s >> k;

    cout << superDigit(s, k);
}
