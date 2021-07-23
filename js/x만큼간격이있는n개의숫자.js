const x = 2;
const n = 5;
solution(2, 5);
function solution(x, n) {
  var answer = [];
  for (let i = 1; i <= n; i++) {
    answer.push(x * i);
  }
  console.log(answer);
  return answer;
}
