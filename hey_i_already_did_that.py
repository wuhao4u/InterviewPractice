def answer(n, b):
    # your code here
    existed = set()

    k = len(n)
    y = sorted(n)
    # print(y)
    x = y[::-1]
    # print(x)
    z = base10ToString(stringToBase10(x, b) - stringToBase10(y, b), k, b)
    # print(z)

    # counter = 0
    while z not in existed:
        existed.add(z)
        y = sorted(z)
        x = y[::-1]
        z = base10ToString(stringToBase10(x, b) - stringToBase10(y, b), k, b)
        # counter += 1


    counter = 0
    anchor = z
    y = sorted(z)
    x = y[::-1]
    z = base10ToString(stringToBase10(x, b) - stringToBase10(y, b), k, b)
    counter += 1

    while z != anchor:
        y = sorted(z)
        x = y[::-1]
        z = base10ToString(stringToBase10(x, b) - stringToBase10(y, b), k, b)
        counter += 1

    return counter

def stringToBase10(s, b):
    # if b == 10:
        # return int(s)

    res = 0
    reveredS = s[::-1]
    multiplier = 1
    for i in reveredS:
        res += int(i) * multiplier
        multiplier *= b

    return res

def base10ToString(base10Num, k, b):
    # if b == 10:
        # return str(base10Num)

    res = ""
    if base10Num == 0:
        return 0

    digits = []
    while base10Num:
        digits.append(str(int(base10Num % b)))
        base10Num //= b

    if (len(digits) < k):
        looper = k - len(digits)
        for i in xrange(looper):
            digits.append('0')

    # print("digit")
    # print(digits)
    digits = digits[::-1]
    return "".join(digits)

if __name__ == '__main__':
    # print(stringToBase10("1211", 10))
    # print(base10ToString(575, 10))
    # print(answer("1211", 10))
    print(answer("210022", 3))