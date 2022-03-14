// 이상한 문자 만들기

//"try hello world" /"TrY HeLlO WoRlD"

// function solution(s) {
//     let answer = "";
//     for(let i = 0, index = 0; i < s.length; i++) {
//         if(s[i] == ' ') {
//             answer += ' ';
//             index = 0;
//         }else {
//             if(index % 2 == 0) {
//                 answer += s[i].toUpperCase();
//             }else {
//                 answer += s[i].toLowerCase();
//             }
//             index++;
//         }
//     }

//     return answer;
// }

// 아무래도 메서드를 많이 사용하다보니 위에 코드보다 느리다
const solution = (s) => s.split(' ').map(str => str.split('').map((v, i) => i % 2 == 0 ? v.toUpperCase() : v.toLowerCase()).join('')).join(' ');

solution(" try      hello   world ");