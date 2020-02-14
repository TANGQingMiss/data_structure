var uniquify = function(nums){
    if(nums == null || nums.length <= 1) return nums;
    let unique = 0;
    for(let i = 0; i < nums.length; i++){
        if(nums[i+1] != nums[i]){
            unique++;
            nums[unique] = nums[i+1];
        }
    }

    return nums.splice(0,unique+1);
};
