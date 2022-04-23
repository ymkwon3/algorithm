// 최소직사각형

function solution(sizes) {
    // width에 무조건 큰 값이 오게
    let width = 0, heigth = 0
    for(let i = 0; i < sizes.length; i++) {
        // sizes[0]에 무조건 큰 값이 오게
        if(sizes[i][0] < sizes[i][1]) {
            let temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
        width = width < sizes[i][0] ? sizes[i][0] : width;
        heigth = heigth < sizes[i][1] ? sizes[i][1] : heigth;
    }
    return width * heigth;
}

console.log(solution([[10, 7], [12, 3], [8, 15], [14, 7], [5, 15]]));