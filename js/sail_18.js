// 서울에서 김서방 찾기

// function solution(seoul) {
//     for (let i = 0; i < seoul.length; i++) {
//         if (seoul[i] == "Kim")
//             return "김서방은 " + i + "에 있다"
//     }
// }


const solution = (seoul) => {
    return `김서방은 ${seoul.indexOf('Kim')}에 있다`;
    };

console.log(solution(["Jane", "Kim"]))