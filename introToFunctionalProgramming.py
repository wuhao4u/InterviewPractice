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

if __name__ == '__main__':
    print(hash_names())