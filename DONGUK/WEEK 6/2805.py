import sys
input = sys.stdin.readline

n, target = map(int, input().split())
trees = list(map(int, input().split()))

trees.sort()

low, high = 1, trees[-1]

max_len = 0
while low <= high:
    mid = (low + high) // 2

    tree_len = 0
    for tree in trees:
        if tree > mid:
            tree_len += (tree - mid)


    if tree_len >= target:
        max_len = mid
        low = mid + 1

    else:
        high = mid - 1

print(max_len)