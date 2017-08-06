def answer(s):
    result = ""
    for c in s:
        if c.islower():
            result += decipher(c)
        else:
            result += c

    return result

def decipher(c):
    normal = "abcdefghijklmnopqrstuvwxyz"
    i = 0
    for letter in normal:
        if letter == c:
            break
        i += 1
    return normal[len(normal) - 1 - i]


if __name__ == '__main__':
    s1 = "wrw blf hvv ozhg mrtsg'h vkrhlwv?"
    s2 = "Yvzs! I xzm'g yvorvev Lzmxv olhg srh qly zg gsv xlolmb!!"
    print(answer(s1))
    print(answer(s2))