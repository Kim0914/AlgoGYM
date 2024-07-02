def solution(data, col, row_begin, row_end):
    
    data.sort(key = lambda x : (x[col-1], -x[0]))
    mods = []
    for i in range(row_begin, row_end + 1):
        elems = data[i-1]
        mod_sum = 0
        for elem in elems:
            mod_sum += (elem % i)
        mods.append(mod_sum)
    
    answer = mods[0]
    for i in range(1, len(mods)):
        answer = answer ^ mods[i]
    return answer