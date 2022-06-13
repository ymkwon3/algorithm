// 가운데 글자 가져오기

function solution(s) {
    let answer = "";
    // 가운데 인덱스를 찾기 위해 나누기 2
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