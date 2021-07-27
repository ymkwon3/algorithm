const n = 11;
solution(n);

function country(num) {
  let result = "";
  let div = Math.ceil(num / 3) - 1;
  if (div !== 0) {
    if (div > 3) result += country(div);
    else {
      if (div === 3) div = 4;
      result += div;
    }
  }

  let rem = num % 3;
  if (rem === 0) rem = 4;
  result += rem;
  return result;
}
function solution(n) {
  var answer = "";
  answer = country(n);
  console.log(answer);
  return answer;
}

/*
1 1
2 2
3 4

4 11
5 12
6 14

7 21
8 22
9 24

10 41
11 42
12 44

13 111
14 112
15 114

*/
