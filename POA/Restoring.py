
def DecToBin(n, bitsize):
    replacedBin=[]
    for i in range(bitsize):
        replacedBin.append(n%2)
        n//=2
    return replacedBin[::-1]


def BinaryToDec(A,Q):
    quotient=int(''.join(map(str,Q)),2)     #''.join(map(st,Q)) converts each Q to string and concats them. int(1100,2),here 1100 is now string  ,2 converts to decimal

    remainder=int(''.join(map(str,A)),2)
    return remainder,quotient



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


        
def comp(Mu):
    #Always Create a copy of the input list Mu
    Mu_copy = Mu[:]
    for i in range(len(Mu_copy)):
        if(Mu_copy[i] == 0):
            Mu_copy[i] = 1
        else:
            Mu_copy[i] = 0
    return add(Mu_copy, [0, 0, 0, 0, 1])



def shiftLeft(A,Q):
    A=A[1:]
    A.append(Q[0])
    Q=Q[1:]
    Q.append('n')
    return A,Q



def restore(A,Q,M,n):
    print("---------------RESTORING START----------------")
    Main=M[:]
    compl=comp(M)[:]
    
    while(n!=0):

        print(f"!!n={n}\n")
        A,Q=shiftLeft(A,Q)
        print(f'After Shift Left=> A:{A},Q:{Q}')
        A=add(A,compl)

        print(f'After A-M=> A:{A},Q:{Q}')
        if(A[0]==1):
            Q[3]=0
            A=add(A,Main)
            print(f'After restore and Q0=0=> A:{A},Q:{Q}')
        else:
            Q[3]=1
            print(f'After Q[0]=1=> A:{A},Q:{Q}')
        n-=1

    print(f'\n Quotient is:{Q} and remainder is:{A}')
    remainder,quotient=BinaryToDec(A,Q)
    print(f'Quotient:{quotient} and remainder is:{remainder}')
    
        



q=int(input("Enter dividend:"))
Q=DecToBin(q,4)
m=int(input("Enter divisor:"))
M=DecToBin(m,5)
A=[0,0,0,0,0]

n=len(Q)
restore(A,Q,M,n)


# DecToBin(13,4)
# DecToBin(5,5)
