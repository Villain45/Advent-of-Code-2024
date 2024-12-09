#include<bits/stdc++.h>
using namespace std;
void resetSpaces(vector<int> store,vector<pair<int,int>> &spaces) {
    spaces.clear();
    int k = 0;
    while(k<store.size()) {
        if(store[k] == -1) {
            int st = k, counter = 0;
            while(store[k] == -1) {
                k++;counter++;
            }
            spaces.push_back({st,counter});
        } else {
            k++;
        }
    }
}
int main() {
    fstream file;
    file.open("input.txt",ios::in);
    string line,input;
    while(getline(file,line)) {
        input = line;
    }
    int file_id = 0;
    vector<int> store;
    vector<pair<int,int>> spaces, numbers;
    for(int i=0;i<input.size();i++) {
        int sz = input[i]-'0';
        int n = store.size();
        if(i%2==0) {
            numbers.push_back({n,sz});
            for(int j=0;j<sz;j++) {
                store.push_back(file_id);
            }
            file_id++;
        } else {
            spaces.push_back({n,sz});
            for(int j=0;j<sz;j++) {
                store.push_back(-1);
            }
        }
    }
    
    // Part 1
    // int l=0,r=store.size()-1;
    // while(l<=r) {
    //     while(store[l] != -1) l++;
    //     while(store[r] == -1) r--;
    //     while(store[l] == -1 and store[r]!=-1 and l<=r) {
    //         swap(store[l++],store[r--]);
    //     }
    // }

    // Part 2
    for(int i=numbers.size()-1;i>=0;i--) {
        for(int j=0;j<spaces.size();j++) {
            auto num = numbers[i];
            auto space = spaces[j];
            if(space.first+space.second > num.first) break;
            if(space.second>=num.second) {
                int count = num.second,spaceStart = space.first,numberEnd = num.first + num.second - 1;
                while(count--) {
                    swap(store[spaceStart++],store[numberEnd--]);
                }
                resetSpaces(store,spaces);
                break;
            }
        }
    }
    long long ans = 0;
    for(int i=0;i<store.size();i++) {
        if(store[i]!=-1) 
            ans+=store[i]*i;
    }
    cout<<ans;
}