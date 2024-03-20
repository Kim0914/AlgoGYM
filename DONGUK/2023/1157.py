d = {}

words = input()

for i in range(len(words)):
    word = words[i].upper()
    if word not in d:
        d[word] = 1
    else:
        d[word] += 1

max_cnt = max(d.values())

ans = []
for word, cnt in d.items():
    if cnt == max_cnt:
        ans.append(word)
    
    if len(ans) >= 2:
        ans = ['?']
        break

print(ans[0])
