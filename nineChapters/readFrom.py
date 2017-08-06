import string

class Calculator(object):
    """docstring for Calculator"""
    def __init__(self, data):
        super(Calculator, self).__init__()
        self.cmds = ""
        if not data:
            self.data = 0
        self.data = data

    def plus(self, val):
        self.data += val
        return Calculator(val)

    def minus(self, val):
        self.data -= val
        return Calculator(val)

    def times(self, val):
        self.data *= val
        return Calculator(val)

    def divide(self, val):
        if val == 0:
            print("Value Error: divide by 0.")

        self.data /= val
        return Calculator(val)

    def formula(self):
        return self.cmds

# read arithmatic formula from a string
    def readFrom(self, val):
        if not val:
            return None

        self.cmds = val

        splited_formula = val
        splited_formula = splited_formula.replace('+', " + ")
        splited_formula = splited_formula.replace('-', " - ")
        splited_formula = splited_formula.replace('*', " * ")
        splited_formula = splited_formula.replace('/', " / ")
        splited_formula = splited_formula.split()
        print(splited_formula)

        try:
            self.data = int(splited_formula[0])
        except ValueError:
            print("Invalid input.")

        i = 1
        while i < len(splited_formula) - 1:
            try:
                second_ele = int(splited_formula[i+1])
            except ValueError:
                print("Wrong formula.")
                return self.data

            if splited_formula[i] == '+':
                self.plus(second_ele)
            elif splited_formula[i] == '-':
                self.minus(second_ele)
            elif splited_formula[i] == '*':
                self.times(second_ele)
            elif splited_formula[i] == '/':
                self.divide(second_ele)
            i += 2

        return self.data

# 1
test1 = "77/5+2*4/10"
print(Calculator(0).readFrom(test1))