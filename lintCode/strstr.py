def strStr(source, target):
    # write your code here
    if source is None or target is None:
        return -1

    if len(target) > len(source):
        return -1

    if source == "" and target == "":
        return 0

    for i, vi in enumerate(source):
        print str(i) + ' ' + vi
        if len(target) > len(source) - i:
            # target is now longer than the remaining source, must be False
            return -1

        match = True
        j = 0
        while j < len(target):
            if target[j] != source[i+j]:
                match = False
                break
            else:
                j += 1

        if match:
            return i

    return -1


test1s = "source"
test1t = "target"
test2s = "abcdabcdefg"
test2t = "bcd"
test3t = "fga"

print strStr(test1s, test1t)
print strStr(test2s, test2t)
print strStr(test2s, test3t)
print strStr("", "")
print strStr("", "asdf")
print strStr("", None)
print strStr(None, "a")