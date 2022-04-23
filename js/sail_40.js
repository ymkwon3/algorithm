// 신규 아이디 추천

function solution(new_id) {
    let ans = new_id.toLowerCase()
    .replace(/[^a-z0-9._-]/g, '')
    .replace(/\.+/g, '.')
    .replace(/^\.*|\.$/g, '')
    .replace(/^$/g, 'a')
    .slice(0, 15).replace(/\.$/g, '');
    
    return ans.length > 2 ? ans : ans + ans[ans.length - 1].repeat(3 - ans.length);
}

console.log(solution("...!@B"))