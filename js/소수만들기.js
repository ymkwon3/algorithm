const nums = [1, 2, 3, 4];
solution(nums);
function solution(nums) {
  var answer = 0;
  let sums = [];
  for (let i = 0; i < nums.length - 2; i++) {
    for (let j = i + 1; j < nums.length - 1; j++) {
      for (let k = j + 1; k < nums.length; k++) {
        sums.push(nums[i] + nums[j] + nums[k]);
      }
    }
  }

  for (let val of sums) {
    let flag = true;
    if (val % 2 === 0) continue;
    for (let i = 3; i <= Math.sqrt(val); i += 2) {
      if (val % i === 0) {
        flag = false;
        break;
      }
    }
    if (flag) answer++;
  }
  console.log(answer);

  return answer;
}
