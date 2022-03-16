function solution(left, right) {
    let sum = 0;
    for(let i = left; i <= right; i++) {
        sum += i * (Math.sqrt(i) % 1 != 0 ? 1 : -1);
    }
    return sum;
 }

console.log(solution(13, 17))

// function measure(num) {
//     let cnt = 0;
//     for (let i = 1; i <= num; i++) {
//       if (num % i === 0) cnt++;
//     }
//     return cnt % 2 === 0 ? 1 : -1;
//   }
  
//   function solution(left, right) {
//     var answer = 0;
  
//     for (let i = left; i <= right; i++) {
//       answer += measure(i) * i;
//     }
//     console.log(answer);
//     return answer;
//   }

//REST API는 HTTP 요청을 보낼때, 어떤 URI에 어떤 메서드를 사용할지 정해놓은 약속