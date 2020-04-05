//make letter permutation in upper and lower case by dfs(backtracking)
//for example: input string s = 'a1B2'
//we need to output ['a1B2','a1b2','A1b2','A1B2']
//for each alphabet, we need to consider two case: upper or lower

let str = 'a1b2C3';
let res = [];

function letterCasePermutation(S){
    S = S.split('');
    dfs(res,S,0);
}

function dfs(res,S,i){
       if(i >= S.length){
           res.push(S.join(''));
           return;
       }
       if(S[i] >= 'A' && S[i] <= 'Z'){
           S[i] = String.fromCharCode(S[i].charCodeAt(0)+32);
           //S[i] += 32;
           dfs(res,S,i+1);
           S[i] = String.fromCharCode(S[i].charCodeAt(0)-32);
           //S[i] -= 32;
           dfs(res,S,i+1);
       }else if(S[i] >= 'a' && S[i] <= 'z'){
           //S[i] -= 32;
           S[i] = String.fromCharCode(S[i].charCodeAt(0)-32);
           dfs(res,S,i+1);
           //S[i] += 32;
           S[i] = String.fromCharCode(S[i].charCodeAt(0)+32);
           dfs(res,S,i+1);
       }else dfs(res,S,i+1);
}

letterCasePermutation(str);
console.log(res);