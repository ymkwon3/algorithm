// 행렬의 덧셈

function solution(arr1, arr2) {
    let result = arr1;
    for(let i = 0; i < result.length; i++) {
        for(let j = 0; j < result[i].length; j++) {
            result[i][j] += arr2[i][j]
        }
    }
    return result;
}

solution([[1,2], [2,3]], [[3,4], [5,6]])