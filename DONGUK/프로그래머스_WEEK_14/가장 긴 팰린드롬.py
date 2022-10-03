def isPalindrome(input_str):
    N = len(input_str)
    
    if N == 1:
        return True
    
    left, right = '', ''
    if N % 2 == 1:
        left = input_str[0:N//2]
        right = input_str[(N//2)+1:]
    else:
        left = input_str[0:N//2]
        right = input_str[N//2:]

    right = right[::-1]
    flag = True
    for i in range(len(left)):
        if left[i] != right[i]:
            flag = False
            break
            
    return flag
    

def solution(s):
    for cut in range(len(s), 0, -1):
        for start in range(0, len(s)):
            cutStr = s[start:start+cut]
            
            if isPalindrome(cutStr) == True:
                return len(cutStr)
            
            if start+cut >= len(s):
                break

# 시간초과 -> 길이가 작은 것 부터 찾으면 시간초과


# def solution(s):
#     answer = 0
#     d = {}
    
#     N = len(s)
    
#     max_len = 0
#     for k in range(N):
#         tmp = ''
#         for i in range(k, (N+k)//2 + 1):
#             tmp += s[i]
            
            
#             if isPalindrome(tmp):
#                 max_len = max(max_len, len(tmp))

#             cmp = ''
#             for j in range(i+1, N):
#                 if j >= N:
#                     break
#                 cmp += s[j]
                
#                 if tmp+cmp in d:
#                     continue

#                 if isPalindrome(tmp + cmp):
#                     if tmp+cmp not in d:
#                         d[tmp+cmp] = len(tmp+cmp)
                        
#                     max_len = max(max_len, len(tmp+cmp))
    
#     answer = max_len
#     return answer