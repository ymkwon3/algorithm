// 평균 구하기

function solution(arr) {
    let result = 0;
    for(const n of arr) {
        result += n;
    }
    result /= arr.length;
    return result;
}

solution([1,2,3,4])