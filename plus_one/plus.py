def plusOne(digits):
	newLength = len(digits)
	carryover = False

	idx = newLength - 1 # start from the right
	while idx >= 0:
		if digits[idx] == 9:
			digits[idx] = 0
			carryover = True
		else:
			digits[idx] += 1
			carryover = False
			break
		idx -= 1

	if carryover: newLength += 1
	result = [0] * newLength
	if carryover: result[0] = 1
	idx = 1 if carryover else 0
	for digit in digits:
		result[idx] = digit
		idx += 1
	return result

digits = [4,3,2,9] # [4,3,3,0]
# digits = [1,9] # [2,0]
# digits = [9,9,9,9] # [1,0,0,0,0]

print(plusOne(digits))
