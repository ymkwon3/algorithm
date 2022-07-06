var twoSum = function(nums, target) {
  const compare = [];
  let subNum, ansIdx;
  for(let i = 0; i < nums.length; i++) {
    subNum = target - nums[i];
    
    ansIdx = compare.findIndex(e => e === nums[i]);
    if(ansIdx !== -1) {
      return [ansIdx, i];
    }

    compare.push(subNum);
  }
};

twoSum([2, 7, 11, 15], 9)