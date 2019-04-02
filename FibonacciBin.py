def fibBin(n): 
    print(str(bin(fibonacci(n)))[2:])

def fibonacci(n):
    if n == 0 or n == 1:
        return 1

    res = [1 for x in xrange(n+1)]

    for i in xrange(2, n+1):
        res[i] = res[i-1] + res[i-2]

    return res[n]


if __name__ == "__main__":
    fibBin(0)
    fibBin(1)
    fibBin(10)
    fibBin(5)
    fibBin(5)