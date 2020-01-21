#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
long long solve(long long n) {
    vector<long long> arr;
    arr.push_back(9);
    long long su = 9;
    for(int i=0;i<12;i++){
        su *= 10;
        
        int len =arr.size();
        arr.push_back(su);
        for(int j=0;j<len;j++){
            arr.push_back(su+arr[j]);
        }
    }
    int len = arr.size();

    for(int i=0;i<len;i++){
        if(arr[i] >= n && !(arr[i]%n))
            return arr[i];
    }
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long long result = solve(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
