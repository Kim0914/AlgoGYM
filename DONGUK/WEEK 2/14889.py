import sys
input = sys.stdin.readline

answer = []
teamA = []
N = int(input())
entire_team = [i for i in range(0,N)]
mat = []

for _ in range(N):
    mat.append(list(map(int, input().split())))


def match():
    if len(teamA) == N // 2:
        teamB = list(set(entire_team) - set(teamA))

        sum_a, sum_b = 0, 0
        a_len = len(teamA)
        for i in range(a_len):
            for j in range(i+1, a_len):
                x1, x2 = teamA[i], teamA[j]
                y1, y2 = teamB[i], teamB[j]
                
                sum_a += (mat[x1][x2] + mat[x2][x1])
                sum_b += (mat[y1][y2] + mat[y2][y1])
        
        diff = abs(sum_a - sum_b)
        if len(answer) == 0 or answer[-1] > diff:
            answer.append(diff)
        return

    for i in range(N):
        if i not in teamA:
            teamA.append(i)
            match()
            teamA.pop()

match()
print(answer[-1])