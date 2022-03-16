import sys
input = sys.stdin.readline

N = int(input())
ans = 0
board = [0] * N

def check(num):
    for i in range(num):
        if board[i] == board[num] or abs(board[num] - board[i]) == (num - i):
            return False
    
    return True

def search(num):
    global ans
    if num == N:
        ans += 1
        return
    
    else:
        for i in range(N):
            board[num] = i
            if check(num):
                search(num+1)
    

search(0)
print(ans)