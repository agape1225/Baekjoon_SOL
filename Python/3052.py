num_list = []

for i in range(0,42):
    num_list[i] = 0
    
for i in range(0,10):
    index = int(input())
    index = index % 42
    num_list[index] += 1

"""count = 0;

for i in num_list:

    if i != 0:
        count += 1
"""
print(len(num_list))
