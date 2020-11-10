# 첫째 줄에 N이 주어진다.
# 둘째 줄 부터 N개의 줄에 T와 P가 공백으로 구분되어서 주어지며, 1일부터 N일까지 순서대로 주어진다.

def init():
    day = input()
    schedule = []
    for i in range(int(day)):
        t, p = map(int, input().split(' '))
        schedule.append([t, p])
    return schedule

def bestProfit(schedule):
    dp = [0] * len(schedule)
    for i in range(len(schedule)):
        if i + schedule[i][0] <= len(schedule):
            dp[i] = schedule[i][1]
            for j in range(i):
                if j + schedule[j][0] <= i:
                    dp[i] = max(dp[i], dp[j] + schedule[i][1])
    return max(dp)

if __name__ == "__main__":
    print(bestProfit(init()))