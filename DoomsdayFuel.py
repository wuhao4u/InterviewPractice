import fractions

def getProbMatrix(m):
    pm = []

    for i in range(len(m)):
        oRow = m[i]
        nRow = None
        oTotal = sum(oRow)

        allZeros = True
        for j in oRow:
            if j != 0:
                allZeros = False
                break

        if allZeros:
            nRow = [0 for x in range(len(oRow))]
            nRow[i] = 1
        else:
            nRow = []
            # this is not a terminal row
            for k in oRow:
                nRow.append(k / float(oTotal))

        pm.append(nRow)

    return pm


def getTerminalRows(m):
    res = []
    
    for row in m:
        allZeros = True
        for i in row:
            if i != 0:
                allZeros = False
                break

        res.append(allZeros)

    return res

def getProbVector(m, pm):
    oFirstRow = pm[0]
    res = None

    for i in range(500):
        probVector = []
        for col in zip(*pm):
            s = 0
            for i in zip(oFirstRow, col):
                # print(i[0] * i[1])
                s += i[0] * i[1]
            probVector.append(s)
        oFirstRow = probVector

    return probVector

def getNumDenum(probVector):
    num = []
    denum = []
    for v in probVector:
        denumObj = fractions.Fraction(v).limit_denominator()
        num.append(denumObj.numerator)
        denum.append(denumObj.denominator)

    return (num, denum)

def getFinalNumers(numers, denums, terminalRows):
    factors = []
    maxDenum = max(denums)
    for d in denums:
        factors.append(maxDenum / d)

    res = []
    for i in range(len(numers)):
        if terminalRows[i]:
            res.append(int(numers[i] * factors[i]))

    return res

def answer(m):
    probMatrix = getProbMatrix(m)
    terminalRows = getTerminalRows(m)
    probVector = getProbVector(m, probMatrix)
    numers, denums = getNumDenum(probVector)
    res = getFinalNumers(numers, denums, terminalRows)
    res.append(max(denums))
    return res

###############################################################################
def printMatrix(m):
    for row in m:
        print(row)
    print('\n')


# def main():
#     """ Test cases. Uncomment to use. """
#     # m = [[0, 2, 1, 0, 0], [0, 0, 0, 3, 4], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]

#     # m = [[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]

#     # m = [[0,1,0,1], [1, 0, 0, 1], [0, 0, 0, 0], [0, 0, 1, 0]]

#     # print(answer(m))

# if __name__ == '__main__':
#     main()