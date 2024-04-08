import sys

input = sys.stdin.readline

N = int(input())

graphs = [list(map(int, input().split())) for _ in range(N)]
candidates = []

def copy_board(board):
    return [row[:] for row in board]

def up(graphs, cnt):
    graphs = copy_board(graphs)
    joined = set()
    for i in range(1, N):
        for j in range(N):
            cur_num = graphs[i][j]
            cur_row = i
            while cur_row > 0:
                if graphs[cur_row - 1][j] == 0:
                    cur_row -= 1
                else:
                    break
            
            if cur_row == 0:
                graphs[cur_row][j] = cur_num
                graphs[i][j] = 0
            else:
                if graphs[cur_row - 1][j] == cur_num and (cur_row - 1, j) not in joined:
                    graphs[cur_row - 1][j] = cur_num * 2
                    joined.add((cur_row - 1, j))
                    graphs[i][j] = 0
                else:
                    if (i, j) == (cur_row, j):
                        continue
                    else:
                        graphs[cur_row][j] = cur_num
                        graphs[i][j] = 0
    dfs(graphs, cnt + 1)
    # for g in graphs:
    #     print(g)
    # print()
def down(graphs, cnt):
    graphs = copy_board(graphs)
    joined = set()

    for i in range(N-2, -1, -1):
        for j in range(N):
            cur_num = graphs[i][j]
            cur_row = i 
            while cur_row < N - 1:
                if graphs[cur_row + 1][j] == 0:
                    cur_row += 1
                else:
                    break

            if cur_row == N - 1:
                graphs[cur_row][j] = cur_num
                graphs[i][j] = 0
            else:
                if graphs[cur_row + 1][j] == cur_num and (cur_row + 1, j) not in joined:
                    graphs[cur_row + 1][j] = cur_num * 2
                    joined.add((cur_row + 1, j))
                    graphs[i][j] = 0
                else:
                    if (i, j) == (cur_row, j):
                        continue
                    else:
                        graphs[cur_row][j] = cur_num
                        graphs[i][j] = 0
    dfs(graphs, cnt + 1)
    # for g in graphs:
    #     print(g)
    # print()
def left(graphs, cnt):
    graphs = copy_board(graphs)
    joined = set()

    for i in range(N):
        for j in range(1, N):
            cur_num = graphs[i][j]
            cur_col = j

            while cur_col > 0:
                if graphs[i][cur_col - 1] == 0:
                    cur_col -= 1
                else:
                    break

            if cur_col == 0:
                graphs[i][cur_col] = cur_num
                graphs[i][j] = 0
            else:
                if graphs[i][cur_col - 1] == cur_num and (i, cur_col - 1) not in joined:
                    graphs[i][cur_col - 1] = cur_num * 2
                    joined.add((i, cur_col - 1))
                    graphs[i][j] = 0
                else:
                    if (i, j) == (i, cur_col):
                        continue
                    graphs[i][cur_col] = cur_num
                    graphs[i][j] = 0

    dfs(graphs, cnt + 1)
    # for g in graphs:
    #     print(g)   
    # print()
def right(graphs, cnt):
    graphs = copy_board(graphs)
    joined = set()

    for i in range(N):
        for j in range(N-2, -1, -1):
            cur_num = graphs[i][j]
            cur_col = j

            while cur_col < N - 1:
                if graphs[i][cur_col + 1] == 0:
                    cur_col += 1
                else:
                    break
            
            if cur_col == N - 1:
                graphs[i][cur_col] = cur_num
                graphs[i][j] = 0
            else:
                if graphs[i][cur_col + 1] == cur_num and (i, cur_col + 1) not in joined:
                    graphs[i][cur_col + 1] = cur_num * 2
                    graphs[i][j] = 0
                    joined.add((i, cur_col + 1))
                else:
                    if (i, j) == (i, cur_col):
                        continue
                    graphs[i][cur_col] = cur_num
                    graphs[i][j] = 0

    dfs(graphs, cnt + 1)
    # for g in graphs:
    #     print(g)
    # print()
def dfs(graph, cnt):
    global candidates

    if cnt == 5:
        max_block = 0
        for g in graph:
            max_block = max(max_block, max(g))
        candidates.append(max_block)
        return

    left(graph, cnt)
    up(graph, cnt)
    down(graph, cnt)
    right(graph, cnt)

dfs(graphs, 0)
# up(graphs, 0)
# down(graphs, 0)
# right(graphs, 0)


print(max(candidates))