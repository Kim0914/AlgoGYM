def solution(n):
    answer = 0

    cnt = list(bin(n)[2:n]).count('1')
    

    while True:
        n = n + 1
        mod_cnt = list(bin(n)[2:n]).count('1')

        if cnt == mod_cnt:
            answer = n
            break
              
    return answer