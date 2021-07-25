const n = 10;
solution(n);
function solution(n) {
  var answer = 0;

  for (let i = 2; i <= n; i++) {
    if (i === 2 || i === 3 || i === 5 || i === 7) {
      answer++;
      continue;
    }
    let flag = true;
    if (i % 2 === 0) continue;
    for (let j = 3; j <= Math.sqrt(i); j += 2) {
      if (i % j === 0) {
        flag = false;
        break;
      }
    }
    if (flag) answer++;
  }
  console.log(answer);
  return answer;
}
