let name = "영민";
function second(param) {
  console.log(param + name);
}

function first() {
  let name = "영민아님";
  second('나는 ');
}
first(); // "나는 영민"