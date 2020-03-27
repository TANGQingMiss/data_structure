#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

void greedyChanges(int cur[], int n, int target, int res[]){
    int max;
    int idx = n - 1;//note idx of current max
    while(target > 0){
        for(int i = idx; i >= 0; i--){
            if(cur[i] <= target){
                max = cur[i];
                idx = i;
                break;
            }
        }
        res[idx]++;
        target -= max;
    }
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

    int result[num];//initial set to record changes
    for(int i = 0; i < num; i++){
        result[i] = 0;
    }
    greedyChanges(currency,num,target,result);
    cout<<"change result is: "<<endl;
    for(int i = 0; i < num; i++){
        if(result[i] != 0){
            cout<<result[i]<<" numbers of currency "<<currency[i]<<endl;
        }
    }
    return 0;
}