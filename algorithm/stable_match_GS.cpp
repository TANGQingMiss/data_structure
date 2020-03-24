#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    cout<<"input number of pairs: "<<endl;
    int num;
    cin>>num;

    cout<<"input preference for each woman: "<<endl;
    int womenPreference[num][num];
    for(int i = 0; i < num; i++){
        cout<<"input preference for "<<i+1<<" woman"<<endl;
        for(int j = 0; j < num; j++){
            int order;
            cin>>order;
            womenPreference[i][j] = order;
        }
    }
    cout<<"print women preferences as below: "<<endl;
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            cout<<womenPreference[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"input preference for each man: "<<endl;
    int menPreference[num][num];
    for(int i = 0; i < num; i++){
        cout<<"input preference for "<<i+1<<" man"<<endl;
        for(int j = 0; j < num; j++){
            int order;
            cin>>order;
            menPreference[i][j] = order;
        }
    }
    cout<<"print men preferences as below: "<<endl;
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            cout<<menPreference[i][j]<<" ";
        }
        cout<<endl;
    }

    int res[num][num];//initialize match result
    int matchedMen[num];//initialize man match
    int matchedWomen[num];//initialize woman match
    for(int i = 0; i < num; i++){
        matchedMen[i] = 0;
        matchedWomen[i] = 0;
        for(int j = 0; j < num; j++){
            res[i][j] = 0;
        }
    }

    int cnt = 0;//store matched pairs, == num means num pairs are all matched
    while(cnt < num){
        for(int man = 0; man < num; man++){
            //check man 
            for(int i = 0; i < num; i++){
                if(matchedMen[man] == 0){
                    int wish = menPreference[man][i] - 1;
                    if(matchedWomen[wish] == 0){//first preference isn't matched,directly match them
                        matchedMen[man] = 1;
                        matchedWomen[wish] = 1;
                        res[man][wish] = 1;
                        cnt++;
                        break;
                    }else{//else check women preference
                        //find current matched man for wish
                        int cur;
                        int idxCur;
                        int idxMan;
                        for(int k = 0; k < num; k++){
                            if(res[k][wish] == 1) cur = k;
                        }
                        for(int m = 0; m < num; m++){
                            if(womenPreference[wish][m] == cur+1) idxCur = m;
                            if(womenPreference[wish][m] == man+1) idxMan = m;
                        }
                        if(idxCur > idxMan){//idx > -> means preferences <
                            res[cur][wish] = 0;
                            matchedMen[man] = 1;
                            matchedWomen[wish] = 1;
                            res[man][wish] = 1;
                            matchedMen[cur] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout<<"after stable match: "<<endl;
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if(res[i][j] == 1){
                cout<<"matched pair with man "<<i+1<<" and woman "<<j+1<<endl;
                break;
            }
        }
    }

    return 0;
}