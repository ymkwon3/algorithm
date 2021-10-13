const s = "try hello world";

solution(s);

function solution(s) {
  var answer = "";
  let tmp = s.split(" ");
  for (let val of tmp) {
    for (let i = 0; i < val.length; i++) {
      if (i % 2 == 0) answer += val[i].toUpperCase();
      else answer += val[i].toLowerCase();
    }
    answer += " ";
  }
  answer = answer.slice(0, answer.length - 1);
  console.log(answer);
  return answer;
}
