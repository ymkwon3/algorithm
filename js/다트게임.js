const dartResult = "1S*2T*3S";
solution(dartResult);

function calculate(score, bonus) {
  score = parseInt(score);
  if (bonus === "S") return score;
  else if (bonus === "D") return score * score;
  else if (bonus === "T") return score * score * score;
}

function solution(dartResult) {
  var answer = 0;
  let game = new Array(3);

  let score = "",
    bonus = null,
    option,
    index = 0;
  for (let i = 0; i < dartResult.length; i++) {
    if (dartResult[i] >= "0" && dartResult[i] <= "9") {
      if (bonus !== null) {
        game[index] = calculate(score, bonus);
        index++;
        score = "";
        bonus = null;
      }
      score += dartResult[i];
    } else if (
      dartResult[i] === "S" ||
      dartResult[i] === "D" ||
      dartResult[i] === "T"
    ) {
      bonus = dartResult[i];
    } else if (dartResult[i] === "*" || dartResult[i] === "#") {
      option = dartResult[i];
      game[index] = calculate(score, bonus);
      if (option === "*") {
        game[index] *= 2;
        if (index > 0) game[index - 1] *= 2;
      }
      if (option === "#") {
        game[index] *= -1;
      }
      index++;
      score = "";
      bonus = null;
    }
  }
  if (bonus !== null) {
    game[index] = calculate(score, bonus);
  }
  console.log("game[0]:", game[0], "game[1]:", game[1], "game[2]:", game[2]);
  for (let val of game) {
    answer += val;
  }
  return answer;
}
