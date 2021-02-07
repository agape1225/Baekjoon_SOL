"""a = float(input("첫 번째 숫자 입력"))
b = float(input("두 번째 숫자 입력"))

answer = a / b

print("%9f"%answer)"""

"""in_sen = input()

print(in_sen)*/"""



#백준 알고리즘 20950번

"""num = int(input())

sums = []

for i in range(0,num):

    a, b = input().split()

    a = int(a)
    b = int(b)

    sums.append(a+b)

for i in range(0,num):

    print(sums[i])"""
    
#백준알고리즘 15552번 문제

import sys

num = int(input())

sums = []

for i in range(0, num):

    a, b = sys.stdin.readline().split()

    a = int(a)
    b = int(b)

    sums.append(a + b)

for i in range(0, num):

    print(sums[i])

