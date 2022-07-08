var removeDuplicates = function(nums) {
  let ans = 0;
  for(let i = 0; i < nums.length; i++) {
    if(i < nums.length - 1 && nums[i] === nums[i + 1]) {
      continue;
    }
    nums[ans] = nums[i];
    ans++;
  }
  return ans;
};

removeDuplicates([1, 1, 2])