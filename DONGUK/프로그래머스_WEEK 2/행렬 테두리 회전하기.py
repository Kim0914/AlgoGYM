def solution(rows, columns, queries):
    answer = []
    mat = [[0] * columns for _ in range(rows)]
    
    for i in range(1, rows+1):
        for j in range(1, columns+1):
            mat[i-1][j-1] = ((i-1) * columns) + j
            
    for query in queries: # max 10000
        nums = []
        start_x, start_y = query[0] - 1, query[1] - 1
        end_x, end_y = query[2] - 1, query[3] - 1
        
        flag1, flag2, flag3, flag4 = True, False, False, False
        
        prior_num = mat[start_x][start_y]
        nums.append(prior_num)
        
        now_num = 0
        i, j = start_x, start_y + 1
        while True:
            # 가로(오른쪽)로 진행
            if flag1: 
                now_num = mat[i][j]
                mat[i][j] = prior_num
                prior_num = now_num
                j += 1
                
                if j > end_y:
                    flag1 = False
                    flag2 = True
                    j -= 1
                    i += 1
            
            
            # 세로(아래)로 진행
            elif flag2:
                now_num = mat[i][j]
                mat[i][j] = prior_num
                prior_num = now_num
                i += 1
                
                if i > end_x:
                    flag2 = False
                    flag3 = True
                    i -= 1
                    j -= 1
                    
                    
            # 가로(왼쪽)로 진행
            elif flag3:
                now_num = mat[i][j]
                mat[i][j] = prior_num
                prior_num = now_num
                j -= 1
                
                if j < start_y:
                    flag3 = False
                    flag4 = True
                    i -= 1
                    j += 1
                    
                
            # 세로(위쪽)로 진행
            elif flag4:
                now_num = mat[i][j]
                mat[i][j] = prior_num
                prior_num = now_num
                i -= 1
            
                if i < start_x:
                    break
                
            nums.append(prior_num)
        
        answer.append(min(nums))
        
    return answer