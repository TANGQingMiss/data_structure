//find the longest common subsequence
// by dynamic programming
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define MAX_LEN 100

char x[MAX_LEN];
char y[MAX_LEN];
int xLen = 0;
int yLen = 0;
char z[MAX_LEN];
int c[MAX_LEN][MAX_LEN];

void getLCS(){
	for(int i = 0; i <= xLen; i++){
		for(int j = 0; j <= yLen; j++){
			if(i == 0 || j == 0){
				c[i][j] = 0;
			}else if(i > 0 && j > 0 && x[i] == y[j]){
				c[i][j] = c[i-1][j-1] + 1;
			}else{
				c[i][j] = c[i-1][j]>c[i][j-1]?c[i-1][j]:c[i][j-1];
			}
		}
	}

	int num = 0;
	int i = xLen;
	int j = yLen;
	while(i != 0 && j != 0){
		if(c[i][j] != c[i-1][j]){
			z[++num] = x[i];
			j--;
			i--;
			while(c[i][j] == c[i][j-1]) j--;
		}else{
			i--;
		}
	}
}

int main(){
	cout<<"input char x length:"<<endl;
	cin>>xLen;
	cout<<"input each item of char x:"<<endl;
	for(int i = 1; i <= xLen; i++){
		cin>>x[i];
	}
	cout<<"input char y length:"<<endl;
	cin>>yLen;
	cout<<"input each item of char y:"<<endl;
	for(int i = 1; i <= yLen; i++){
		cin>>y[i];
	}

	getLCS();

	cout<<"number of LCS:"<<c[xLen][yLen]<<endl;
	cout<<"LCS is:";
	for(int i = c[xLen][yLen]; i > 0; i--){
		cout<<z[i]<<"";
	}
	cout<<endl;
}


