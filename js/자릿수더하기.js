const N = 123;

solution(N);

function solution(n) {
  var answer = 0;
  while (true) {
    answer += n % 10;
    console.log(answer);
    n = Math.floor(n / 10);
    if (n < 1) break;
  }

  console.log(answer);
  return answer;
}
