// 완주하지 못한 선수

function solution(participant, completion) {
    let map = new Map();
    for(let i = 0; i < completion.length; i++) {
        let c = completion[i];
        map.set(c, map.has(c) ? map.get(c) + 1 : 1);
    }
    for(let i = 0; i < participant.length; i++) {
        let p = participant[i]
        if(map.has(p)) {
            map.get(p) == 1 ? map.delete(p) : map.set(p, map.get(p) - 1);
        }else {
            return p
        }
    }

    //위의 방식이 효율성에서 더 빨랐음

    // participant.sort();
    // completion.sort();
    // for(let i = 0, len = participant.length; i < len; i++) {
    //     if(participant[i] != completion[i]) return participant[i];
    // }
}

solution(["mislav", "stanko", "mislav", "ana"], ["stanko", "ana", "mislav"]);