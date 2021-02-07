num = int(input())

sum = []

for i in range(0, num):

    a, b = input().split()

    a = int(a)
    b = int(b)

    sum.append(a + b)

for i in range(0, num):

    print("Case #%d:"%(i + 1), sum[i])
