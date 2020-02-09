//find the longest common subsequence
#include <iostream>
#include <string>
using namespace std;

int max(int a, int b){
    return a>b?a:b;
}
int Lcs(char a[], int n, char b[], int m){
    if(n == 0||m == 0)
        return 0;
    else if(a[n-1] == b[m-1]){
        return Lcs(a, n - 1, b, m - 1) + 1;
    }
    else
        return max(Lcs(a, n, b, m - 1),Lcs(a, n -1, b, m));
}
int main(){
    char str1[8] = {'p', 'r', 'o', 'g', 'r', 'a', 'm'};
    char str2[10] = {'a', 'l', 'g', 'o', 'r', 'i', 't', 'h', 'm'};
    cout<<Lcs(str1, 7, str2, 9)<<endl;
    return 0;
}


