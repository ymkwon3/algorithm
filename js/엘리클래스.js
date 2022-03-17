class Counter {
    constructor(runIfFive) {
        this.counter = 0;
        this.callback = runIfFive;
    }

    increase() {
        this.counter++;
        console.log(this.counter);
        if(this.counter % 5 === 0) {
            this.callback && this.callback(this.counter);
        }
    }
}

const coolCounter = new Counter(printYo);
const hotCounter = new Counter(printKi);

function printYo(num) {
    console.log(`yo! ${num}`);
}

function printKi(num) {
    console.log(`ki! ${num}`);
}


coolCounter.increase();
coolCounter.increase();
coolCounter.increase();
coolCounter.increase();
coolCounter.increase();
coolCounter.increase();


hotCounter.increase();
hotCounter.increase();
hotCounter.increase();
hotCounter.increase();
hotCounter.increase();
hotCounter.increase();
hotCounter.increase();
hotCounter.increase();