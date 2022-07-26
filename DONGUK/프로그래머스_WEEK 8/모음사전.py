words = []
alpha_list = ['A', 'E', 'I', 'O', 'U']

def dfs(cnt, char):

    if cnt == 5:
        return

    for i in range(5):
        tmp = char + alpha_list[i]
        words.append(tmp)
        dfs(cnt+1, tmp)

def solution(word):
    answer = 0

    dfs(0, '')
    answer = words.index(word) + 1
    return answer