
var longestCommonSubsequence = function(str1,str2) {
    let len1 = str1.length;
    let len2 = str2.length;
    let res = new Array(len1+1);
    for(let i = 0; i < res.length;i++){
        res[i] = new Array(str2.length+1);
    }

    for(let i = 0; i <= len1; i++){
        for(let j = 0; j <= len2; j++){
            if(i == 0 || j == 0){
                res[i][j] = 0;
            }else if(i > 0 && j > 0 && x[i] == y[j]){
                res[i][j] = res[i-1][j-1] + 1;
            }else{
                c[i][j] = c[i-1][j]>c[i][j-1]?c[i-1][j]:c[i][j-1];
            }
        }
    }

    return res[len1][len2];
}
};