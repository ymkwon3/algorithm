// 서울에서 김서방 찾기

function solution(seoul) {
    for (const i in seoul) {
        if (seoul[i] == "Kim")
            return "김서방은 " + i + "에 있다"
    }
}

solution(["Jane", "Kim"])