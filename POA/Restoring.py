
def DecToBin(n, qval):
    global count
    replacedBin = []
    
    #for Q qval=0 and for M qval=1

    if qval == 0:
        size = n.bit_length()     #if Q=50  binary->[1,1,0,0,1,0]     size=count=6
        count = size
    else:
        size = count + 1          #if M=5   binary->[0,0,0,0,1,0,1]   size should be count+1=7
    
    for i in range(size):
        replacedBin.append(n % 2)
        n //= 2
    
    return replacedBin[::-1]



def BinaryToDec(A, Q):
    quotient = int(''.join(map(str, Q)), 2)
    remainder = int(''.join(map(str, A)), 2)
    return remainder, quotient



def add(A, M):
    carry = 0
    sum = []
    
    for i in range(len(A) - 1, -1, -1):
        temp = A[i] + M[i] + carry
        if temp >= 2:
            carry = 1
            sum.append(temp % 2)
        else:
            carry = 0
            sum.append(temp)
    
    return sum[::-1]



def comp(Mu):
    Mu_copy = Mu[:]
    for i in range(len(Mu_copy)):
        if Mu_copy[i] == 0:
            Mu_copy[i] = 1
        else:
            Mu_copy[i] = 0
    return add(Mu_copy, [0]*(count)+[1])       #1 that has to be added should be equal to size of M i.e. count+1 hence [0]*count+[1]



def shiftLeft(A, Q):
    A = A[1:] + [Q[0]]
    Q = Q[1:] + [0]
    return A, Q



def restore(A, Q, M, n):
    print("---------------RESTORING START----------------")
    Main = M[:]
    compl = comp(M)[:]
    
    while n != 0:

        # print(f"n=>{n}\n")
        A, Q = shiftLeft(A, Q)
        # print(f'After Shift Left=> A:{A}, Q:{Q}')
        A = add(A, compl)

        # print(f'After A-M=> A:{A}, Q:{Q}')
        
        if A[0] == 1:
            Q[-1] = 0
            A = add(A, Main)
            # print(f'After restore and Q0=0=> A:{A}, Q:{Q}')
        else:
            Q[-1] = 1
            # print(f'After Q[0]=1=> A:{A}, Q:{Q}')
        n -= 1

    print(f'\nQuotient is: {Q} and remainder is: {A}')
    remainder, quotient = BinaryToDec(A, Q)
    print(f'Quotient: {quotient} and remainder is: {remainder}')



q = int(input("Enter dividend: "))
Q = DecToBin(q, 0)
m = int(input("Enter divisor: "))
M = DecToBin(m, 1)
A = [0] * (count + 1)             #size of A=size of M i.e. count+1


n = len(Q)
restore(A, Q, M, n)
