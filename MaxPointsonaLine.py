# Definition for a point
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

def maxPoints(points):
	xDict = {}
	for p in points:
		if p[0] in xDict.keys():
			if p[1] > xDict[p[0]]:
				xDict[p[0]] = p[i]
		else:
			xDict[p[0]] = p[1]
		
	for item in xDict.items():
		return item[1]

pl1 = [(5,2), (3,4), (0,1), (-11,-100), (3.1415, 2)]
pl2 = [(0,0)]

print maxPoints(pl1)
print maxPoints(pl2)