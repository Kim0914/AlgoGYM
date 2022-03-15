import sys
input = sys.stdin.readline

N = int(input())

infos = []
for i in range(N):
    age, name = map(str, input().split())
    infos.append((int(age), name, i)) # 나이, 이름, 가입순서(i)

infos = sorted(infos, key=lambda x : (x[0], x[2]))

for info in infos:
    print(info[0], info[1])
