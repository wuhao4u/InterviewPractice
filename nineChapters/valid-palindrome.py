import string
def isPalindrome(s):
    # Write your code here
    if s == "" or len(s) == 0:
        return True
        
    s = s.lower()
    # s = s.translate(None, string.punctuation)
    s = s.replace(' ', '')
    for c in string.punctuation:
        s = s.replace(c, '')

    print(s)
    
    fPtr = 0
    bPtr = len(s) - 1
    
    while fPtr < bPtr:
        if not s[fPtr] == s[bPtr]:
            return False
        fPtr += 1
        bPtr -= 1
            
    return True

test1 = "A man, a plan, a canal: Panama"
test2 = "race a car"

for c in string.punctuation:
    print c

print(isPalindrome(test1))
print(isPalindrome(test2))