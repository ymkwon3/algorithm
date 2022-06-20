const answer = []; // 출력되어야 하는 정답 배열
const isCheck = []; // 번호가 사용되었는지 확인하기 위한 배열

function recursive(n, k) {
    if (n === 0) {
        // n 만큼 반복되었을 경우 재귀 종료
        return;
    }

    // 팩토리얼로 중복이 제외된 모든 경우의 수 구하기
    let fact = 1;
    for (let i = 1; i <= n; i++) {
        fact *= i;
    }

    const div = fact / n; // 경우의 수 첫번째 자리를 제외한 나머지가 div 만큼 반복됨
    const checkIdx = Math.floor(((k - 1) / div) + 1) - 1; // div만큼 반복되었기 때문에, k번째의 첫번째 수를 알 수 있음
    const nextK = ((k - 1) % div) + 1; // 나머지 값을 통해 다음 자릿 수가 해당 경우의 수의 몇 번째인지 알 수 있음

    answer.push(isCheck[checkIdx]); // isCheck에서 사용된 값을 정답배열에 추가해준 뒤 제외시킴
    isCheck.splice(checkIdx, 1);
    recursive(n - 1, nextK) // n만큼 재귀시켜줌
}

function solution(n, k) {
    for (let i = 0; i < n; i++) {
        isCheck.push(i + 1);
    }
    recursive(n, k);
    return answer;
}

solution(4, 6);
/* 
1 2 3 4 5 6 3의 팩토리얼
0 1 2 3 4 5 를 팩토리얼의 n을 나눈 수로 각 자리수를 나눴을때의 math.floor 값의 + 1
1 1 2 2 3 3

다음 자리가 계속 몇번째인지?

n=4
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
...

*/