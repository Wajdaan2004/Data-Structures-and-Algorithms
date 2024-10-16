from stack import Stack
from functions import stack_split_alt, is_palindrome_stack, postfix, stack_maze, is_mirror_stack

# Create a stack object
stack = Stack()

# Test for is_empty method
print("Test is_empty:")
print(stack.is_empty())  # Should return True since the stack is empty
stack.push(10)
print(stack.is_empty())  # Should return False after pushing an element

# Test for push method
print("\nTest push:")
stack.push(20)
print(stack.peek())  # Should show 20 as the top of the stack

# Test for pop method
print("\nTest pop:")
print(stack.pop())  # Should return 20, the last pushed item
print(stack.pop())  # Should return 10, the remaining item
# Uncomment the following line to test pop on an empty stack (it should raise an exception)
# print(stack.pop())  # Should raise an assertion error because the stack is empty

# Test for peek method
print("\nTest peek:")
stack.push(30)
print(stack.peek())  # Should return 30, the top element

# Test for split_alt method
print("\nTest split_alt:")
stack.push(40)
stack.push(50)
stack.push(60)
target1, target2 = stack.split_alt()
print([v for v in target1])  # Should print alternating values like [60, 40]
print([v for v in target2])  # Should print [50]

# Test for iterating through the stack (via __iter__)
print("\nTest __iter__:")  # Iterating through the stack
stack.push(70)
print([v for v in stack])  # Should print stack from top to bottom: [70, 60, 50, 40, 30]

# Test for split_alt with empty stack
print("\nTest split_alt with empty stack:")
empty_stack = Stack()
target1, target2 = empty_stack.split_alt()
print([v for v in target1])  # Should print empty list []
print([v for v in target2])  # Should print empty list []

# Test stack_split_alt (from functions module)
print("\nTest stack_split_alt:")
s = Stack()
s.push(8)
s.push(14)
s.push(12)
s.push(9)
s.push(8)
s.push(7)
s.push(5)
target1, target2 = stack_split_alt(s)  # This should work as expected with stack_split_alt
print([v for v in target1])  # Should print alternating values in one stack
print([v for v in target2])  # Should print alternating values in the other stack

# Test is_palindrome_stack
print("\nTest is_palindrome_stack:")
palindrome = is_palindrome_stack('A man, a plan, a canal, Panama')  # Should return True
print(palindrome)
non_palindrome = is_palindrome_stack('Not a palindrome')  # Should return False
print(non_palindrome)

# Test postfix
print("\nTest postfix:")
answer = postfix('4 5 + 12 * 2 3 * -')  # Should return 2.0
print(answer)

# Test stack_maze
print("\nTest stack_maze:")
maze = {'Start': ['A'], 'A':['B', 'C'], 'B':[], 'C':['D', 'E'],
        'D':[], 'E':['F', 'X'], 'F':['G', 'H'], 'G':[], 'H':[]}
path = stack_maze(maze)  # Should return a path like ['Start', 'A', 'C', 'E', 'X']
print(path)

# Test is_mirror_stack
print("\nTest is_mirror_stack:")
mirror = is_mirror_stack("cmc", "abc", "m")  # Should return MIRRORED.IS_MIRRORED
print(mirror)
mirror_invalid = is_mirror_stack("cmc", "abc", "x")  # Should return MIRRORED.NOT_MIRRORED
print(mirror_invalid)
