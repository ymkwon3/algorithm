const lottos = [45, 4, 35, 20, 3, 9];
const win_nums = [31, 10, 45, 1, 6, 19];
solution(lottos, win_nums);
function ranking(num) {
  switch (num) {
    case 2:
      return 5;
    case 3:
      return 4;
    case 4:
      return 3;
    case 5:
      return 2;
    case 6:
      return 1;
    default:
      return 6;
  }
}

function solution(lottos, win_nums) {
  var answer = [];
  let zero = 0;
  let minimum = 0;
  for (let val of lottos) {
    if (val === 0) zero++;
    else {
      for (let win of win_nums) {
        if (val === win) {
          minimum++;
          break;
        }
      }
    }
  }
  answer = [ranking(minimum + zero), ranking(minimum)];
  console.log(answer);
  return answer;
}
