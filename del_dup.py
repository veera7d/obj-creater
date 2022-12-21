
f=open("test.obj","r")
listt=[]
for i in f:
    listt.append(i.split())
print(listt)
print("len",len(listt))

found=False

def checkdup():
    for i in range(len(listt)-1,0,-1):
        for j in range(i,-1,-1):
            if listt[i]==listt[j] and listt[j][0]=='v' and i!=j:
                print(i+1,listt[i],"    ",j+1,listt[j])
                return [i,j]
    return None

def replaceVInF(dell,rep):
    for i in range(len(listt)):
        if listt[i][0]=='f':
            for j in range(len(listt[i])):
                if listt[i][j]==dell:
                    listt[i][j]=rep

def deldupv(dell,rep):
    del listt[dell]
    replaceVInF(dell,rep)

while(None != checkdup()):
    temp=checkdup()
    print(temp)
    deldupv(temp[0],temp[1])

print(listt)
print("len",len(listt))

f.close()

newf=open("new.obj","w")

for i in listt:
    for j in i:
        s=str(j)
        newf.write(s+" ")
    newf.write("\n")
newf.close()