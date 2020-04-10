//make parenthese permutation
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

void backtrack(vector<string> &res, int left, int right, string s){
    if(left == 0 && right == 0) res.push_back(s);
    if(right > left) backtrack(res,left,right-1,s+")");
    if(left > 0) backtrack(res,left-1,right,s+"(");
}

void getPermutation(vector<string> &res, int n){
    string s = "";
    backtrack(res,n,n,s);//left ( n, right ) n
}

int main(){
    int n;
    cout<<"input parenthese pairs n : "<<endl;
    cin>>n;

    vector<string> res;
    getPermutation(res,n);

    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}