// 두 정수 사이의 합

function solution(a, b) {
    let sum = 0;
    // a에는 작은 값, b에는 큰 값
    if(a > b) {
      let tmp = a;
      a = b;
      b = tmp;
    }
    
    
    for(let i = a; i <= b; i++) {
      sum += i;
    }
    console.log(sum);
    return sum;
  }
  
  solution(5, 3)