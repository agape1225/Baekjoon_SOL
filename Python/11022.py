num = int(input())

sum = []

for i in range(0, num):

    a, b = input().split()

    a = int(a)
    b = int(b)
    c = a + b

    sum.append("%d + %d = %d"%(a,b,c))

for i in range(0, num):

    print("Case #%d:"%(i + 1), sum[i])
