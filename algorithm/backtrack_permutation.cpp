//find all permutation by back tracking
//input n = 3, -> out put 123 132 213 231 312 321
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void backtrack(int n, vector<int> &origin, vector<vector<int> > &res, int start, int end){
    if(start == end){
        res.push_back(origin);
    }else{
        for(int i = start; i <= end; i++){
            int tmp = origin[i];
            origin[i] = origin[start];
            origin[start] = tmp;
            backtrack(n,origin,res,start+1,end);
            int tmp1 = origin[i];
            origin[i] = origin[start];
            origin[start] = tmp1;
        }
    }
}

void numberPermutation(int n, vector<int> &origin, vector<vector<int> > &res){
    if(n == 1){
        res.push_back(origin);
        return;
    }
    backtrack(n,origin,res,0,n-1);
    return;

}

int main(){
    int n;
    cout<<"input positive integer number n : "<<endl;
    cin>>n;

    vector<int> origin;
    cout<<"input each integer: "<<endl;
    for(int i = 0; i < n; i++){
        int tmp;
        cin>>tmp;
        origin.push_back(tmp);
    }

    vector<vector<int> > res;
    numberPermutation(n,origin,res);
    cout<<"result permutation is: "<<endl;
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;     
    }

    return 0;
}