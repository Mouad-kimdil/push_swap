# push_swap

## School: 1337 Coding School

## Project Information

In the "push_swap" project, you will delve into the world of sorting algorithms, mastering the art of efficiently sorting values using two stacks, namely stack A and stack B. Your goal is to sort the values in stack A using stack B and a set of instructions in the fewest moves possible.

## Usage

Git clone the repository and cd into it. Then use ```make``` to compile.

Then run it with :

```shell
./push_swap <numbers>
```

The numbers provided can be positive or negative integers. There must not be any duplicates. For example :

```shell
./push_swap 9 0 -217 2147483647 -2147483648
```

If the arguments are valid, the program will output the most efficient list of actions to sort the list.

The program can be checked with the provided checker, like this :

```shell
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG
```

## Push_Swap Rules and Grading

The program operates with two stacks, A and B. The following actions are allowed:

pa (push A): Push the top element of B onto A (if B is not empty).

pb (push B): Push the top element of A onto B (if A is not empty).

sa (swap A): Swap the top 2 elements of A (if there are at least two elements).

sb (swap B): Swap the top 2 elements of B (if there are at least two elements).

ss: Perform sa and sb simultaneously.

ra (rotate A): Shift all elements of A up by 1, with the first element becoming the last.

rb (rotate B): Shift all elements of B up by 1, with the first element becoming the last.

rr: Perform ra and rb simultaneously.

rra (reverse rotate A): Shift all elements of A down by 1, with the last element becoming the first.

rrb (reverse rotate B): Shift all elements of B down by 1, with the last element becoming the first.

rrr: Perform rra and rrb simultaneously.

Grading is based on the efficiency of the sorting process:

Sorting 3 values: No more than 3 actions.

Sorting 5 values: No more than 12 actions.

Sorting 100 values: Rated from 1 to 5 points based on the number of actions:

5 points for less than 700 actions

4 points for less than 900

3 points for less than 1100

2 points for less than 1300

1 point for less than 1500

Sorting 500 values: Rated from 1 to 5 points based on the number of actions:

5 points for less than 5500 actions

4 points for less than 7000

3 points for less than 8500

2 points for less than 10000

1 point for less than 11500

## BONUS PART

