##Stack Applications: Polish Notation

# Expression:
It is sequence of operators and operands that reduces to a single
value after evaluation is called an expression.

# Expression can be represented in different format such as
> Prefix expression or Polish notation</br>
> Infix Expression</br>
> Postfix Expression or Reverse Polish notation

# InFix Expression:
In this exp, the binary operator is placed in between the
operand. The exp can be parethesized on unparenthesized.

Ex: A + B, A and B are operands and + is operator.

# Prefix or Polish Expression:
In this expression, the operator append before
it's operand.

Example: +AB

# Postfix or Reverse Polish Expression:
In the expression, the operator appears after the operand.

Example: AB+

# Precedence of an Operator:
	Image 1

# INFIX TO POSTFIX CONVERSION

An algorithm to convert infix to postfix expression as follows:

1. Fully Parenthesize the expression.
2. Move all binary operators so that they replace their corresponding right
   parentheses.
3. Delete all parentheses.

Ex:
=> ((((a/b) - c) + (d+c) - a * c))</br>
=> ab/c - de* + ac*</br>


-> (4/2)-((2+3) * 3 - 4) * 2
-> 2 - ((5) * 3 - 4) * 2
-> 2 - (15 - 4) * 2
-> 2 - 11 * 2
-> 2 - 22
-> -20


* Using Stacks:

	 * Operator insert to stack.
	 * char pop to output.
	 * ( = push to stack.
	 * ) = pop entire stack.
	 * When reaches end of string pop whole stack.

ex:
   Q. a * (b + c) * d</br>

Q.
1. (a + b) * (c - d) + (e - (x + y))
2. ((x * y) - ( p / q )) - a + b


