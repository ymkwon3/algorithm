const d = [1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 5];
const budget = 20;

solution(d, budget);

function solution(d, budget) {
  var answer = 0;
  d = d.sort(function (a, b) {
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
  });
  console.log(d);
  for (let val of d) {
    budget -= val;
    if (budget < 0) {
      break;
    }
    answer++;
  }
  console.log(answer, budget);
  return answer;
}
