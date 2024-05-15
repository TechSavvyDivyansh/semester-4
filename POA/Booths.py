def DecToBin(n, qval):
    global count
    replacedBin = []

    n=abs(n)
    
    #for Q qval=0 and for M qval=1

    if qval == 0:
        size = n.bit_length()+1     #if Q=50  binary->[1,1,0,0,1,0]     size=count=6
        count = size
    else:
        size = count          #if M=5   binary->[0,0,0,0,1,0,1]   size should be count+1=7
    
    for i in range(size):
        replacedBin.append(n % 2)
        n //= 2
    
    return replacedBin[::-1]


def add(A,M):
    carry=0
    sum=[]
    for i in range(len(A)-1,-1,-1):
        temp=A[i]+M[i]+carry
        if(temp>=2):
            carry=1
            sum.append(temp%2)
        else:
            carry=0
            sum.append(temp)
    return sum[::-1]

        
def comp(Mu,count):
    #Always Create a copy of the input list Mu
    Mu_copy = Mu[:]
    for i in range(len(Mu_copy)):
        if(Mu_copy[i] == 0):
            Mu_copy[i] = 1
        else:
            Mu_copy[i] = 0
    return add(Mu_copy, [0]*(count-1)+[1])




def shiftRight(A,Q,q):
    q=Q[-1]
    Q=[A[-1]]+Q[:-1]
    A=[A[0]]+A[:-1]
    
    return A,Q,q 




def initialize(m,q):

    if(abs(m)>=abs(q)):
        M=DecToBin(m,0)
        Q=DecToBin(q,1)
    else:
        Q=DecToBin(q,0)
        M=DecToBin(m,1)

    if(q<0):
        Q=comp(Q,count)[:]

    
    if(m<0):
        minusM=M[:]
        plusM=comp(M,count)[:]
    else:
        plusM=M[:]
        minusM=comp(M,count)[:]


    A = [0] * (count) 
    q=0

    n=len(Q)

    return A,Q,q,plusM,minusM,n 








def booths(A,Q,q,plusM,minusM,n):
    while(n!=0):
        print(f"n={n}->")
        if(Q[-1]==0 and q==1):
            print("+added")
            A=add(A,plusM)
        elif(Q[-1]==1 and q==0):
            A=add(A,minusM)
            print("-added")
        else:
            print("nothing added")

        print(f"A after addition:{A}")

        A,Q,q=shiftRight(A,Q,q)
        n-=1

        print(f"A:{A} , Q:{Q} ,q0:{q}\n")
    

    # final ans print binary to decimal
    final=A+Q
    print(final)
    if(final[0]==1):
        finalAns=comp(final,len(final))[:]
        finalAns=int(''.join(map(str,finalAns)),2)
        print(f"ans: -{finalAns}")
    
    else:
        finalAns=int(''.join(map(str,final)),2)
        print(f"ans: {finalAns}")
    








m=int(input("Enter multiplicand:"))
q=int(input("Enter multiplier:"))

A,Q,q,plusM,minusM,n = initialize(m,q)


print(f"A:{A} , Q:{Q} ,q0:{q}, plusM:{plusM}, minusM:{minusM}\n")

booths(A,Q,q,plusM,minusM,n)
# At,Qt,qt=shiftRight(A,Q,q)
# print(f"A:{At} Q:{Qt} q0:{qt}")