def solution(s):
    s = s[1:-1]
    s = "".join(s.split('{'))
    s = s.split('}')
    
    tuple_list = []
    for a in s:
        if a == '':
            continue
        else:
            if a[0] == ',':
                a = a[1:]
            
            tuple_list.append(a)
    
    
    tuple_list.sort(key=lambda x:len(x))
    
    answer = []
    
    for data in tuple_list:
        data = data.split(',')
        for num in data:
            num = int(num)
            if num not in answer:
                answer.append(num)
            
    
    return answer