// 모의고사

// function compare(test, ans) {
//   let ts = 0;
//   for (let i = 0; i < ans.length; i++) {
//     if (test[i] == ans[i]) {
//       ts++;
//     }
//   }
//   return ts;
// }

// function solution(answers) {
//   var answer = [];
//   var tmp = [];
//   var first = [];
//   var second = [];
//   var third = [];
//   for (let i = 0; i < 10000; i++) {
//     first.push(1, 2, 3, 4, 5);
//     i += 4;
//   }
//   for (let i = 0; i < 10000; i++) {
//     second.push(2, 1, 2, 3, 2, 4, 2, 5);
//     i += 7;
//   }
//   for (let i = 0; i < 10000; i++) {
//     third.push(3, 3, 1, 1, 2, 2, 4, 4, 5, 5);
//     i += 9;
//   }
//   tmp.push(compare(first, answers));
//   tmp.push(compare(second, answers));
//   tmp.push(compare(third, answers));
//   let maxi = Math.max(...tmp);
//   for (let i in tmp) {
//     console.log(tmp[i], maxi);
//     if (tmp[i] == maxi) {
//       answer.push(parseInt(i) + 1);
//     }
//   }

//   return answer;
// }

function solution(answers) {
    let ans = [];
    const p1 = [1,2,3,4,5];
    const p2 = [2,1,2,3,2,4,2,5];
    const p3 = [3,3,1,1,2,2,4,4,5,5];

    let p1_result = answers.filter((v, i) => v === p1[i % p1.length]).length;
    let p2_result = answers.filter((v, i) => v === p2[i % p2.length]).length;
    let p3_result = answers.filter((v, i) => v === p3[i % p3.length]).length;

    const max = Math.max(p1_result, p2_result, p3_result);

    if(max == p1_result) ans.push(1);
    if(max == p2_result) ans.push(2);
    if(max == p3_result) ans.push(3);

    return ans;
}

console.log(solution([1,2,3,4,5]));