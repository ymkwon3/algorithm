function solution(checkin, checkout) {
    let hour_sum = 0, minute_sum = 0;

    for(let i = 0; i <checkin.length; i++) {
        let c_in = checkin[i].split(":");
        let c_out = checkout[i].split(":");
        
        if(c_out[0] >= 29){
            c_out[0] = 21;
            c_out[1] = 0;
        }
        
        hour_sum += c_out[0] - c_in[0];
        minute_sum += c_out[1] - c_in[1];
    }

    hour_sum += parseInt(minute_sum / 60);
    minute_sum %= 60;

    if(minute_sum < 0) {
        hour_sum--;
        minute_sum = 60 + minute_sum;
    }

    return `${hour_sum}시간 ${minute_sum}분`;
}

console.log(solution(["9:00", "9:00"], ["21:40", "21:30"]));