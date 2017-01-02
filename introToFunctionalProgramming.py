# https://maryrosecook.com/blog/post/a-practical-introduction-to-functional-programming

# Exercise 1. Try rewriting the code below as a map. 
# It takes a list of real names and replaces them with code names 
# produced using a more robust strategy.

# names = ['Mary', 'Isla', 'Sam']

# for i in range(len(names)):
#     names[i] = hash(names[i])

# print names
# => [6306819796133686941, 8135353348168144921, -1228887169324443034]
import random

# maps
def hash_names():
    names = ['Mary', 'Isla', 'Sam']
    secret_names = map(hash, names)
    return secret_names



# Exercise 2. Try rewriting the code below using map, reduce and filter. Filter takes a function and a collection. It returns a collection of every item for which the function returned True.

# people = [{'name': 'Mary', 'height': 160},
#           {'name': 'Isla', 'height': 80},
#           {'name': 'Sam'}]

# height_total = 0
# height_count = 0
# for person in people:
#     if 'height' in person:
#         height_total += person['height']
#         height_count += 1

# if height_count > 0:
#     average_height = height_total / height_count

#     print average_height
#     # => 120

# reduce and filter
def exercise2():
    people = [{'name': 'Mary', 'height': 160},
              {'name': 'Isla', 'height': 80},
              {'name': 'Sam'}]
    people_with_height = filter(lambda x: 'height' in x, people)
    height_total = reduce(lambda a, b: a + b['height'],
        people_with_height, 0)

    print(height_total)


def zero(s):
    if s[0] == "0":
        return s[1:]

def one(s):
    if s[0] == "1":
        return s[1:]

def rule_sequence(s, rules):
    for rule in rules:
        s = rule(s)
        if s == None:
            break

    return s

def rule_sequence_recur(s, rules):
    if (not s) or (len(rules) == 0):
        return s
    else:
        return rule_sequence_recur(s[1:], rules[1:])

if __name__ == '__main__':
    # print(hash_names())
    # exercise2()
    print rule_sequence('0101', [zero, one, zero])
    print rule_sequence_recur('0101', [zero, one, zero])
    # => 1
    
    print rule_sequence('0101', [zero, zero])
    print rule_sequence_recur('0101', [zero, zero])
    # => None
