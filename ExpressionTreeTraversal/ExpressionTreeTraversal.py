import re

# Class defining a node
class Node:
    def __init__(self, data) :
        self.data = data
        self.left = None
        self.right = None

# Creates an expression tree from an infix expression
class InfixExpressionTree:
        
    # Creates the tree by building nodes
    def makeNode(self, op, tree):
        """ Each calling of this function creates a single root with two children. Roots are always operators. Children are either numbers or 
        a pre-existing subtree who's root is an operator.  """

        # Takes the last operator in the provided operator list and uses it as the root
        root = Node(op.pop())
        
        # Last and second to last elements become right and left children respectively 
        root.right = tree.pop()
        root.left = tree.pop()

        # Adds the created node to the tree list
        tree.append(root)

    # Function to check if the current character is an operator
    def IsOperator(self, s):
        return s in "+-*/)"
        
    
    # Main function that implements makeNode
    def binaryExpressionTree(self, s):

        # Defines the priority of each operator
        priority = dict()
        priority[')'] = 0
        priority['-'] = 2
        priority['+'] = 2
        priority['*'] = 3
        priority['/'] = 3
        
        # Creates stacks to hold operators and the current tree/numbers
        tree = []
        operators = []

        # Defines criteria for regular expressions
        regex_expression = "[\/\+\-\*\(\)]|[0-9][0-9][0-9]|[0-9][0-9]|[0-9]"

        # Uses regular expressions to split the given string into a list
        s_list = re.findall(regex_expression, s)
        
        # Loops through the list
        for i in range(len(s_list)):

            if s_list[i] == '(':
                operators.append('(')
            
            # If the character is not a number then create a root with no children and add it to the tree stack
            elif not self.IsOperator(s_list[i]):
                node = Node(s_list[i])
                tree.append(node)
            
            # Filters out parentheses 
            elif priority[s_list[i]] > 0:
                # While the operators stack is not empty and the priority of the top operator is greater than the priority of the current operator
                while len(operators) > 0 and operators[-1] != '(' and priority[operators[-1]] >= priority[s_list[i]]:
                    # Creates and combines nodes to begin building the tree
                    self.makeNode(operators, tree)
                # Adds the current operator to the top of the stack    
                operators.append(s_list[i])
            # Handles parentheses
            elif s_list[i] == ')':
                while len(operators) != 0 and operators[-1] != '(':
                    self.makeNode(operators, tree)
                    
                operators.pop()

        # Combines any remaining nodes
        while len(tree) > 1:
            self.makeNode(operators, tree)
        
        return tree[-1]

    # Traverses the tree and returns the infix expression
    def Infix(self, tree, arr):
        if tree != None:                   
                        
            if self.IsOperator(tree.data):
                arr.append('(')
            
            self.Infix(tree.left, arr)
            arr.append(tree.data)
            self.Infix(tree.right, arr)

            if self.IsOperator(tree.data):
                arr.append(')')
    
    def Preorder(self, tree, arr):
        if tree != None:
            arr.append(tree.data),
            self.Preorder(tree.left, arr)
            self.Preorder(tree.right, arr)

    def Postorder(self, tree, arr):
        
        if tree != None:
            
            self.Postorder(tree.left, arr)
            self.Postorder(tree.right, arr)
            arr.append(tree.data)
        

    # Testing purposes
    def printTree(self, node, level=0):
        if node != None:
            self.printTree(node.left, level + 1)
            
            print(str(level) + "->" + str(node.data))
            self.printTree(node.right, level + 1)

# Turns an infix expression into postfix
class InfixToPostfix:
    def __init__(self):
        # Operator stack
        self.operator = []
         
        # Output stack
        self.output = [] 
        # Precedence setting
        self.precedence = {'(': 0, '+': 1, '-': 1, '*': 2, '/': 2} 

        self.regex_expression = "[\/\+\-\*\(\)]|[0-9][0-9][0-9]|[0-9][0-9]|[0-9]"
 
    def isOperator(self, s):
        if '+' in s:
            return True
        if '-' in s:
            return True
        if '*' in s:
            return True
        if '/' in s:
            return True
        if '(' in s:
            return True
        if ')' in s:
            return True
        return False
 
    # The main function that
    # converts given infix expression
    # to postfix expression
    def infixToPostfix(self, exp):
        exp_list = re.findall(self.regex_expression, exp)
        # Iterate over the expression for conversion
        for i in exp_list:
             
            # If the character is an operand,
            # add it to output
            if not self.isOperator(i):
                self.output.append(i)

            # If the scanned character is an ')', pop and
            # output from the stack until and '(' is found
            elif i == ')':
                while len(self.operator) > 0 and self.operator[-1] != '(':
                    a = self.operator.pop()
                    self.output.append(a)

                self.operator.pop()
                    
            # An operator is encountered
            else:
                # Skip if the operator is a (
                if i != '(':
                    # Pop off operator stack while it's not empty and the precedence of the top of the stack is greater than the current operator precedence
                    while (len(self.operator) > 0) and (self.precedence[self.operator[-1]] >= self.precedence[i]):
                        self.output.append(self.operator.pop())
                    self.operator.append(i)
                else:
                    self.operator.append(i)
 
        # Pop all the operator from the stack
        while len(self.operator) > 0:
            self.output.append(self.operator.pop())

        # Returns final expression
        return ''.join(self.output)

# Turns an infix expression to prefix
class InfixToPrefix:
    # Initialize variables
    def __init__(self):
        self.toPost = InfixToPostfix()
        self.regex_expression = "[\/\+\-\*\(\)]|[0-9][0-9][0-9]|[0-9][0-9]|[0-9]"
    # Switches open paren with closed paren and vice versa
    def openToClose(self, exp):
        c = 0
        for i in exp:
            if i == '(':
                exp[c] = ')'
            elif i == ')':
                exp[c] = '('
            c += 1
        return exp

    # Reverses the expression, finds its postfix, then reverses the postfix to get prefix
    def infixToPrefix(self, exp):  
        exp = re.findall(self.regex_expression, exp[::-1])
        exp = self.openToClose(exp)
        exp = self.toPost.infixToPostfix(str(exp))

        return exp[::-1]




postfixCon = InfixToPostfix()
prefixCon = InfixToPrefix()
infixExpressionTree = InfixExpressionTree()

s = '5+4/5*9+(4-3)'
InfixArr = []
PostfixArr = []
PrefixArr = []

my_tree = infixExpressionTree.binaryExpressionTree(s)

infixExpressionTree.Infix(my_tree, InfixArr)
infixExpressionTree.Postorder(my_tree, PostfixArr)
infixExpressionTree.Preorder(my_tree, PrefixArr)

infix = ''.join(InfixArr[1:-1])
postfix = ''.join(PostfixArr)
prefix = ''.join(PrefixArr)

print("\nInfix: " + infix)
print("\nPostfix (Nontraversal): " + postfixCon.infixToPostfix(infix))
print("Postfix (Traversal): " + postfix)

print("\nPrefix (Nontraversal): " + prefixCon.infixToPrefix(infix))
print("Prefix (Traversal): " + prefix)
