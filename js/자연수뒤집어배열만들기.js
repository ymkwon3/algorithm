const n = 12345;
solution(n);
function solution(n) {
  var answer = [];
  while (true) {
    answer.push(n % 10);
    n = Math.floor(n / 10);
    if (n === 0) break;
  }
  console.log(answer);
  return answer;
}
