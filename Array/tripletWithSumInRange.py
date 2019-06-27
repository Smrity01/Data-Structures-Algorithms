'''
Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 . 
Return 1 for true or 0 for false
'''
class Solution:
    def solve(self, A):
        a = float(A[0])
        b = float(A[1])
        c = float(A[2])
        for i in range(3, len(A)):
            if a + b + c > 1 and a + b + c < 2:
                return 1
            if a + b + c < 1:
                if a < b and a < c:
                    a = float(A[i])
                elif b < c and b < a:
                    b = float(A[i])
                elif c < b and c < a:
                    c = float(A[i])
            else:
                if a > b and a > c:
                    a = float(A[i])
                elif b > c and b > a:
                    b = float(A[i])
                elif c > b and c > a:
                    c = float(A[i])
        if a + b + c > 1 and a + b + c < 2:
            return 1
        else:
            return 0
def main():
    s = Solution()
    A = [ "2.673662", "2.419159", "0.573816", "2.454376", "0.403605", "2.503658", "0.806191" ]
    print(s.solve(A))

if __name__ == "__main__":
    # calling main function
    main()
