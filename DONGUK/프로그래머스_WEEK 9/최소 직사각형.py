def solution(sizes):
    answer = 0

    orders = []
    for size in sizes:
        a = max(size[0], size[1])
        b = min(size[0], size[1])
        orders.append((a, b))
    
    garo, sero = 0, 0
    for a, b in orders:
        garo = max(garo, a)
        sero = max(sero ,b)
    
    answer = garo * sero
    return answer