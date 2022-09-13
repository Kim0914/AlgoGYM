def solution(x, n):
    answer = []
    
    add = x
    for _ in range(n):
        answer.append(add)
        add += x
    return answer