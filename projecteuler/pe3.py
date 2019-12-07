#真后悔...python真的慢...
allp = [2]

for i in range(3, 800000):
    flag = True
    for j in allp:
        if(i%j == 0):
            flag = False
            break
    if(flag):
        allp.append(i)
    if(i%100000 == 0):
        print("{:d}/8 done...".format(i/100000))
print("done...")
num = 600851475143
for i in allp:
    while(num % i == 0):
        num = num/i
        maxp = i
print(maxp)

