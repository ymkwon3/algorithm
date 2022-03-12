// 두 정수 사이의 합

function solution(a, b) {
    let sum = 0;
    // a에는 작은 값, b에는 큰 값
    if(a > b) {
      let tmp = a;
      a = b;
      b = tmp;
    }
    
    // 두 정수 사이의 범위를 구하기 위해 작은 값이 a에 위치하도록 함
    for(let i = a; i <= b; i++) {
      sum += i;
    }
    c
    return sum;
  }
  
  solution(5, 3)