a=input()
countupper=0
countlower=0
for i in a:
    if i.isupper():
        countupper+=1
    elif i.islower():
        countlower+=1
if(countupper<=countlower):
    print(a.lower())
    
else:
    print(a.upper())
    

