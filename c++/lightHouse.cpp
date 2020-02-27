//calculate how many houses can light each other
#include<iostream>
using namespace std;

int main(){
    cout<<"input number of light houses: "<<endl;
    int num;
    cin>>num;
    int position[num][2];
    int res = 0;
    for(int i = 0; i < num; i++){
        cout<<"input position for "<<i+1<<" point"<<endl;
        cout<<"input x position: "<<endl;
        cin>>position[i][0];
        cout<<"input y position: "<<endl;
        cin>>position[i][1];
    }

    for(int i = 0; i < num - 1; i++){
        for(int j = i + 1; j < num; j++){
            if(float(position[j][1] - position[i][1]) / float(position[j][0] - position[i][0]) > 0){
                res++;
            }
        }
    }
    cout<<"pairs of light houses that can light each other is :"<<res<<endl;
    return 0;
}

