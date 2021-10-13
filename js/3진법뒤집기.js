const n = 45;
solution(n);

function solution(n) {
  var answer = 0;
  let cnt = 0;
  while (true) {
    if (Math.pow(3, cnt) > n) {
      break;
    } else cnt++;
  }
  let arr = [];
  for (let i = 0; i < cnt; i++) {
    arr[i] = 0;
  }
  cnt = 0;
  while (true) {
    if (Math.pow(3, cnt) > n) {
      arr[cnt - 1]++;
      n -= Math.pow(3, cnt - 1);
      cnt = 0;
    } else cnt++;
    if (n === 0) break;
  }
  arr.reverse();

  for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr[i]; j++) {
      answer += Math.pow(3, i);
    }
  }
  console.log(answer);
  return answer;
}
