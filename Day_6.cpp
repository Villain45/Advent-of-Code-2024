#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string> mp = {{"up","right"},{"down","left"},{"left","up"},{"right","down"}};
int main() {
    fstream file;
    file.open("input.txt",ios::in);
    string line;
    vector<vector<char>> mat;
    int j=0,startRow,startCol;
    string startDir = "up";
    while(getline(file,line)) {
        vector<char> temp;
        for(int i=0;i<line.size();i++) {
            temp.push_back(line[i]);
            if(line[i] == '^') {
                startRow = j;
                startCol = i;
            }
        }
        j++;
        mat.push_back(temp);
    }
    int curRow = startRow, curCol = startCol;
    string curDir = startDir;
    set<pair<int,int>> s;
    while(true) {
        if(curDir == "up") {
            int i=curRow;
            while(i>=0) {
                if(mat[i][curCol]=='#') {
                    curRow = ++i;
                    curDir = mp[curDir];
                    break;
                }
                s.insert(make_pair(i,curCol));
                cout<<curDir<<" "<<i<<" "<<curCol<<endl;
                i--;
            }
            if(i<0) break;
        }
        if(curDir == "right") {
            int j=curCol;
            while (j<mat.size()) {
                if(mat[curRow][j]=='#') {
                    curCol = --j;
                    curDir = mp[curDir];
                    break;
                }
                s.insert(make_pair(curRow,j));
                cout<<curDir<<" "<<curRow<<" "<<j<<endl;
                j++;
            }
            if(j==mat.size()) break; 
        }
        if(curDir == "down") {
            int i=curRow;
            while(i<mat.size()) {
                if(mat[i][curCol]=='#') {
                    curRow = --i;
                    curDir = mp[curDir];
                    break;
                }
                s.insert(make_pair(i,curCol));
                cout<<curDir<<" "<<i<<" "<<curCol<<endl;
                i++;
            }
            if(i==mat.size()) break;
        }
        if(curDir == "left") {
            int j=curCol;
            while (j>=0) {
                if(mat[curRow][j]=='#') {
                    curCol = ++j;
                    curDir = mp[curDir];
                    break;
                }
                s.insert(make_pair(curRow,j));
                cout<<curDir<<" "<<curRow<<" "<<j<<endl;
                j--;
            }
            if(j<0) break;
        }
    }
    cout<<s.size();
}