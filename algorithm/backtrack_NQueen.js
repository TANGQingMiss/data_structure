//solve N queen problem
//n queen in n*n grid, each col, each row and each diagonal should have only one queen
//for n == 1 only one solution, n==2 && n == 3 not possible
//we only consider n >= 4
    let res = [];
    let n = 4;
    let str = new Array(n).fill('.');
    let board = new Array(n).fill(str.join(''));
    solveNQueens(res,board,n);
    console.log(res);

    function solveNQueens(res,board,n) {
        backtrack(res,board,0,n);
    }

    function backtrack(res,board,row,n){
        if(row == n){
            let tmp = board.slice(0);
            res.push(tmp);
            return;
        }
        for(let col = 0; col < n; col++){
            if(!isValid(board,row,col)) continue;
            board[row] = board[row].substring(0,col)+'Q'+board[row].substring(col+1);
            backtrack(res,board,row+1,n);
            board[row] = board[row].substring(0,col)+'.'+board[row].substring(col+1);
        }
    }

    function isValid(board,row,col){
        let n = board.length;
        // check col
        for (let i = 0; i < n; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        // check right-up
        for (let i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        // check left-up
        for (let i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }

