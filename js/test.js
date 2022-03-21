let arr = [1, 2, 3, 4, 5];

arr.reduce((acc, value, index) => {
    console.log(acc, value, index);

    return acc + value;
}, 0)


console.log(arr);