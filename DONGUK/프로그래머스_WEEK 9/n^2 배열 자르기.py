def solution(n, left, right):
    answer = []

    for num in range(int(left), int(right)+1):
        i, j = num // n, num % n
        
        cnt = max(i,j) + 1
        answer.append(cnt)

    return answer