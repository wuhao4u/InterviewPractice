def isNumber(s):
	s = s.strip()
	try:
		res = float(s)
		return True
	except ValueError:
		return False

print isNumber("0")
print isNumber(" 0.1")
print isNumber("abc")
print isNumber("1 a")
print isNumber("2e10")