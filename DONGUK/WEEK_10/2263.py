import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
pos = [0] * (n+1)


inOrder = list(map(int, input().split()))
postOrder = list(map(int, input().split()))


for i in range(n):
    pos[inOrder[i]] = i


def preOrder(in_s, in_e, post_s, post_e):
    if in_s > in_e or post_s > post_e:
        return
    
    root = postOrder[post_e]
    print(root, end = ' ')

    left = pos[root] - in_s # 왼쪽 서브 트리의 노드 수
    right = in_e - pos[root] # 오른쪽 서브 트리의 노드 수

    preOrder(in_s, in_s + left - 1, post_s, post_s + left - 1)
    preOrder(in_e - right + 1, in_e, post_e - right, post_e - 1)
    

preOrder(0, n-1, 0, n-1)

'''
중위, 후위 순위로 나타낸 것에서 서브트리를 나누는 구간을 적절하게 구하는 것이 핵심

'''