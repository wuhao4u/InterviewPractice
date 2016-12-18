"""Write a HashTable class that stores strings
in a hash table, where keys are calculated
using the first two letters of the string."""

class HashTable(object):
    def __init__(self):
        self.table = [None]*10000

    def store(self, string):
        """Input a string that's stored in 
        the table."""
        hashVal = self.calculate_hash_value(string)

        # the given string value is hashable
        if hashVal != -1:

            # the bucket is empty right now, need to init the string with its 1st ele
            if not self.table[hashVal]:
                self.table[hashVal] = [string]
            else:
                # collision, add to the list
                self.table[hashVal].append(string)

    def lookup(self, string):
        """Return the hash value if the
        string is already in the table.
        Return -1 otherwise."""
        hashVal = self.calculate_hash_value(string)
        if hashVal != -1:
            if self.table[hashVal]:
                return hashVal
            else:
                return -1

    def calculate_hash_value(self, string):
        """Helper function to calulate a
        hash value from a string."""
        if len(string) > 1:
            hashVal = ord(string[0]) * 100 + ord(string[1])
            return hashVal
        else:
            print("the string is too short for this hash function")
            return -1
    
# Setup
hash_table = HashTable()

# Test calculate_hash_value
# Should be 8568
print hash_table.calculate_hash_value('UDACITY')

# Test lookup edge case
# Should be -1
print hash_table.lookup('UDACITY')

# Test store
hash_table.store('UDACITY')
# Should be 8568
print hash_table.lookup('UDACITY')

# Test store edge case
hash_table.store('UDACIOUS')
# Should be 8568
print hash_table.lookup('UDACIOUS')
