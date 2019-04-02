import collections

def main():
    od = collections.OrderedDict()

    od["first added"] = 0
    od["Colleen"] = 29
    od["Hao"] = 28
    od["May"] = 52
    od["Qiang"] = 56
    od["last added"] = 99

    printOD(od)

    # popitem(), default pop the last added
    print(od.popitem(last=True))
    print(od.popitem(last=False))

    od.move_to_end("Hao")
    printOD(od)

    od.move_to_end("Hao", last=False)
    printOD(od)

    print(od.get("non exist"))

    first = next(iter(od))
    x = 0



def printOD(od: collections.OrderedDict):
    print("------------------------------")
    for k, v in od.items():
        print("{} : {}".format(k, v))

if __name__ == "__main__":
    main()