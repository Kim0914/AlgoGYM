def solution(board, skill):
    answer = 0
    
    N = len(board)
    M = len(board[0])
    
    score = [[0] * (M+1) for _ in range(N+1)]
    
    for data in skill:
        typ = data[0]
        r1, c1, r2, c2= data[1], data[2], data[3], data[4]
        degree = data[5]
        
        # 적 공격
        if typ == 1:
            score[r1][c1] -= degree
            score[r1][c2+1] += degree
            score[r2+1][c1] += degree
            score[r2+1][c2+1] -= degree
        
        else:
            score[r1][c1] += degree
            score[r1][c2+1] -= degree
            score[r2+1][c1] -= degree
            score[r2+1][c2+1] += degree
    
    for i in range(len(score) - 1):
        for j in range(len(score[0]) - 1):
            score[i][j+1] += score[i][j]
    
    for j in range(len(score[0]) - 1):
        for i in range(len(score) - 1):
            score[i+1][j] += score[i][j]
        
    for i in range(N):
        for j in range(M):
            board[i][j] += score[i][j]
            if board[i][j] > 0:
                answer += 1
                
    return answer


'''
누적 합을 쓰는 문제.
Skills 최대 길이가 200,000 이므로 절대 O(K*N*M)으로 효율성을 통과할 수 없음

arr = [1, 2, 3, 4, 5] 가 있는 배열에서 0번째 ~ 2번째까지 -2를 하고 싶으면

[-2, 0, 0, 2, 0] 시작점(0번째)는 -2, 마지막 다음(2+1번째)는 부호 반대 +2

위 배열의 누적합을 계산하면
psum = [-2, -2, -2, 0, 0]

arr + psum을 하게 되면 원하는 값을 얻을 수 있음
'''