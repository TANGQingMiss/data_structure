//solve N queen problem
//n queen in n*n grid, each col, each row and each diagonal should have only one queen
//for n == 1 only one solution, n==2 && n == 3 not possible
//we only consider n >= 4
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isValid(vector<string>& board, int row, int col) {
    int n = board.size();
    // check col
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q')
            return false;
    }
    // check right-up
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }
    // check left-up
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

void backtrack(vector<vector<string> > &res, vector<string> &board, int row){
    if (row == board.size()) {
        res.push_back(board);
        return;
    }
    int n = board[row].size();
    for (int col = 0; col < n; col++) {
        if (!isValid(board, row, col)) 
            continue;
        board[row][col] = 'Q';
        backtrack(res, board, row + 1);
        board[row][col] = '.';
    }
}

void getNQueens(vector<vector<string> > &res, int n){
    vector<string> board(n, string(n, '.'));
    backtrack(res,board,0);
}

int main(){
    int n;
    cout<<"input positive integer number n >= 4: "<<endl;
    cin>>n;

    vector<vector<string> > res;

    getNQueens(res,n);
    for(int i = 0; i < res.size(); i++){
        cout<<"the "<<i+1<<" th solution is: "<<endl;
        cout<<"[ ";
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<" ]"<<endl;
    }
    return 0;
}