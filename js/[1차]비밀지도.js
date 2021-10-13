const n = 2;
const arr1 = [0, 0];
const arr2 = [0, 0];
solution(n, arr1, arr2);

function toBinary(num, n) {
  let result = new Array(n);
  for (let i = 0; i < n; i++) {
    result[i] = " ";
  }

  let cnt = 0;
  while (true) {
    if (num <= 0) break;
    if (Math.pow(2, cnt) > num) {
      if (cnt - 1 < 0) {
        result[cnt] = "#";
        num -= Math.pow(2, cnt);
        cnt = 0;
      } else {
        result[cnt - 1] = "#";
        num -= Math.pow(2, cnt - 1);
        cnt = 0;
      }
    } else cnt++;
  }

  return result.reverse();
}

function sumBinary(num1, num2, n) {
  let result = "";
  let map1 = toBinary(num1, n);
  let map2 = toBinary(num2, n);
  for (let i = 0; i < map1.length; i++) {
    if (map1[i] === " " && map2[i] === " ") {
      result += " ";
    } else result += "#";
  }
  return result;
}

function solution(n, arr1, arr2) {
  var answer = [];
  for (let i = 0; i < n; i++) {
    answer.push(sumBinary(arr1[i], arr2[i], n));
  }
  console.log(answer);
  return answer;
}
