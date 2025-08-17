#User function Template for python3
class Solution:
    def getSecondLargest(self, arr):
        # Code Here
        largest = secondLargest = float('-inf')
        unique = set(arr)
        for num in unique:
            if num > largest :
                secondLargest = largest
                largest = num
            elif num > secondLargest and num != largest:
                secondLargest = num
        return secondLargest if secondLargest!= float('-inf') else -1
         

#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.getSecondLargest(arr)
        print(ans)
        print("~")
# } Driver Code Ends