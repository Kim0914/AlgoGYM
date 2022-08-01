answer = [0,0]

def check(arr, start_i, start_j, cnt):
    val = arr[start_i][start_j] # 0 or 1
    flag = True

    for i in range(start_i, start_i + cnt):
        for j in range(start_j, start_j + cnt):
            if arr[i][j] != val:
                flag = False
    
    
    if flag:
        answer[val] += 1

    else:
        h_cnt = cnt // 2
        check(arr, start_i, start_j, h_cnt)
        check(arr, start_i, start_j + h_cnt, h_cnt)
        check(arr, start_i + h_cnt, start_j, h_cnt)
        check(arr, start_i + h_cnt, start_j + h_cnt, h_cnt)

def solution(arr):
    
    check(arr, 0, 0, len(arr))
    return answer