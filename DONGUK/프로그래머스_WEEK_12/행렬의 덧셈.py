def solution(arr1, arr2):
    answer = []
    
    for i in range(len(arr1)):
        row1, row2 = arr1[i], arr2[i]
        
        tmp = []
        for j in range(len(row1)):
            tmp.append(row1[j] + row2[j])
        
        answer.append(tmp)
        
    return answer