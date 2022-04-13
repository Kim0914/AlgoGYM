N, B = map(int, input().split())

mat = []
for _ in range(N):
    mat.append(list(map(int, input().split())))


def calc(mat_a, mat_b):
    mat_len = len(mat_a)

    ret = [[0] * mat_len for _ in range(mat_len)]

    for i in range(mat_len):
        for j in range(mat_len):
            tmp = 0
            for k in range(mat_len):
                tmp += mat_a[i][k] * mat_b[k][j]
            
            ret[i][j] = tmp % 1000

    return ret



def square(mat, B):
    if B == 1:
        for i in range(N):
            for j in range(N):
                mat[i][j] = mat[i][j] % 1000

        return mat

    else:
        tmp  = square(mat, B//2)

        if B % 2 == 0:
            return calc(tmp, tmp)
            

        else:
            return calc(calc(tmp, tmp), mat)

            

ans = square(mat, B)

for data in ans:
    print(*data)
