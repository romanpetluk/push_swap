# push_swap

Project in 42 School.

Main goal of this project is to sort numbers using 2 stacks and specific operations.

There are two programs

Push Swap - takes integer numbers in arguments and generates operations to sort them using two stacks named 'a', 'b' respectively. At the start all integers passed as arguments is written in stack 'a'.

Checker - takes commands generated by push_swap into stdin, numbers to apply this operations on in arguments, and checks if this commands will sort this numbers. If yes - displays OK, if no - displays KO. In case of error - displays Error.

### Commands to operate stacks:

* pa - push from 'a' to 'b'
* pb - push from 'b' to 'a'
* sa - swap top 2 elements in 'a'
* sb - swap top 2 elements in 'b'
* ss - swap top 2 elements in both stacks
* ra - rotates stack 'a' (the first element becomes the last one)
* rb - rotates stack 'b'
* rr - rotates both stacks
* rra - reverse rotates stack 'a' (the last element becomes the first one)
* rrb - reverse rotates stack 'b'
* rrr - reverse rotates both stacks
