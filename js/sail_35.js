// 문자열 내 마음대로 정렬하기

function solution(strings, n) {
    strings.sort(function(a, b) {
        return a[n] < b[n] ? -1 : a[n] < b[n] ? 1 : a < b ? -1 : a > b ? 1 : 0;
    });
    return strings;
}

console.log(solution(["sun", "bed", "car"], 1));