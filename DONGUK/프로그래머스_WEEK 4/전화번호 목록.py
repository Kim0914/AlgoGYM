def solution(phoneBook):
    d = {}
    phoneBook.sort(key=lambda x:len(x))
    for num in phoneBook:
        if len(d) == 0:
            d[num] = 1
        
        else:
            tmp = ''
            for i in range(len(num)):
                tmp += num[i]
                if tmp in d:
                    return False
            d[num] = 1
            
    return True