class Solution:
	# @param A : integer
	# @return a list of strings
	def fizzBuzz(self, A):
	    stringList = []
	    for i in range(1,A + 1):
	        if (i % (3*5) == 0 ):
	            stringList.append('FizzBuzz')
	        elif (i % 3 == 0):
	            stringList.append('Fizz')
	        elif (i % 5 == 0):
	            stringList.append('Buzz')
	        else:
	            stringList.append(str(i))
	    return stringList

ob = Solution()
print(ob.fizzBuzz(10))