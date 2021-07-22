const a = 1;
const b = 1;

solution(a, b);

function solution(a, b) {
  var answer = "";
  let date = 5;
  let cal = new Array(13);
  cal[1] = new Array(32);
  cal[2] = new Array(30);
  cal[3] = new Array(32);
  cal[4] = new Array(31);
  cal[5] = new Array(32);
  cal[6] = new Array(31);
  cal[7] = new Array(32);
  cal[8] = new Array(32);
  cal[9] = new Array(31);
  cal[10] = new Array(32);
  cal[11] = new Array(31);
  cal[12] = new Array(32);

  for (let i = 1; i <= 12; i++) {
    for (let j = 1; j < cal[i].length; j++) {
      cal[i][j] = date;
      date++;
      if (date > 7) date = 1;
    }
  }

  switch (cal[a][b]) {
    case 1:
      answer = "MON";
      break;
    case 2:
      answer = "TUE";
      break;
    case 3:
      answer = "WED";
      break;
    case 4:
      answer = "THU";
      break;
    case 5:
      answer = "FRI";
      break;
    case 6:
      answer = "SAT";
      break;
    case 7:
      answer = "SUN";
      break;
  }
  console.log(answer);
  return answer;
}
