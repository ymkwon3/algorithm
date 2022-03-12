// 로또의 최고 순위와 최저 순위

function solution(lottos, win_nums) {
    const rank = [6, 6, 5, 4, 3, 2, 1]

    let zero_cnt = 0;
    let win_cnt = 0;
    for(let i = 0; i < lottos.length; i++) {
        if(lottos[i] != 0) {
            win_cnt = win_nums.includes(lottos[i]) ? win_cnt + 1 : win_cnt;
        } else {
            zero_cnt++;
        }
    }
    return [rank[win_cnt + zero_cnt], rank[win_cnt]];
}

console.log(solution([44, 1, 0, 0, 31, 25], [31, 10, 45, 1, 6, 19]));