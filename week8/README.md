# Week 8 - Optimisations

>Choose a small algorithm to implement in different ways. Describe when/why you might use
>each. You can choose any small algorithm.
>

The algorithm chosen is "find the first 100 prime numbers". The source code in this repo 
implements 3 versions, one which uses less RAM and code space but trades this for processor cycles. 
The other two trade processor cycles for less RAM and code space.

The outputs of all three functions:

<img src="images/output.png">

In godbolt.org, they appear like so ([link](https://godbolt.org/z/9sn4KqfGx)):

Algorithm 1:
31 assembly lines

Algorithm 2:
20 assembly instructions

Algorithm 3:
9 assembly instructions
