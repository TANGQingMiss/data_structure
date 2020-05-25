//滑动窗口方法解决字符串问题

//1: 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度

// 用 i 指向卷尺头部，用 j 指向卷尺尾部，k 则作为子串中字符的索引
// 每次对比开始时，用 i 的值初始化 k，当找到重复字符时，又将 k + 1的值赋给 i，即直接将窗口的左侧移动到重复字符的下一个字符位置
// 窗口右侧每次向右滑动一格，如果窗口中子串包含窗口右侧下一个字符，左侧滑动一格或多格 
// 与枚举法相比，由于利用了子串中重复字符的位置，直接将窗口左侧跳到该字符的下一个位置，每次检查出重复减少了 k - i 个子串的自检
function lengthOfLongestSubstring(s){
    let i = 0, j = 0;
    let maxLen = 0, curLen = 0;
    let len = s.length;
    if(len == 0) return 0;
    for(; j < len && len - i > maxLen; j++){
        curLen++;
        for(let k = i; k <= j; k++){
            if(s[k] == s[j+1]){
                if(curLen > maxLen){
                    maxLen = curLen;
                }
                i = k + 1;
                curLen = j - i + 1;
                break;
            }
        }
    }
    if(curLen > maxLen) return curLen;
    else return maxLen;
}

let s = "abcdbardec";
let res = lengthOfLongestSubstring(s);
console.log(res);