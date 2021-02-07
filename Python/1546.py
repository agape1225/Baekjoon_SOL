size = int(input())
score = input().split(' ')
for i in range(size):
    score[i] = int(score[i])

maxNum = max(score)

for i in range(size):
    score[i] = (score[i] / maxNum) * 100

avg = sum(score) / size

print(avg)
