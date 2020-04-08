//find all subsets for an array withotu duplicate elements
//for example [1,2,3] => [],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void backtrack(vector<int> &array, vector<vector<int> > &res, int start, vector<int> tmp){
    res.push_back(tmp);
    for(int i = start; i < array.size(); i++){
        tmp.push_back(array[i]);
        backtrack(array,res,i+1,tmp);
        tmp.pop_back();
    }
}

void getSubsets(vector<int> &array, vector<vector<int> > &res){
    vector<int> tmp;
    backtrack(array,res,0,tmp);
}

int main(){
    int n;
    cout<<"input positive integer number n : "<<endl;
    cin>>n;

    vector<int> array;
    cout<<"input each integer: "<<endl;
    for(int i = 0; i < n; i++){
        int tmp;
        cin>>tmp;
        array.push_back(tmp);
    }

    vector<vector<int> > res;
    getSubsets(array,res);
    cout<<"result subsets: "<<endl;
    for(int i = 0; i < res.size(); i++){
        if(res[i].size() == 0) cout<<"[]"<<endl;
        else{
            cout<<"[";
            for(int j = 0; j < res[i].size(); j++){
                cout<<res[i][j]<<" ";
            }
            cout<<"]"<<endl;    
        }
    }

    return 0;
}