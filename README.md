# 🔄 Push_swap

**Push_swap** is a highly efficient sorting algorithm project developed in C. The goal is to sort a stack of integers using two stacks (`A` and `B`) and a limited set of operations, optimizing for the lowest possible number of moves.

## 📖 Overview

The project consists of two executable programs:
1.  **`push_swap`**: Calculates and outputs the smallest sequence of operations instructions to sort the integer arguments.
2.  **`checker`**: Takes the integers and the operations (read from standard input) and verifies if the stack is correctly sorted.

## 🏗️ Architecture & Algorithm

This implementation moves beyond brute force by utilizing a **Chunking Algorithm** combined with normalized indexing.

### 1. Parsing & Indexing
* **Validation:** The program parses input arguments, checking for integer limits, syntax errors, and duplicates.
* **Normalization:** Instead of sorting the actual values, the algorithm maps each number to its "rank" (index) in the sorted list (0 to N-1). This allows the algorithm to work with predictable ranges regardless of the input values.

### 2. The Sorting Strategy
The sorting logic adapts based on the input size:
* **Small Stacks (≤ 3):** An optimized, hardcoded function (`sort_three`) sorts these instantly.
* **Large Stacks (Chunking):**
    1.  **Chunk Assignment:** The stack is divided into dynamic chunks based on the indices (e.g., chunk size 20 for ≤100 numbers, 39 for larger sets).
    2.  **Push to B:** Elements are moved from Stack A to Stack B chunk by chunk.
        * If an element belongs to the current chunk, it is pushed (`pb`).
        * Optimization: If the element is in the lower half of the chunk, Stack B is rotated (`rb`) to pre-sort it.
    3.  **Push back to A:** Once Stack A is empty (except for the last 3), the algorithm sorts the remaining 3 and then pushes elements back from B to A. It does this by repeatedly finding the maximum value in B, moving it to the top efficiently, and pushing it to A (`pa`).

## 🛠️ Instruction Set

The only allowed moves to manipulate the stacks are:

| Command | Description |
| :--- | :--- |
| **sa** | Swap the first 2 elements at the top of stack A. |
| **sb** | Swap the first 2 elements at the top of stack B. |
| **ss** | `sa` and `sb` at the same time. |
| **pa** | Push the top element of B to the top of A. |
| **pb** | Push the top element of A to the top of B. |
| **ra** | Rotate A (first element becomes the last). |
| **rb** | Rotate B (first element becomes the last). |
| **rr** | `ra` and `rb` at the same time. |
| **rra** | Reverse rotate A (last element becomes the first). |
| **rrb** | Reverse rotate B (last element becomes the first). |
| **rrr** | `rra` and `rrb` at the same time. |

## 🚀 Installation & Usage

### Compilation
The project uses a `Makefile` to compile the source code and the custom `libft` library.

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/your-username/push_swap.git](https://github.com/your-username/push_swap.git)
    cd push_swap
    ```

2.  **Compile the main program:**
    ```bash
    make
    ```
    This generates the `push_swap` executable.

3.  **Compile the bonus (checker):**
    ```bash
    make bonus
    ```
    This generates the `checker` executable.

### Running push_swap
Run the program with a list of integers as arguments:

```bash
./push_swap 2 1 3 6 5 8
