def evalRPN(tokens):
	res = 0
	l = len(tokens)
	counter = 0
	while counter < len(tokens):
		if tokens[counter] == '+':
			if res==0:
				res = int(tokens[counter-1]) + int(tokens[counter-2])
				tokens.pop(counter)
				counter = counter  - 1
				print tokens
				tokens.pop(counter)
				counter = counter  - 1
				print tokens
				tokens.pop(counter)
				counter = counter  - 1
				print tokens
				continue
			else:
				res = res + int(tokens[counter-1])
				tokens.pop(counter)
				counter = counter  - 1
				print tokens
				tokens.pop(counter)
				counter = counter  - 1
				print tokens
				
		elif tokens[counter] == '*':
			if res==0:
				res = int(tokens[counter-1]) * int(tokens[counter-2])
				for x in range(0,3):
					if counter > 1:
						tokens.pop(counter)
						counter = counter  - 1
						print counter
						print tokens
					else:
						return
				continue
			else:
				res = res * int(tokens[counter-1])
				for x in range(0,2):
					if counter > 1:
						tokens.pop(counter)
						counter = counter  - 1
						print counter
						print tokens
					else:
						return
				continue
				
		print res
		counter = counter + 1


l1 = ["2", "1", "+", "3", "*"]
l2 = ["4", "13", "5", "/", "+"]
evalRPN(l1)
#evalRPN(l2)
