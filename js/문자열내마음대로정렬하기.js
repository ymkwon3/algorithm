const strings = ["sun", "bed", "car"];
const n = 1;

solution(strings, n);

function solution(strings, n) {
  var answer = [];
  let tmp = new Array();

  for (let val of strings) {
    let pair = new Object();
    pair.pivot = val[n];
    pair.word = val;
    tmp.push(pair);
  }
  tmp.sort(function (a, b) {
    if (a.pivot > b.pivot) return 1;
    if (a.pivot < b.pivot) return -1;
    if (a.pivot === b.pivot) {
      if (a.word > b.word) return 1;
      if (a.word < b.word) return -1;
    }
    return 0;
  });

  for (let val of tmp) {
    answer.push(val.word);
  }

  console.log(answer);

  return answer;
}
