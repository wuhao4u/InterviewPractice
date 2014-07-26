def reverseWords(s):
	temp = []
	counter = 0
	res = ''
	s = s.split()
	for i in s:
		counter = counter + 1
		temp.append(i)
	while counter > 0:
		counter = counter - 1
		res = res + temp[counter] + ' '
		
	return res.strip()

reverseWords("the sky is blue")