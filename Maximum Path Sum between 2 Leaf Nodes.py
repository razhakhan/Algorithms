#User function Template for python3

'''
# Node Class:
class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None
        '''
class Solution:
    
    def __init__(self):
        self.s=-999999
        
    def deep(self, root):
        # if null node
        if not root:
            return 0
        
        lsum=self.deep(root.left)   # go deeper towards left
        rsum=self.deep(root.right)  # go deeper towards right
        
        # if this is a leaf node (left and right none)
        if not root.left and not root.right:
            return root.data
        
        # can't go deeper in left subtree    
        if not root.left:
            return root.data+rsum
        
        # can't go deeper in right subtree    
        if not root.right:
            return root.data+lsum
        
        # we need to find max of [ (left max sum + root node + right max sum ), only left max sum, only right max sum ]
        # the greater out of these three will be printed in maxPathSum method
        self.s=max(self.s, root.data+lsum+rsum)
        return max(root.data+lsum, root.data+rsum)  # return the best path, either right or left 
    
    def maxPathSum(self, root):
        ans=self.deep(root)
        if not root.left or not root.right:
            self.s=max(self.s, ans)
        return self.s

#{ 
 # Driver Code Starts
#Initial Template for Python 3

from collections import deque
import sys
sys.setrecursionlimit(10**6)  #Increasing the limit of recursion
# Tree Node
class Node:
   def __init__(self, val):
       self.right = None
       self.data = val
       self.left = None


# Function to Build Tree   
def buildTree(s):
   #Corner Case
   if(len(s)==0 or s[0]=="N"):           
       return None
       
   # Creating list of strings from input 
   # string after spliting by space
   ip=list(map(str,s.split()))
   
   # Create the root of the tree
   root=Node(int(ip[0]))                     
   size=0
   q=deque()
   
   # Push the root to the queue
   q.append(root)                            
   size=size+1 
   
   # Starting from the second element
   i=1                                       
   while(size>0 and i<len(ip)):
       # Get and remove the front of the queue
       currNode=q[0]
       q.popleft()
       size=size-1
       
       # Get the current node's value from the string
       currVal=ip[i]
       
       # If the left child is not null
       if(currVal!="N"):
           
           # Create the left child for the current node
           currNode.left=Node(int(currVal))
           
           # Push it to the queue
           q.append(currNode.left)
           size=size+1
       # For the right child
       i=i+1
       if(i>=len(ip)):
           break
       currVal=ip[i]
       
       # If the right child is not null
       if(currVal!="N"):
           
           # Create the right child for the current node
           currNode.right=Node(int(currVal))
           
           # Push it to the queue
           q.append(currNode.right)
           size=size+1
       i=i+1
   return root

if __name__=="__main__":
    t=int(input())
    for _ in range(0,t):
        s=input()
        root=buildTree(s)
        ob = Solution()
        print(ob.maxPathSum(root))
# } Driver Code Ends


'''

Example 1:

Input:      
           3                               
         /    \                          
       4       5                     
      /  \      
    -10   4                          
Output: 16
Explanation:
Maximum Sum lies between leaf node 4 and 5.
4 + 4 + 3 + 5 = 16.
Example 2:

Input:    
            -15                               
         /      \                          
        5         6                      
      /  \       / \
    -8    1     3   9
   /  \              \
  2   -3              0
                     / \
                    4  -1
                       /
                     10  
Output:  27
Explanation:
The maximum possible sum from one leaf node 
to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)


'''
