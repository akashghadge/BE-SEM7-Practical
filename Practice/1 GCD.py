a = int(input())
b = int(input())
n, m = a, b
while(b != 0):
    temp = b
    b = a % b
    a = temp


def gcd(a, b):
    if(b == 0):
        return abs(a)
    else:
        return gcd(b, a % b)


print(a)


print(gcd(n, m))
