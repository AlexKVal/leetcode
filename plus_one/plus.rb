# @param {Integer[]} digits
# @return {Integer[]}
def plus_one(digits)
	number = digits.reduce{|n, d| n*10 + d}
	number += 1
	number.digits.reverse
end

# digits = [4,3,2,1] # [4,3,2,2]
digits = [9,9,9,9] # [1,0,0,0,0]

p plus_one(digits)
