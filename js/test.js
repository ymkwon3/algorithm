let str = "hello*3";
let answer = "";
let temp;
const vowel = ['a', 'e', 'i', 'o', 'u']
for (let i = 0; i < str.length; i++) {
    temp = str[i].charCodeAt();
    if (temp >= 97 && temp < 122) {
        temp++;
        if (vowel.includes(String.fromCharCode(temp))) {
            temp -= 32;
        }
    } else if (temp === 122) {
        temp = 65
    }
    answer += String.fromCharCode(temp);
}
console.log(answer)