'''
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
'''
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
        alphabets = {1: 'A', 2:'B', 3: 'C', 4: 'D',
            5: 'E', 6: 'F', 7: 'G', 8: 'H',
            9: 'I', 10: 'J', 11: 'K', 12: 'L',
            13: 'M', 14: 'N', 15: 'O', 16: 'P',
            17: 'Q', 18: 'R', 19: 'S', 20: 'T',
            21: 'U', 22: 'V', 23: 'W', 24: 'X',
            25: 'Y', 26: 'Z'}
        title = ''
        while (A > 0):
            if A % 26 == 0:
                title = 'Z' + title
                A = (A // 26) - 1
            else:
                title = alphabets[A % 26] + title
                A = A // 26
        return title
a = Solution()
print(a.titleToNumber(943566))