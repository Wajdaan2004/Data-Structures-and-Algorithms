from stack import Stack

# Constants
OPERATORS = "+-*/"
# Imports
from enum import Enum

# Enumerated constant
MIRRORED = Enum('MIRRORED',
                {'IS_MIRRORED': "is a mirror", 'TOO_MANY_LEFT': "too many characters in L",
                 'TOO_MANY_RIGHT': "too many characters in R", 'MISMATCHED': "L and R don't match",
                 'INVALID_CHAR': "invalid character", 'NOT_MIRRORED': "no mirror character"})



def stack_split_alt(source):
    """
    -------------------------------------------------------
    Splits the source stack into separate target stacks.
    When finished source stack is empty. Values are
    pushed alternately onto the returned target stacks.
    Use: target1, target2 = stack_split_alt(source)
    -------------------------------------------------------
    Parameters:
        source - the stack to split into two parts (Stack)
    Returns:
        target1 - contains alternating values from source (Stack)
        target2 - contains other alternating values from source (Stack)
    -------------------------------------------------------
    """
    target1 = Stack()
    target2 = Stack()
    x = True
    for i in source:
        if x:
            target1.push(source.pop())
            x = False
        else:
            target2.push(source.pop())
            x = True
            
    return target1, target2



def is_palindrome_stack(string):
    """
    -------------------------------------------------------
    Determines if string is a palindrome. Ignores case, digits, spaces, and
    punctuation in string.
    Use: palindrome = is_palindrome_stack(string)
    -------------------------------------------------------
    Parameters:
        string - a string (str)
    Returns:
        palindrome - True if string is a palindrome, False otherwise (bool)
    -------------------------------------------------------
    """
    palin = ''
    stack = Stack()
    letters = ''
    
    for i in string:
        if i.isalpha():
            letters += i.lower()
        
    for i in letters:
        stack.push(i)
        
    for i in letters:
        palin += str(stack.pop())
        
    if palin.lower() == letters.lower():
        palindrome = True 
    else:
        palindrome = False
        
    return palindrome
        
        
def postfix(string):
    """
    -------------------------------------------------------
    Evaluates a postfix expression.
    Use: answer = postfix(string)
    -------------------------------------------------------
    Parameters:
        string - the postfix string to evaluate (str)
    Returns:
        answer - the result of evaluating string (float)
    -------------------------------------------------------
    """
    stack = Stack()
    for i in string.split():
        if i.isdigit():
            stack.push(float(i))
        elif i in OPERATORS:
            j = stack.pop()
            k = stack.pop()
            if i == "+":
                a = k + j
            elif i == "-":
                a = k - j
            elif i == "*":
                a = k * j
            elif i == "/":
                a = k / j
            stack.push(a)
    answer = stack.pop()
    return answer


def stack_maze(maze):
    """
    -------------------------------------------------------
    Solves a maze using Depth-First search.
    Use: path = stack_maze(maze)
    -------------------------------------------------------
    Parameters:
        maze - dictionary of points in a maze, where each point
            represents a corridor end or a branch. Dictionary
            keys are the name of the point followed by a list of
            branches, if any. First point is named 'Start', exit
            is named 'X' (dict)
    Returns:
        path - list of points visited before the exit is reached,
            None if there is no exit (list of str)
    -------------------------------------------------------
    """
    stack = Stack()
    path = []
    end = {}
    key = "Start"

    stack.push(key)
    end[key] = []
    while not stack.is_empty():
        current = stack.pop()
        path.append(current)
        if current == "X":
            return path
        for i in maze.get(current, []):
            if i not in end:
                stack.push(i)
                end[i] = path
                
    return path
        
        
        
        
def is_mirror_stack(string, valid_chars, m):
    """
    -------------------------------------------------------
    Determines if string is a mirror of characters in valid_chars around the pivot m.
    A mirror is of the form LmR, where L is the reverse of R, and L and R
    contain only characters in valid_chars.
    Use: mirror = is_mirror_stack(string, valid_chars, m)
    -------------------------------------------------------
    Parameters:
        string - a string (str)
        valid_chars - a string of valid characters (str)
        m - the mirror pivot string (str - one character not in valid_chars)
    Returns:
        mirror - the state of the string (Enum MIRRORED)
    -------------------------------------------------------
    """
    if m in valid_chars or m not in string:

        return MIRRORED.NOT_MIRRORED

    mirroring = False

    arr = []

    for i in string:
        if i not in valid_chars and i != m:
            return MIRRORED.INVALID_CHAR
        
        elif i != m and not mirroring:
            arr.append(i)
            
        elif i == m:
            mirroring = True
            
            if len(arr) < (len(string) - (len(arr)+1)):
                return MIRRORED.TOO_MANY_RIGHT
            
            elif len(arr) > (len(string) - (len(arr)+1)):
                return MIRRORED.TOO_MANY_LEFT
        else:
            if i != arr.pop():
                return MIRRORED.MISMATCHED
    assert m not in valid_chars and m != '{}'
    
    return MIRRORED.IS_MIRRORED