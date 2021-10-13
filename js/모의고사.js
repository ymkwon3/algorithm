function compare(test, ans) {
  let ts = 0;
  for (let i = 0; i < ans.length; i++) {
    if (test[i] == ans[i]) {
      ts++;
    }
  }
  return ts;
}

function solution(answers) {
  var answer = [];
  var tmp = [];
  var first = [];
  var second = [];
  var third = [];
  for (let i = 0; i < 10000; i++) {
    first.push(1, 2, 3, 4, 5);
    i += 4;
  }
  for (let i = 0; i < 10000; i++) {
    second.push(2, 1, 2, 3, 2, 4, 2, 5);
    i += 7;
  }
  for (let i = 0; i < 10000; i++) {
    third.push(3, 3, 1, 1, 2, 2, 4, 4, 5, 5);
    i += 9;
  }
  tmp.push(compare(first, answers));
  tmp.push(compare(second, answers));
  tmp.push(compare(third, answers));
  let maxi = Math.max(...tmp);
  for (let i in tmp) {
    console.log(tmp[i], maxi);
    if (tmp[i] == maxi) {
      answer.push(parseInt(i) + 1);
    }
  }

  return answer;
}

solution([1, 2, 3, 4, 5]);
