//滑动窗口方法解决字符串问题


//3: 给定S与P，找出S中所有是P的字母异位词的子串，返回起始索引
//eg: S = "cbaebabacd" T = "abc" output: [0,6]

function findAnagrams(s,p){
    const map = new Array(26).fill(0);
    for(let i = 0; i < p.length; i++){
        map[p[i].charCodeAt(0)-97]++;
    }
    const r = [];
    for(let i = 0, j = 0; i < s.length; i++){
        const c = s[i].charCodeAt(0)-97;
        map[c]--;
        while(map[c] < 0){
            const c2 = s[j].charCodeAt(0)-97;
            j++;
            map[c2]++;
        }
        if(i-j+1 == p.length){
            r.push(j);
        }
    }
    return r;
}

let s = "cbaebabacd";
let p = "abc";
let res = findAnagrams(s,p);
console.log(res);
