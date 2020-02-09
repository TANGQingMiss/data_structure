/**
 * @param {number[]} nums
 * @return {number}
 */
var longestCommonSubsequence = function(nums1,nums2) {
    
    function lcs(nums1,nums2,m,n){
        if(m == 0 || n == 0){
            return 0;
        }else if(nums1[m - 1] == nums2[n - 1]){
            return lcs(nums1,nums2,m-1,n-1)+1;
        }else{
            return Math.max(lcs(nums1,nums2,m-1,n),lcs(nums1,nums2,m,n-1));
        }
    }
    return lcs(nums1,nums2,nums1.length,nums2.length);
};