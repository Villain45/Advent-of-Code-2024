#include<bits/stdc++.h>
using namespace std;
int counter=0;
vector<char> thing = {'X','M','A','S'};
// void canfindXMAS(vector<vector<char>> &mat,int i,int j) {
//     int n=mat.size();
//     if(i-3>=0 and j-3>=0) {
//         string temp;
//         int k=i,l=j,runs=4,m=0;
//         while(runs--) {
//             if(mat[k][l]!=thing[m])
//                 break;
//             temp+=mat[k--][l--];
//             m++;
//         }
//         if(temp=="XMAS") counter++;
//     }
//     if(i+3<n and j+3<n) {
//         string temp;
//         int k=i,l=j,runs=4,m=0;
//         while(runs--) {
//             if(mat[k][l]!=thing[m])
//                 break;
//             temp+=mat[k++][l++];
//             m++;
//         }
//         if(temp=="XMAS") counter++;
//     }
//     if(i+3<n) {
//         string temp;
//         int k=i,l=j,runs=4,m=0;
//         while(runs--) {
//             if(mat[k][l]!=thing[m])
//                 break;
//             temp+=mat[k++][l];
//             m++;
//         }
//         if(temp=="XMAS") counter++;
//     }
//     if(j+3<n) {
//         string temp;
//         int k=i,l=j,runs=4,m=0;
//         while(runs--) {
//             if(mat[k][l]!=thing[m])
//                 break;
//             temp+=mat[k][l++];
//             m++;
//         }
//         if(temp=="XMAS") counter++;
//     }
//     if(i-3>=0 and j+3<n) {
//         string temp;
//         int k=i,l=j,runs=4,m=0;
//         while(runs--) {
//             if(mat[k][l]!=thing[m])
//                 break;
//             temp+=mat[k--][l++];
//             m++;
//         }
//         if(temp=="XMAS") counter++;
//     }
//     if(i+3<n and j-3>=0) {
//         string temp;
//         int k=i,l=j,runs=4,m=0;
//         while(runs--) {
//             if(mat[k][l]!=thing[m])
//                 break;
//             temp+=mat[k++][l--];
//             m++;
//         }
//         if(temp=="XMAS") counter++;
//     }
//     if(i-3>=0) {
//         string temp;
//         int k=i,l=j,runs=4,m=0;
//         while(runs--) {
//             if(mat[k][l]!=thing[m])
//                 break;
//             temp+=mat[k--][l];
//             m++;
//         }
//         if(temp=="XMAS") counter++;
//     }
//     if(j-3>=0) {
//         string temp;
//         int k=i,l=j,runs=4,m=0;
//         while(runs--) {
//             if(mat[k][l]!=thing[m])
//                 break;
//             temp+=mat[k][l--];
//             m++;
//         }
//         if(temp=="XMAS") counter++;
//     }
// }
void canfindMAS(vector<vector<char>> &mat,int i,int j) {
    int n=mat.size();
    bool flag1 = false,flag2=false;
    if(i-1>=0 and j-1>=0 and i+1<n and j+1<n) {
        string temp = string(1,mat[i-1][j-1]) + "A" + string(1,mat[i+1][j+1]);
        if(temp=="MAS" or temp=="SAM") flag1 = true;
    }
    if(i-1>=0 and j+1<n and i+1<n and j-1>=0) {
        string temp = string(1,mat[i-1][j+1]) + "A" + string(1,mat[i+1][j-1]);
        if(temp=="MAS" or temp=="SAM") flag2 = true;
    }
    if(flag1 and flag2) counter++;
}
int main() {
    fstream file;
    file.open("input.txt",ios::in);
    string line;
    vector<vector<char>> mat;
    while(getline(file,line)) {
        vector<char> temp;
        for(int j=0;j<line.size();j++) {
            temp.push_back(line[j]);
        }
        mat.push_back(temp);
    }
    for(int i=0;i<mat.size();i++) {
        for(int j=0;j<mat[i].size();j++) {
            if(mat[i][j] == 'A') {
                canfindMAS(mat,i,j);
            }
        }
    }
    cout<<counter;
}