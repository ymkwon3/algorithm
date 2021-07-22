const arr = [1, 2, 3, 4];
solution(arr);
function solution(arr) {
  var answer = 0;
  for (let val of arr) {
    answer += val;
  }
  answer = answer / arr.length;
  console.log(answer);
  return answer;
}
