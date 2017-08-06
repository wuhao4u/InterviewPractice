# Complete the function below.


def  GigawattPower(batteryOne, batteryTwo, gigawattTarget):
    if (not batteryOne) or (not batteryTwo):
        return None

    if len(batteryOne) == 0 or len(batteryTwo) == 0:
        return None

    dictB1 = {}
    dictB2 = {}

    for index, val in enumerate(batteryOne):
        dictB1[val] = index

    for index, val in enumerate(batteryTwo):
        dictB2[val] = index

    for k in dictB1.keys():
        if (gigawattTarget - k) in dictB2.keys():
            return True

    return False


test1a = [5,7,2,4]
test1b = [-3,0,1]

test2a = [6,3,1,9,5,4,0,1,-29,12,45,2,6]
test2b = [1,2,3,4,5,6,7,8,9,10,11,12,13]

print(GigawattPower(test1a, test1b, 8))
print(GigawattPower(test2a, test2b, 100))