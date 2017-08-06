import fractions

""" Test cases. Uncomment to use. """
# m = [[0, 2, 1, 0, 0], [0, 0, 0, 3, 4], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]

m = [[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]

# m = [[0,1,0,1], [1, 0, 0, 1], [0, 0, 0, 0], [0, 0, 1, 0]]

def calculateProbability(original):
    probs = []

    for r in range(original):
        row = original[i]
        nRow = []
        total = sum(row)
        for c in range(len(row)):
            nRow.append((float) c / total)