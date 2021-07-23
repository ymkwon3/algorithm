const num = 1;
solution(num);
function solution(num) {
  var answer = 0;
  if (num === 1) answer = 1;
  else {
    while (true) {
      answer++;
      if (num % 2 === 0) {
        num /= 2;
      } else {
        num = num * 3 + 1;
      }
      if (num === 1) break;
      if (answer >= 500) {
        answer = -1;
        break;
      }
    }
  }

  console.log(answer);
  return answer;
}
