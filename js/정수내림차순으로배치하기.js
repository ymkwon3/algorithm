const n = 118372;
solution(n);
function solution(n) {
  var answer = 0;
  let tmp = [];
  while (true) {
    tmp.push(n % 10);
    n = Math.floor(n / 10);
    if (n === 0) break;
  }

  tmp.sort(function (a, b) {
    if (a < b) return 1;
    if (a > b) return -1;
    return 0;
  }); // or reverse

  for (let i = 0; i < tmp.length; i++) {
    answer += tmp[i];
    if (i !== tmp.length - 1) answer *= 10;
  }

  console.log(answer);

  return answer;
}
