const N = 5;
const stages = [2, 1, 2, 6, 2, 4, 3, 3];
solution(N, stages);
function solution(N, stages) {
  var answer = [];
  let tmp = [];
  for (let i = 1; i <= N; i++) {
    let obj = new Object();
    let all = 0;
    let fail = 0;
    for (let j = 0; j < stages.length; j++) {
      if (stages[j] >= i) {
        all++;
        if (stages[j] === i) fail++;
      }
    }
    obj.first = i;
    obj.second = fail / all;
    tmp.push(obj);
  }
  tmp.sort((a, b) => {
    if (a.second === b.second)
      return a.first > b.first ? 1 : a.first < b.first ? -1 : 0;
    else return a.second > b.second ? -1 : a.second < b.second ? 1 : 0;
  });
  console.log(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
  for (let val of tmp) {
    answer.push(val.first);
  }
  return answer;
}
