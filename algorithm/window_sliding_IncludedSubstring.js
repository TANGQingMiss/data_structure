//滑动窗口方法解决字符串问题


//1: 给定S与T，找出S中包含T所有字母的最小字串
//eg: S = "ADOBCECODEBANC" T = "ABC" output: "BANC"

function findMinimumIncludedSubstring(s,t){
    const map = {};
    for(let i = 0; i < t.length; i++){
        if(map[t[i]]){
            map[t[i]]++;
        }else{
            map[t[i]] = 1;
        }
    }

    let left = 0;
    let right = 0;
    let cnt = t.length;
    let max = Number.MAX_SAFE_INTEGER;
    let res = s;

    while(right < s.length){
        if(map[s[right]] > 0){
            cnt--;
        }
        map[s[right]]--;
        right++;

        while(cnt == 0){
            if(right - left < max){
                max = right - left;
                res = s.slice(left,right);
            }
            map[s[left]]++;
            if(map[s[left]] > 0){
                cnt++;
            }
            left++;
        }
    }
    return max == Number.MAX_SAFE_INTEGER ? "" : res;
}

let s = "ADOBECODEBANC";
let t = "ABC";
let res = findMinimumIncludedSubstring(s,t);
console.log(res);
