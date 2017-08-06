def fooBar():
    for i in xrange(1, 101):
        if i % 3 == 0 and i % 5 == 0:
            print("FooBar")
        elif i % 3 == 0:
            print("Foo")
        elif i % 5 == 0:
            print("Bar")
        else:
            print(i)

def evenIntegers(n):
    return [i for i in xrange(1, n+1) if i % 2 == 0]

def removeDuplicates(wList):
    appearance = {}
    for w in wList:
        if w not in appearance:
            appearance[w] = 1

    return sorted(appearance.keys())

if __name__ == '__main__':
    # fooBar()
    # print(evenIntegers(100))
    words = ['one', 'one', 'two', 'three', 'three', 'two']
    print(removeDuplicates(words))