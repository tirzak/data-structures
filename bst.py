class Node:
    def __init__ (self,item):
        self.left=None
        self.right=None
        self.item=item

class Tree:
    def __init__ (self):
        self.root=None
    def insert(self,item):
        if self.root==None:
            self.root=Node(item)
        else:
            self._insertHelp(self.root,item)
    def _insertHelp(self,node,item):   
        if item < node.item:
            if node.left is not None:
                self._insertHelp(node.left,item)
            else:
                node.left=Node(item)
        else: 
            if node.right is not None:
                self._insertHelp(node.right,item)
            else:
                node.right=Node(item)
    def search(self,item):
        if self.root==None:
            return None
        else:
            self._searchHelp(self.root,item)   
    def _searchHelp(self,node,item):
        if item == node.item:
            return node.item
        if item < node.item:  
            if node.left is not None:
                return(self._searchHelp(node.left,item))
        else: 
            if node.right is not None:
                return(self._searchHelp(node.right,item))

    def searchIterative(self,item):
        current=self.root
        if current.item==item:
            return item
        else:
            while current is not None:
                if current.item==item:
                    return item
                elif current.item>item:
                    current=current.left
                else:
                    current=current.right
    def printTree(self):
        if self.root is not None:
            self._printTreePreOrder(self.root)

    def _printTreePostOrder(self, node):
        if node is not None:
            
            self._printTreePostOrder(node.left)
            
            self._printTreePostOrder(node.right)
            print(str(node.item) + ' ')
    def _printTreeInOrder(self, node):
        if node is not None:
            
            self._printTreeInOrder(node.left)
            print(str(node.item) + ' ') 
            self._printTreeInOrder(node.right)
    def _printTreePreOrder(self, node):
        if node is not None:
            print(str(node.item) + ' ')     
            self._printTreePreOrder(node.left)
            
            self._printTreePreOrder(node.right)
                              


              
                     


x=Tree()
l=[20,1,2,3,-1,-4,-3]

for i in l:
    x.insert(i)
x.printTree()

# y=x.searchIterative(4)
# print('%dG'%y)

                

                    







