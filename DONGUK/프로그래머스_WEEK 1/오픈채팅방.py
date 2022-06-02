# 시작: 22:48
# 종료: 23:00
def solution(record):
    answer = []
    
    user_dict = {} # uid: name
    for data in record:
        data = data.split(' ')
        
        status, uid= data[0], data[1]
        
        if status == 'Enter' or status == 'Change':
            name = data[2]
            
            if status == 'Enter':
                user_dict[uid] = name
            
            elif status == 'Change':
                user_dict[uid] = name
    
    
    
    for data in record:
        data = data.split(' ')
        status, uid= data[0], data[1]
        
        if status == 'Enter':
            ans = "{}님이 들어왔습니다.".format(user_dict[uid])
            answer.append(ans)
            
        elif status == 'Leave':
            ans = "{}님이 나갔습니다.".format(user_dict[uid])
            answer.append(ans)
            
    return answer