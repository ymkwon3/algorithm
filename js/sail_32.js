// 두 개 뽑아서 더하기

function solution(numbers) {
    let set = new Set();

    for(let i = 0, end = 1; i < numbers.length; end++) {
        if(end == numbers.length) break;
        set.add(numbers[i] + numbers[end]);
        if (end >= numbers.length - 1) {
            i++;
            end = i;
        }
    }
    let arr = Array.from(set);
    arr.sort(function(a,b) {
        return a - b;
    })
    return arr;
}

console.log(solution([2, 1, 3, 4, 1]))