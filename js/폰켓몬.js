const nums = [3, 1, 2, 3];

function solution(nums) {
  var answer = 0;
  nums = nums.sort();
  let pre = nums[0];
  const max = nums.length / 2;
  answer++;
  for (let val of nums) {
    if (pre !== val && answer < max) {
      pre = val;
      answer++;
    }
  }
  console.log(answer);
  return answer;
}

solution(nums);
