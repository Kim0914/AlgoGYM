import sys
input = sys.stdin.readline
sdoku = []

for _ in range(9):
    row = list(map(int, input().split()))
    sdoku.append(row)

zero_point = []

for i in range(9):
    for j in range(9):
        if sdoku[i][j] == 0:
            zero_point.append((i,j))
    

def check3x3(coords, val):
    x, y = 3*(coords[0]//3), 3*(coords[1]//3)
    for i in range(x, x+3):
        for j in range(y, y+3):
            if sdoku[i][j] == val:
                return False
    return True

def checkRow(coords, val):
    row = coords[0]
    for j in range(9):
        if sdoku[row][j] == val:
            return False
    
    col = coords[1]
    for i in range(9):
        if sdoku[i][col] == val:
            return False
    return True


def bt(index):
    if index == len(zero_point):
        for i in range(9):
            print(*sdoku[i])
        exit(0)

    for i in range(1, 10):
        x = zero_point[index][0]
        y = zero_point[index][1]
        
        
        if check3x3((x,y), i) and checkRow((x,y), i):
            sdoku[x][y] = i
            bt(index+1)
            sdoku[x][y] = 0

bt(0)


#------------------------시간초과----------------------------#

import sys

def find_number(n,m):
    nums = [1,2,3,4,5,6,7,8,9]
    for i in range(9): # 가로 행 검사
        if sdoku[n][i] in nums:
            nums.remove(sdoku[n][i])
    
    for j in range(9): # 세로 열 검사
        if sdoku[j][m] in nums:
            nums.remove(sdoku[j][m])

    x_cor = (n // 3) * 3
    y_cor = (m // 3) * 3
    

    for i in range(x_cor, x_cor+3):
        for j in range(y_cor, y_cor+3):
            if sdoku[i][j] in nums:
                nums.remove(sdoku[i][j])
    # 행, 열, 3x3 까지 검사하여 0 자리에 가능한 숫자 list인 nums 반환
    return nums

def dfs(index):
    global answer_flag
    if answer_flag == True:
        return
    
    if index == len(zero_point):
        for line in sdoku: # zero_point를 모두 체크한 경우 출력
            print(*line)
        answer_flag = True
        return

    i, j = zero_point[index] # 스도쿠에서 0인 좌표를 하나씩 가져온다
    able_nums = find_number(i,j)
    for num in able_nums:
        sdoku[i][j] = num
        dfs(index + 1)
        sdoku[i][j] = 0

sdoku = [list(map(int, sys.stdin.readline().split())) for _ in range(9)]
zero_point = [list((i,j)) for i in range(9) for j in range(9) if sdoku[i][j] == 0]
answer_flag = False
dfs(0)