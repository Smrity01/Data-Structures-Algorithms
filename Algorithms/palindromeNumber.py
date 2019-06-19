class Solution:
    # @param A : integer
    # @return an integer
    def isPalindrome(self, A):
        count = 10
        if A < 10:
            return True
        while (A//count >= 10): 
            count = count*10
        print("before loop: ", A," count: ",count)
        while(A != 0):
            lastDigit = A % 10
            firstDigit = A // count
            if ( firstDigit != lastDigit):
                return False
            A  = (A % count) // 10 
            count = count / 100
        return True

ob = Solution()
print(ob.isPalindrome(1441))
        