// 가운데 글자 가져오기

function solution(s) {
    let answer = "";
    // abcde c // abcd bc
    // s[0] s[1] s[2] s[3]
    let middle_idx = parseInt(s.length / 2)
    
    if (s.length % 2 == 0) {
      // 짝수
      answer = s[middle_idx - 1] + s[middle_idx]
      
    }else {
      // 홀수
      answer = s[middle_idx]
    }
    console.log(answer)
    return answer;
  }
  
  solution("abcd")