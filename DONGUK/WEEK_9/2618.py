import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

N = int(input())
W = int(input())
pos = [(1, 1), (N, N)]
dp = [[-1] * (W+2) for _ in range(W+2)]

def search(row, col):
    # print('row, col: ', end = '')
    # print(row, col)
    if row > W or col > W:
        return 0
    
    if dp[row][col] != -1:
        return dp[row][col]
    
    next_pos = max(row, col) + 1
    nr = search(next_pos, col) + abs(pos[next_pos][0] - pos[row][0]) + abs(pos[next_pos][1] - pos[row][1])
    nc = search(row, next_pos) + abs(pos[next_pos][0] - pos[col][0]) + abs(pos[next_pos][1] - pos[col][1])
    dp[row][col] = min(nr,nc)

    return dp[row][col]

def route(row,col):
	if row > W or col > W:
		return

	next_pos = max(row, col)+1
	nr = abs(pos[next_pos][0] - pos[row][0]) + abs(pos[next_pos][1] - pos[row][1])
	nc = abs(pos[next_pos][0] - pos[col][0]) + abs(pos[next_pos][1] - pos[col][1])

	if dp[next_pos][col] + nr < dp[row][next_pos] + nc:
		print(1)
		route(next_pos,col)

	else:
		print(2)
		route(row,next_pos)

	return


def solution(N,W):
	print(search(0,1))
	
	route(0,1)

for _ in range(W):
	pos.append(tuple(map(int,input().split())))

solution(N,W)




'''
1. DP를 W+2 사이즈 만큼 만들기 -> 처음, 시작점 2개 추가
2. 경찰차 2대를 i, j로 표현
3. DP[i][j]는 1번째 경찰차는 i번째 ,2번째 경찰차는 j번째 까지 해결한 상태
4. 탐색할 경우에는 max(i, j) + 1을 구하고 search(max(i,j)+1, j), search(i, max(i,j)+1) 수행

'''