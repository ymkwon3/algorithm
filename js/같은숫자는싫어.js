const arr = [1, 1, 3, 3, 0, 1, 1];
solution(arr);
function solution(arr) {
  var answer = [];
  let pre = arr[0];
  answer.push(pre);
  for (let val of arr) {
    if (val !== pre) {
      answer.push(val);
      pre = val;
    }
  }
  return answer;
}
