const num = 0;
solution(num);
function solution(num) {
  var answer = "";
  if (num % 2 === 0) {
    answer = "Even";
  } else {
    answer = "Odd";
  }
  console.log(answer);
  return answer;
}
