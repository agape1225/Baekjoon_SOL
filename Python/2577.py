list_num = [0,0,0,0,0,0,0,0,0,0]

num1 = 0
num2 = 0
num3 = 0

num1 = int(input())
num2 = int(input())
num3 = int(input())

result = num1 * num2 * num3
result = str(result)

for i in result:
    list_num[int(i)] = list_num[int(i)] + 1

for i in list_num:
    print(i)

