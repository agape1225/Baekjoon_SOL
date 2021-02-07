
answer = []
count = 0


while True:

    a,b = input().split(" ")

    a = int(a)
    b = int(b)

    if a == 0 and b == 0:

        break

    answer.append(a + b)

    count += 1

i = 0

while count > 0:

    print(answer[i])

    i += 1
    count -= 1


