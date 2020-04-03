//this file is used to solve dynamic programming for bag question
//bag question: we have [a,b,c,d...] objects, their weight are [wa,wb,wc,wd...],their value are [va,vb,vc,vd,...]
//for a given size bag, find solution to make the values in the bag reach maximum while total weight <= bag size

#include<iostream>
#include <math.h>
#include <cstring>
using namespace std;

int dpBag_01(int size, int weiObjects[], int valObjects[], int len){
    int dp[len+1][size+1];
    //dp[i][j] means for taking i+1 th objects(1-len), for size j+1 maximum value
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= len; i++){
        for(int j = 1; j <= size; j++){
            if(j >= weiObjects[i-1]){
                //if j >= weiObjects[i-1] -> choose max between choosing this one or not
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weiObjects[i-1]] + valObjects[i-1]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<"show current dp matrix"<<endl;
    for(int i = 0; i <= len; i++){
        for(int j = 0; j <= size; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[len][size];

}


int dpBag_complete(int size, int weiObjects[], int valObjects[], int len){
    int dp[size+1];
    //dp[i][j] means for taking i+1 th objects(1-len), for size j+1 maximum value
    memset(dp,0,sizeof(dp));
    for(int i = 0; i < len; i++){
        for(int j = weiObjects[i]; j <= size; j++){
            dp[j] = max(dp[j],dp[j-weiObjects[i]]+valObjects[i]);
        }
    }
    cout<<"show current dp matrix"<<endl;
    for(int i = 0; i <= size; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return dp[size];
}

int main(){
	int len;
	cout<<"input number of objects:"<<endl;
	cin>>len;

    int numObjects[len];
    cout<<"input number of each object"<<endl;
    for(int i = 0; i < len; i++){
        cin>>numObjects[i];
    }
    
    int weiObjects[len];
    cout<<"input weight of each object"<<endl;
    for(int i = 0; i < len; i++){
        cin>>weiObjects[i];
    }

    int valObjects[len];
    cout<<"input value of each object"<<endl;
    for(int i = 0; i < len; i++){
        cin>>valObjects[i];
    }

    int size;
    cout<<"input bag maximum size:"<<endl;
    cin>>size;
    
    cout<<"for 0 / 1 objects, maximum value is: "<<dpBag_01(size,weiObjects,valObjects,len)<<endl;
    cout<<"for non-limited objects, maximum value is: "<<dpBag_complete(size,weiObjects,valObjects,len)<<endl;
    return 0;
}



