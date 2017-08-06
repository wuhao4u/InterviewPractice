# Complete the function below.

def improbabilityCalculator(coordinates, remove):
    if not coordinates:
        return coordinates

    if remove >= len(coordinates):
        return '0'
    elif remove < 0:
        return coordinates
    elif remove == 0:
        return coordinates

    lHalf = coordinates[:remove+1]
    rHalf = coordinates[remove:]

    # find min number in the left half
    min = 10
    i = 0
    anchor = -1

    while i < len(lHalf):
        if int(lHalf[i]) < min:
            min = int(lHalf[i])
            anchor = i
        i += 1

#     if the anchor is the last element in lhalf, we'll just remove the head
    if anchor == len(lHalf) - 1:
        return coordinates[remove:]
    else:
        lHalf = lHalf[anchor]

    return lHalf + getRightHalf(rHalf, 1)

#     right half
def getRightHalf(coordinates, remove):
    while remove > 0:
        for i, v in enumerate(coordinates):
            if coordinates[i] > coordinates[i+1]:
                del coordinates[i]
            else:
                del coordinates[i+1]
            break
        remove -= 1
    return ''.join(coordinates)

print(improbabilityCalculator("746209249",5))
print(improbabilityCalculator("64738929",0))
print(improbabilityCalculator("12345",6))
print(improbabilityCalculator("43597658", 2))
