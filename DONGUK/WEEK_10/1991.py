import sys
input = sys.stdin.readline

# ord('A') : 65, chr(65) = 'A'

N = int(input())
tree = [[] * (1+N) for _ in range(1+N)]
pre_visited = [0] * (N+1)
inOrder_visited = [0] * (N+1)
post_visited = [0] * (N+1)

def init():
    for i in range(1, N+1):
        inp = input().split()
        a, b, c = inp[0], inp[1], inp[2]

        tree[ord(a) - 64].append((b, c))

def preOrder(i):
    if pre_visited[i] == 0:
        pre_visited[i] = 1
        print(chr(i + 64), end = '')

        left, right = tree[i][0][0], tree[i][0][1]
        if left != '.':
            preOrder(ord(left) - 64)

        if right != '.':
            preOrder(ord(right) - 64)

    return


def inOrder(i):
    if inOrder_visited[i] == 0:
        inOrder_visited[i] = 1

        left, right = tree[i][0][0], tree[i][0][1]

        if left != '.':
            inOrder(ord(left) - 64)

        if inOrder_visited[i] == 1:
            print(chr(i + 64), end = '')

        if right != '.':
            inOrder(ord(right) - 64)

    return

def postOrder(i):
    if post_visited[i] == 0:
        post_visited[i] = 1

        left, right = tree[i][0][0], tree[i][0][1]

        if left != '.':
            postOrder(ord(left) - 64)

        if right != '.':
            postOrder(ord(right) - 64)
    
        print(chr(i + 64), end = '')

init()


preOrder(1)
print()
inOrder(1)
print()
postOrder(1)

