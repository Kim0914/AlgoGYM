def solution(n, k, cmd):
    cur = k
    # prev, next
    table = { i:[i - 1, i + 1] for i in range(n) }
    answer = ['O'] * n
    table[0] = [None, 1]
    table[n-1] = [n-2, None]
    
    deleted = []
    
    for c in cmd:
        if c == 'C':
            answer[cur] = 'X'
            prev, next_ = table[cur]
            deleted.append([prev, cur, next_])
            
            if next_ == None:
                cur = table[cur][0]
            else:
                cur = table[cur][1]
            
            if prev == None:
                table[next_][0] = None
                
            elif next_ == None:
                table[prev][1] = None
                
            else:
                table[prev][1] = next_
                table[next_][0] = prev
                
        elif c == 'Z':
            prev, now, next_ = deleted.pop()
            answer[now] = 'O'
            if prev == None:
                table[next_][0] = now
                
            elif next_ == None:
                table[prev][1] = now
                
            else:
                table[next_][0] = now
                table[prev][1] = now
                
        else:
            c1, c2 = c.split()
            c2 = int(c2)
            
            if c1 == 'D':
                for _ in range(c2):
                    cur = table[cur][1]
                    
            else:
                for _ in range(c2):
                    cur = table[cur][0]
                    
    return "".join(answer)

print(solution(8, 2, ["D 2","C","U 3","C","D 4","C","U 2","Z","Z"]))