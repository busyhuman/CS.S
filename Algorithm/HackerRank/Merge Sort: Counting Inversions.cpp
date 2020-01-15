#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
long ans;
void arrange(vector<int>& arr, int base, int len){
    int mid = (base+len)/2;
    int start1 = base, start2 = mid+1;
    int *temp = new int[len-base+1], idx=0;

    while(start1 <= mid && start2 <= len){
        if(arr[start1] <= arr[start2]) temp[idx++] = arr[start1++];
        else {
            temp[idx++] = arr[start2++];
            ans += mid+1-start1;   
        }
    }
    while(start1 <= mid){
        temp[idx++] = arr[start1++];
    }
    while(start2 <= len){
        temp[idx++] = arr[start2++];
    }

    idx = 0;
    for(int i=base;i<=len;i++){
        arr[i] = temp[idx++];
    }
    
    delete(temp);
    temp = NULL;
}

void merge(vector<int>& arr, int base, int len){
    if(base < len){
        merge(arr,base,(base+len)/2);
        merge(arr,(base+len)/2+1,len);
        arrange(arr,base,len);
    }
}

// Complete the countInversions function below.
long countInversions(vector<int> arr) {
    ans = 0;
    merge(arr,0,arr.size()-1);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
