//아이디 길이는 3자이상 15자이하
//알파벳소문자, 숫자,빼기,밑줄,마침표사용가능
//마침표는 처음과 끝에 사용할 수 없으며 연속사용 불가
const new_id = "z-+.^.";
solution(new_id);
function solution(new_id) {
  var answer = "";
  new_id = new_id.toLowerCase(); // 1단계

  let remove = []; // 2단계
  for (let i = 0; i < new_id.length; i++) {
    if (
      (new_id[i] < "0" || new_id[i] > "9") &&
      (new_id[i] < "a" || new_id[i] > "z")
    ) {
      if (new_id[i] !== "-" && new_id[i] !== "." && new_id[i] !== "_") {
        remove.push(new_id[i]);
      }
    }
  }
  for (let val of remove) {
    let regex = new RegExp("\\" + val, "g");
    new_id = new_id.replace(regex, "");
  }

  new_id = new_id.replace(/\.+/g, "."); // 3단계

  let arr = new_id.split(""); // 4단계
  if (arr[0] === ".") arr[0] = "";
  if (arr[arr.length - 1] === ".") arr[arr.length - 1] = "";
  new_id = arr.join("");

  // 5단계
  if (new_id.length === 0) {
    new_id = "a";
  }

  // 6, 7단계
  if (new_id.length >= 16) {
    new_id = new_id.slice(0, 15);
  } else if (new_id.length <= 2) {
    while (new_id.length < 3) {
      new_id += new_id[new_id.length - 1];
    }
  }

  arr = new_id.split(""); // 4단계
  if (arr[0] === ".") arr[0] = "";
  if (arr[arr.length - 1] === ".") arr[arr.length - 1] = "";
  new_id = arr.join("");

  answer = new_id;
  console.log(new_id);

  return answer;
}
