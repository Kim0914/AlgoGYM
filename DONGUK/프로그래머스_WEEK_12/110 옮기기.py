def solution(s):
    answer = []
    
    for data in s:
        stack = []
        count = 0
        # 110 모두 제거
        for c in data:
            # 110이 나온 경우
            if(len(stack) >= 2 and stack[-1] == '1' and stack[-2] == '1' and c == '0'):
                count += 1
                stack.pop()
                stack.pop()
            else:
                stack.append(c)
                
        
        count_1 = 0
        for s in stack[::-1]:
            if s == '0':
                break
            else:
                count_1 += 1
        answer.append(''.join(stack[:len(stack) - count_1]) + '110' * count + '1' * count_1)
            
    return answer