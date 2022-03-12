// 문자열 내 p와 y의 개수

function solution(s){
    // let p = 0, y = 0;
    // for (const i of s) {
    //     if(i == 'p' || i == 'P')
    //         p++;
    //     else if(i == 'y' || i == 'Y')
    //         y++;
    // }

    // return p == y;
    console.log(s.toUpperCase().split("P"))
    console.log(s.toUpperCase().split("Y"))
    return s.toUpperCase().split("P").length == s.toUpperCase().split("Y").length
}

solution("pPoooyY");