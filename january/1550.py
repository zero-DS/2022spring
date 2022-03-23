str=input()
sum=0
pow=0
for i in range(len(str)-1,-1,-1):
    if str[i]=='A':
        sum+=10*(16**pow)
    elif str[i]=='B':
        sum+=11*(16**pow)
    elif str[i]=='C':
        sum+=12*(16**pow)
    elif str[i]=='D':
        sum+=13*(16**pow)
    elif str[i]=='E':
        sum+=14*(16**pow)
    elif str[i]=='F':
        sum+=15*(16**pow)
    else:
        sum+=int(str[i])*(16**pow)
    pow+=1
print(sum)