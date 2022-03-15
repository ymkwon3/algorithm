function solution(id_list, report, k) {
    let answer = [];

    let m_set = new Map();
    let m_reported = new Map();
    let m_answer = new Map();
    for(let i = 0; i < id_list.length; i++) {
        let s = new Set();
        m_set.set(id_list[i], s);
        m_reported.set(id_list[i], 0);
        m_answer.set(id_list[i], 0);
    }

    for(let i = 0; i < report.length; i++) {
        let split = report[i].split(' ');
        let user_name = split[0];
        let report_name = split[1];
        m_set.set(user_name, m_set.get(user_name).add(report_name));
    }

    m_set.forEach((value) => {
        value.forEach(v => {
            m_reported.set(v, m_reported.get(v) + 1);
        })
    })

    m_reported.forEach((value, key) => {
        console.log(key, value);
        if(value >= k) {
            m_set.forEach((inner_value, inner_key) => {
                inner_value.forEach(v => {
                    if(key == v)
                        m_answer.set(inner_key, m_answer.get(inner_key) + 1)
                })
            })
        }
    })

    m_answer.forEach(v => {
        answer.push(v);
    })

    return answer;
}

console.log(solution(
    ["muzi", "frodo", "apeach", "neo"],
    ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"],
    2
));