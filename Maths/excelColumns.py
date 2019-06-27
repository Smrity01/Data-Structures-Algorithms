'''
Given a column title as appears in an Excel sheet, return its corresponding column number.
Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 
'''
class Solution:
    def titleToNumber(self, A):
        alphabets = {'A': 1, 'B': 2, 'C': 3, 'D': 4,
	        'E': 5, 'F': 6, 'G': 7, 'H': 8,
	        'I': 9, 'J': 10, 'K': 11, 'L': 12,
	        'M': 13, 'N': 14, 'O': 15, 'P': 16,
	        'Q': 17, 'R': 18, 'S': 19, 'T': 20,
	        'U': 21, 'V': 22, 'W': 23, 'X': 24,
	        'Y': 25, 'Z': 26}
        stringLength = len(A)
        columnNumber = 0
        for i in range(stringLength):
            value = alphabets[A[i]]
            power = stringLength - (i + 1)
            columnNumber = columnNumber + (26 ** power) * value
        return columnNumber

a = Solution()
print(a.titleToNumber('AA'))