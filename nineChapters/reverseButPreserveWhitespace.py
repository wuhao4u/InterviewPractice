# Complete the function below.


def reverseButPreserveWhitespace(reverseMe):
    if not reverseMe:
        return reverseMe
    if len(reverseMe) <= 1:
        return reverseMe

    ret = reverseMe
    splitedRM = reverseMe.strip().split()
    reversedRM = [s[::-1] for s in splitedRM]
    reversedContent = ''.join(reversedRM)

    ret = ''
    i = 0
    rPtr = 0
    while i < len(reverseMe):
        if reverseMe[i] == ' ':
            ret += ' '
        else:
            ret += reversedContent[rPtr]
            rPtr += 1
        i += 1


    return ret

test1 = "Let's meet     in the  owlery today "
test2 = "Secret Message     test"

print(reverseButPreserveWhitespace(test1))
print(reverseButPreserveWhitespace(test2))