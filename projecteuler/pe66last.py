
def getmaxen(x):
    i = 2
    while i*i <= x:
        while x%i==0 and x!=i:
            x /= i
        i+=1
    return int(x)

maxx = 0
ans = -1
fp = open("pe66warning", "r")
for lastnum in fp:
    cd = int(lastnum)
    i = int(4294967296/cd-1)
    while True:
        cx = cd*i-1
        if cx > 10000000000:
            print("{} warning".format(cd))
            break
        #print("{} {}".format(cd, cx))
        tmp = cx*cx-1
        if tmp % cd == 0:
            tmp /= cd
            cy = int(tmp**0.5)
            if cy*cy == tmp:
                if cx > maxx:
                    maxx = cx
                    ans = cd
                print("{} {}".format(cd, cx))
                break
        cx = cd*i+1
        if cx > 10000000000:
            print("{} warning".format(cd))
            break
        #print("{} {}".format(cd, cx))
        tmp = cx*cx-1
        if tmp % cd == 0:
            tmp /= cd
            cy = int(tmp**0.5)
            if cy*cy == tmp:
                if cx > maxx:
                    maxx = cx
                    ans = cd
                print("{} {}".format(cd, cx))
                break
        i+=1
print(maxx)
print(ans)
