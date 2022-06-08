def solution(s):
    num_dict = {'zero': '0', 'one':'1', 'two':'2', 'three':'3', 'four':'4', 
                'five': '5', 'six':'6', 'seven':'7','eight':'8', 'nine':'9'}
    
    nums = ['0','1','2','3','4','5','6','7','8','9']
    
    answer = ''
    
    s = list(s)
    
    tmp = ''
    for ch in s:
        if ch not in nums:
            tmp += ch
        
            if tmp in num_dict:
                answer += num_dict[tmp]
                tmp = ''
        else:
            answer += ch
    
    answer = int(answer)
    return answer