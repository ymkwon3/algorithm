# 축구 n명 짝수
# n/2명으로 스타트팀 링크팀 나눔
# 능력치 Sij 각 i번사람과 j번사람의 시너지
# 각 팀의 능력치 합의 차이가 최소화 될 경우를 구해야함

from itertools import combinations

def init():
    global n, s
    n = int(input())
    s = [list(map(int, input().split())) for _ in range(n)]
    member = [i for i in range(n)]
    teams = list(combinations(member, n//2))
    minimum = 101
    for team in teams:
        restTeam = set(member) - set(team)
        minimum = min(minimum,BruteForce(team, restTeam))
    print(minimum)
        
    
def BruteForce(team, restTeam):
    global n, s
    start = 0
    link = 0
    for i in team:
        for j in team:
            start += s[i][j]

    for i in restTeam:
        for j in restTeam:
            link += s[i][j]

    return abs(start - link)


if __name__ == "__main__":
    init()