#include <iostream>
#include <string>
#include <math.h>
#include<algorithm>
using namespace std;

int dpChanges(int cur[], int n, int target){
    int dp[target+1];
    dp[0] = 0;
    for(int i = 1; i <= target; i++){
        dp[i] = 500;//suppose a maximum demand for 500
        for(int j = 0; j < n; j++){
            if(cur[j] == i){
                dp[i] = 1;
                break;
            }
        }
    }
    for(int i = 1; i <= target; i++){
        if(dp[i] == 1){
            cout<<"changes for "<<i<<" is "<<dp[i]<<endl;
        }
        else{
            for(int j = 0; cur[j] < i && j < n; j++){
                dp[i] = min(dp[i],dp[i - cur[j]]+1);
            }
            cout<<"changes for "<<i<<" is "<<dp[i]<<endl;
        }

    }
    return dp[target];
}

int main(){
    cout<<"input number of types of currency: "<<endl;
    int num;
    cin>>num;

    cout<<"input each type of currency: "<<endl;
    int currency[num];
    for(int i = 0; i < num; i++){
        int money;
        cin>>money;
        currency[i] = money;
    }

    cout<<"input needed changes: "<<endl;
    int target;
    cin>>target;

    cout<<"minimum change result is: "<<dpChanges(currency,num,target)<<endl;
    
    return 0;
}