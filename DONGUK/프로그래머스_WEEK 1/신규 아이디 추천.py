def solution(new_id):
    answer = ''
    new_id = list(new_id)
    
    # 1단계
    for i in range(len(new_id)):
        alpha = new_id[i]
        if 65 <= ord(alpha) <= 90:
            new_id[i] = chr(ord(alpha) + 32)
    
    # 2단계
    for i in range(len(new_id)):
        alpha = new_id[i]
        if 48 <= ord(alpha) <= 57 or 97 <= ord(alpha) <= 122 or alpha == '-' or alpha == '_' or alpha == '.':
            answer += alpha
    
    # 3단계
    while '..' in answer:
        answer = answer.replace('..', '.')
            
    
    # 4단계
    if answer and answer[0] == '.':
        answer = answer[1:]
    
    if answer and answer[-1] == '.':
        answer = answer[:-1]
    
    # 5단계
    if len(answer) == 0:
        answer += 'a'
        
    # 6단계
    if len(answer) >= 16:
        answer = answer[0:15]
    

    if answer[-1] == '.':
        answer = answer[:-1]

    # 7단계
    while len(answer) <= 2:
        tail = answer[-1]
        answer += tail

    return answer