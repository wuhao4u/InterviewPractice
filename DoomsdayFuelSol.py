from __future__ import division
from itertools import compress
from itertools import starmap
from operator import mul
import fractions

""" Test cases. Uncomment to use. """
# m = [[0, 2, 1, 0, 0], [0, 0, 0, 3, 4], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]

m = [[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]

# m = [[0,1,0,1], [1, 0, 0, 1], [0, 0, 0, 0], [0, 0, 1, 0]]


def convertMatrix(transMatrix):
  probMatrix = []

  for i in range(len(transMatrix)):
    row = transMatrix[i]
    newRow = []
    rowSum = sum(transMatrix[i])

    if all([v == 0 for v in transMatrix[i]]):
      # if all of the value in this row is 0
      for j in transMatrix[i]:
        newRow.append(0)

      # this the col denote possibility for this row is 1
      newRow[i] = 1
      probMatrix.append(newRow)

    else:
      # there are some possibility leads to another level
      for j in transMatrix[i]:
        if j == 0:
          newRow.append(0)
        else:
          newRow.append(j/rowSum)

      probMatrix.append(newRow)

  return probMatrix


def printMatrix(m):
  for row in m:
    print(row)

def answer(m):
  print("Given Matrix:")
  printMatrix(m)
  print('\n')

  # convert matrix numbers into probabilities
  probMatrix = convertMatrix(m)
  print("Probability Matrix:")
  printMatrix(probMatrix)
  print('\n')
  
  # find terminal states
  terminalStateFilter = []
  for row in range(len(m)):
    if all(x == 0 for x in m[row]):
      terminalStateFilter.append(True)
    else:
      terminalStateFilter.append(False)
  
  # multiply matrix by probability vector
  oldFirstRow = probMatrix[0]
  probVector = None
  for i in range(3000):
    probVector = [sum(starmap(mul, zip(oldFirstRow, col))) for col in zip(*probMatrix)]
    oldFirstRow = probVector

  print("Prob Vector after 3000 times: ")
  print(probVector)
  print('\n')
 
  # generate numerators
  numerators = []
  for i in probVector:
    numerator = fractions.Fraction(i).limit_denominator().numerator
    numerators.append(numerator)

  print("Numerators: ")
  print(numerators)
  print('\n')

  # generate denominators
  denominators = []
  for i in probVector:
    denominator = fractions.Fraction(i).limit_denominator().denominator
    denominators.append(denominator)

  print("Denominators: ")
  print(denominators)
  print('\n')

  # calculate factors to multiply numerators by
  factors = [max(denominators)/x for x in denominators]
  print("Factors")
  print(factors)
  print('\n')

  # multiply numerators by factors
  numeratorsTimesFactors = [a*b for a,b in zip(numerators, factors)]
  print("numerators times factors")
  print(numeratorsTimesFactors)
  print('\n')

  # filter numerators by terminal state booleans
  terminalStateNumerators = list(compress(numeratorsTimesFactors, terminalStateFilter))
  print("terminal state numerators")
  print(terminalStateNumerators)
  print('\n')

  # append numerators and denominator to answer
  answer = []
  for i in terminalStateNumerators:
    answer.append(i)
  answer.append(max(denominators))

  print("answer")
  print(answer)
  print('\n')

  return list(map(int, answer))
  
print(answer(m))
