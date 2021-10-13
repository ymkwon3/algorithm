const x = 13;
solution(x);
function solution(x) {
  var answer = true;
  let value = x;
  let sum = 0;
  while (true) {
    sum += value % 10;
    value = Math.floor(value / 10);
    if (value === 0) break;
  }
  if (x % sum === 0) answer = true;
  else answer = false;
  console.log(answer);
  return answer;
}
