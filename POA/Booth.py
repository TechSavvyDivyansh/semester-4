
def arithmetic_right_shift(ac, q, qi):
    q_last = q[-1] 
    qi = q_last
    q = q[:-1]

    repeated = [ac[0]] 
    ac = repeated + ac

    ac_last = ac[-1] 
    q = [ac_last] + q
    ac = ac[:-1]

    return ac, q, qi

def add(a, b, carry = 0):
    ans = [0] * len(a)
    i = len(a) - 1
    
    while i >= 0:
        bit = carry + a[i] + b[i]
        
        if bit == 0:
            carry, ans[i] = 0, 0
        elif bit == 1:
            carry, ans[i] = 0, 1
        elif bit == 2:
            carry, ans[i] = 1, 0
        elif bit == 3:
            carry, ans[i] = 1, 1
        
        i -= 1
    return ans
def ones_complement(a):
    c = []
    for dig in a:
        if dig == 0:
            c.append(1)
        else:
            c.append(0)
    return c
def twos_complement(a):
    return add(ones_complement(a), [0]*len(a) , 1)

def booths_algo(m, q):
    sc = len(m)
    qi = 0
    ac = [0] * sc
    m_2comp = twos_complement(m)
    action = "  Initial"
    print("n        A                       Q                   Action")
    print(n, "      ", ac, "      ", q, "      ", action)

    while sc > 0:
        if q[-1] == 0 and qi == 1:
            ac = add(ac, m)
            action = "   A = A+M"
            print(n, "      ", ac, "      ", q, "      ", action)


        elif q[-1] == 1 and qi == 0:
            ac = add(ac, m_2comp)            
            action = "   A = A-M"
            print(n, "      ", ac, "      ", q, "      ", action)


        sc -= 1
        ac, q, qi = arithmetic_right_shift(ac, q, qi)     
        action = "   Arithmetic Right Shift"
        print(n, "      ", ac, "      ", q, "      ", action)

    return ac + q

def binaryToDecimal(binary):
    is_negative = False
    if binary[0] == 1:
        binary =  twos_complement(binary)
        is_negative = True

    binary = binary[1:]
    decimal = 0
    for dig in range(len(binary)):
        decimal += binary[dig] * 2**(len(binary)-1-dig)
    
    if is_negative: 
        return -decimal
    
    return decimal

def decimalToBinary(num, max_l = 4):
    is_negative = False
    if num < 0:
        is_negative = True
        num = -num

    binary = []
    rem = 0

    while num != 0:
        rem = num % 2
        num = num // 2
        binary = [rem] + binary
    
    if max_l > len(binary):
        more_zer = max_l - len(binary)
        binary = [0] * more_zer + binary

    if is_negative:
        return twos_complement(binary)
    
    return binary

num1 = int(input("Multiplicand: "))
num2 = int(input("Multiplier: "))
n = int(input("Number of digits(including signed bit): "))

bool1 = decimalToBinary(num1, n)
bool2 = decimalToBinary(num2, n)

print("Boolean Multiplicand: ", bool1)
print("Boolean Multiplier: ", bool2)

print("Integer Multiplicand: ", binaryToDecimal(bool1))
print("Integer Multiplier: ", binaryToDecimal(bool2))

mul = booths_algo(bool1, bool2)

print("\nResult:")
print("Boolean: ", mul)
print("Integer: ", binaryToDecimal(mul))