def preOrder(node):
    global nodes
    print(node, end='')

    siblings = nodes[node]
    left, right = siblings[0], siblings[1]

    if left != '.':
        preOrder(left)
    
    if right != '.':
        preOrder(right)

def inOrder(node):
    global nodes
    siblings = nodes[node]
    left, right = siblings[0], siblings[1]

    if left != '.':
        inOrder(left)

    print(node, end='')

    if right != '.':
        inOrder(right)

def postOrder(node):
    global nodes
    siblings = nodes[node]
    left, right = siblings[0], siblings[1]

    if left != '.':
        postOrder(left)

    if right != '.':
        postOrder(right)

    print(node, end='')

N = int(input())

nodes = {}

for _ in range(N):
    node, left, right = map(str, input().split())
    nodes[node] = [left, right]

preOrder('A')
print()
inOrder('A')
print()
postOrder('A')