#include<bits/stdc++.h>
using namespace std;
int counter=0;
vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
bool isValid(int i,int j,int n) {
    return i>=0 and i<n and j>=0 and j<n;
}
void solve(vector<vector<int>> &mat,int i,int j,int curVal) {
    if(curVal == 9) {
        // Part 1
        // mat[i][j] = -1;
        counter++;
        return;
    }
    for(int k=0;k<dirs.size();k++) {
        int newI = i+dirs[k][0];
        int newJ = j+dirs[k][1];
        if(isValid(newI,newJ,mat.size()) and mat[newI][newJ] == curVal + 1) {
            solve(mat,newI,newJ,curVal+1);
        }
    }
}
int main() {
    fstream file;
    file.open("input.txt",ios::in);
    string line;
    vector<vector<int>> mat;
    while(getline(file,line)) {
        vector<int> temp;
        for(int i=0;i<line.size();i++) {
            temp.push_back(line[i]-'0');
        }
        mat.push_back(temp);
    }
    for(int i=0;i<mat.size();i++) {
        for(int j=0;j<mat[i].size();j++) {
            if(mat[i][j] == 0) {
                // Part 1
                // vector<vector<int>> duplicate = mat;
                solve(mat,i,j,0);
            }
        }
    }
    cout<<counter;
}