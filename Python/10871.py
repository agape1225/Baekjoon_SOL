

answer = []
count = 0

size,num = input().split(" ")

size = int(size)
num = int(num)

num_input = input()
num_input = num_input.split(" ")


for i in range(0,size):

    num_input[i] = int(num_input[i])

    if num_input[i] < num:

        answer.append(num_input[i])

        count += 1

for i in range(0,count):

    print(answer[i],end = " ")
