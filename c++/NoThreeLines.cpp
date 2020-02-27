//game: if three elements are the same - delete them
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void deleteThree(vector<string>& s){
    if(s.size() <= 2) return;
    for(int i = 0; i < s.size() - 2; ){
        if(s[i] == s[i+1] && s[i+1] == s[i+2]){
            s.erase(s.begin()+i,s.begin()+i+3);
            i = 0;
            if(s.size() <= 2) break;
        }else{
            i++;
        }
    }
}

void addChar(vector<string>& s, int& position, string& r){
    s.insert(s.begin()+position,r);
    deleteThree(s);
}



int main(){
    vector<string> s;
    int originLen;
    cout<<"please input original length: "<<endl;
    cin>>originLen;
    cout<<"please input initial sequence: "<<endl;
    for(int i = 0; i < originLen; i++){
        string str;
        cin>>str;
        s.push_back(str);
    }
  
	int n;
	cout<<"input operate times:"<<endl;
	cin>>n;

    for(int i = 1; i <= n; i++){
        string cur;
        int where;
        cout<<"input insert position: "<<endl;
        cin>>where;
        cout<<"input char: "<<endl;
        cin>>cur;
        addChar(s,where,cur);
        cout<<"result is: ";
        if(s.size() == 0){
            cout<<'-';
        }else{
            for(int j = 0; j < s.size(); j++){
                cout<<s[j];
            }
        }
        cout<<endl;
    }    
    return 0;
}



