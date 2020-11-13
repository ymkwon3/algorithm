# op = [+, -, ×, ÷]
import itertools

def init():
    global n, a, operators
    a = []
    op = []
    operator = []
    n = int(input())
    while(len(a) != n):
        a = list(map(int, input().split()))
    while(sum(op) != n-1):
        op = list(map(int, input().split()))
        if len(op) != 4:
            continue
    for i, v in enumerate(op):
        for _ in range(v):
            if i == 0:
                operator.append('+')
            elif i == 1:
                operator.append('-')
            elif i == 2:
                operator.append('*')
            elif i == 3:
                operator.append('/')
    operators = list(itertools.permutations(operator))


def BruteForce():
    global n, a, operators

    minimum = 1000000000
    maximum = -1000000000

    for operator in operators:
        result = a[0]
        for i, v in enumerate(operator):
            result = computation(result, a[i+1], v)
        if (result < minimum):
            minimum = result
        if (result > maximum):
            maximum = result
    
    print(maximum)
    print(minimum)

def computation(left, right, op):
    if op == '+':
        return int(left + right)
    elif op == '-':
        return int(left - right)
    elif op == '*':
        return int(left * right)
    elif op == '/':
        return int(left / right)

    

if __name__ == "__main__":
    init()
    BruteForce()