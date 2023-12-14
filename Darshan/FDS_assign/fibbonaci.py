def fibbonaci(list,key,n):
    
    a=0
    b=1
    f=a+b
    
    
    while(f<n):
        a=b
        b=f
        f=a+b
    

    offset=-1

    while(f>1):

        i=min(offset+a,n-1)


        if(list[i]<key):
            f=b
            b=a
            a=f-b
            offset=i
        elif(list[i]>key):
            f=a
            b=b-a
            a=a-b
        else:
            return i
    return -1

#--------------------------------------------
list=[]

n = int(input())



for i in range(0,n):
    ele=int(input())
    list.append(ele)
    
key=int(input())

result= fibbonaci(list,key,n)

if result!=-1:
    print("key found at:" , result)
else:
    print("key not found")
    

#------------------------------------------