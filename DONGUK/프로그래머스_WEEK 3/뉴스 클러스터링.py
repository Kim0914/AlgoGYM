def search(data):
    ret = []
    for i in range(len(data) - 1):
        c1, c2 = data[i], data[i+1]
        
        if 'a' <= c1 <= 'z' and 'a' <= c2 <= 'z':
            ret.append(c1+c2)
    return ret


def uni(list1, list2):
    ret = []
    
    for data in list1:
        if data not in ret:
            cnt = max(list1.count(data), list2.count(data))
            for _ in range(cnt):
                ret.append(data)
    
    for data in list2:
        if data not in ret:
            cnt = max(list1.count(data), list2.count(data))
            for _ in range(cnt):
                ret.append(data)
    
    return len(ret)


def inter(list1, list2):
    ret = []
    
    if len(list1) > len(list2):
        list1, list2 = list2, list1
    
    for data in list1:
        if data in list2:
            cnt = min(list1.count(data), list2.count(data))
            
            if data not in ret:
                for _ in range(cnt):
                    ret.append(data)

    return len(ret)

def solution(str1, str2):
    answer = 0
    str1 = str1.lower()
    str2 = str2.lower()
    
    list1 = search(str1)
    list2 = search(str2)
            
    list1.sort()
    list2.sort()
    
    if list1 == list2:
        return 65536
    
    union = uni(list1, list2)
    intersection = inter(list1, list2)
    
    
    answer = int((intersection/union) * 65536)
    return answer