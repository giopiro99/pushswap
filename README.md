# pushswap
Push_swap is a sorting algorithm project where you must sort a stack of integers using a limited set of operations with the goal of minimizing the number of moves.
--------------------------------------------------
push_swap is a sorting algorithm project developed in C that aims to sort data on a stack with a limited set of operations. The goal is to sort a list of integers using two stacks (A and B) and a minimal number of moves.

## Features

- Efficient sorting of integers using stack operations:
  - `sa`, `sb`, `ss` (swap)
  - `pa`, `pb` (push)
  - `ra`, `rb`, `rr` (rotate)
  - `rra`, `rrb`, `rrr` (reverse rotate)
- Handles both small and large sets of numbers with optimized strategies
- Includes a separate checker program that verifies if the given operations correctly sort the stack
- Proper error handling for invalid input and duplicates

## How to use

1. Compile the project with:

```bash
  make
Run push_swap with a list of integers:

bash
Copy
Edit
./push_swap 3 2 5 1 4
Run the checker to validate operations:

bash
Copy
Edit
./checker 3 2 5 1 4
You can then input the operations manually or pipe the output of push_swap to checker:

bash
Copy
Edit
./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4
Objective
The main objective is to produce the shortest possible sequence of operations to sort the stack efficiently.Run push_swap with a list of integers:

bash
Copy
Edit
./push_swap 3 2 5 1 4
Run the checker to validate operations:

bash
Copy
Edit
./checker 3 2 5 1 4
You can then input the operations manually or pipe the output of push_swap to checker:

bash
Copy
Edit
./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4
Objective
The main objective is to produce the shortest possible sequence of operations to sort the stack efficiently.

