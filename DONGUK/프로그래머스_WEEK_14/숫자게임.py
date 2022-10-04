from collections import deque

def solution(A, B):
    answer = 0
    
    if min(A) >= max(B):
        return 0

    A.sort()
    B.sort()
    
    B = deque(B)
    for i in range(len(A)):
        q = deque()
        num = A[i]
        
        while B:
            if B[0] > num:
                B.popleft()
                answer += 1
                break
            
            else:
                B.popleft()
            
    return answer
