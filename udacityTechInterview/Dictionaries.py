"""Time to play with Python dictionaries!
You're going to work on a dictionary that
stores cities by country and continent.
One is done for you - the city of Mountain 
View is in the USA, which is in North America.

You need to add the cities listed below by
modifying the structure.
Then, you should print out the values specified
by looking them up in the structure.

Cities to add:
Bangalore (India, Asia)
Atlanta (USA, North America)
Cairo (Egypt, Africa)
Shanghai (China, Asia)"""

locations = {'North America': {'USA': ['Mountain View', 'Atlanta']},
"Asia" : {"India": ["Bangalore"], "China": ["Shanghai"]},
"Africa": {"Egypt": ["Cairo"]}}

"""Print the following (using "print").
1. A list of all cities in the USA in
alphabetic order.
2. All cities in Asia, in alphabetic
order, next to the name of the country.
In your output, label each answer with a number
so it looks like this:
1
American City
American City
2
Asian City - Country
Asian City - Country"""
print("1")
sortedUSACities = sorted(locations["North America"]["USA"])
for c in sortedUSACities:
    print(c)

print('2')
asiaCityNCountry = []
for kvpair in locations["Asia"].items():
    for city in kvpair[1]:
        asiaCityNCountry.append((city, kvpair[0]))

sortedAsiaCityCountry = (sorted(asiaCityNCountry, key=lambda pair : pair[0]))

for p in sortedAsiaCityCountry:
    print("{} - {}".format(p[0],p[1]))