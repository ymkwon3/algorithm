// 문자열 내림차순으로 배치하기

const solution = (s) => s.split("").sort((a, b) => a < b ? 1 : a > b ? -1 : 0).join("");

console.log(solution("Zbcdefg"));