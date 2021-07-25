const arr = [5, 9, 7, 10];
const divisor = 5;
solution(arr, divisor);
function solution(arr, divisor) {
  var answer = [];
  arr.sort((a, b) => {
    return a > b ? 1 : a < b ? -1 : 0;
  });
  for (let val of arr) {
    if (val % divisor === 0) answer.push(val);
  }
  if (answer.length === 0) answer.push(-1);
  return answer;
}
