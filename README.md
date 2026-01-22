# push_swap

`push_swap` is a program that sorts a list of integers using two stacks and a limited set of operations.  
The objective is to sort the numbers and optimize the move count that outputs to `stdout`.

## Installation and Usage

To use push_swap clone the git repository and `cd` into the push_swap folder.
Run `make` to compile all the files and execute `./push_swap`.

exemple:

```bash
./push_swap -12 45 2 8 5
```

#### Output:

```bash
pb
ra
pb
ra
ra
ra
sa
pa
pa
```

In adition to this, 42 has provided a `checker_OS` to test and validate the project, it works by having the moves from push_swap piped to itself and the same argument as push_swap, if it sorts correctly then it prints `OK` otherwise it prints `KO`.

```bash
./push_swap -12 45 2 8 5 | ./checker_OS -12 45 2 8 5
```

#### Output:

```bash
OK
```

## Project Overview

The program receives integers as arguments, stores them in **stack A**, and uses **stack B** as an auxiliary structure to sort them using only predefined stack operations.


| Operation | Description |
|----------|-------------|
| `sa` | Swap top 2 elements of stack A |
| `sb` | Swap top 2 elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of B onto A |
| `pb` | Push top of A onto B |
| `ra` | Rotate A (top becomes bottom) |
| `rb` | Rotate B (top becomes bottom) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A (bottom becomes top) |
| `rrb` | Reverse rotate B (bottom becomes top) |
| `rrr` | `rra` and `rrb` simultaneously |

## Input Handling

When **push_swap** is run, before it can do anything it needs to parse its arguments, so that no undesired elements enter the program, for that `ft_parser` is used split the arguments, if needed, and to transform them with `ft_atol` from `char *` (string) to `int`, furthermore the program checks if the arguments are only consisting of **integers**, being those integers in the limits of `INT_MIN` to `INT_MAX` and if there are no duplicate numbers.

```c
tmp = ft_atol(nums[j]);
if (tmp < INT_MIN || tmp > INT_MAX)
	send_error();
if (ft_double_check(nums))
	send_error();
if (!ft_check_num(nums[j]))
	send_error();
```

If any of these fail then the function `send_error` is called that prints "***Error***" to `stderr` and calls `exit` to stop the program.

```c
void	send_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
```

### Valid examples:

```bash
./push_swap 2 1 3
./push_swap "4 67 3 1"
```

### Invalid examples:

```bash
./push_swap 1 2 a
./push_swap 3 3
./push_swap 2147483648
./push_swap " "
./push_swap
```

## Sorting algorithm

For this project, it was chosen the **Radix Sort**, but for smaller number of arguments simpler hardcoded sorts were made.

| Size | Strategy |
|------|----------|
| `<= 3` | Simple swaps/rotations |
| `<= 5` | Push smallest values, sort, push back |
| `> 5` | **Radix Sort** |

### Indexing

For **Radix** to work its needed to **index** the integers, because **Radix** sorts the numbers with their binary value, since negative numbers are very hard to work with in binary needing an extra bit to work, **indexes** are basically required:

| Number | Index |
|--------|-------|
| **42** | `2` |
| **-3** | `0` |
| **1** | `1` |
| **3452** | `3` |


### Radix Sort

For easier sorting a struct is used, it's format uses two integers to track the value and index for each node in the stack, and a pointer to the next node in the stack.

```c
typedef struct s_stack {
    int				value;
    int				index;
    struct s_stack	*next;
}	t_stack;
```

With each node **indexed**, **Radix** goes through every node's **index** and searches the fardest bit to the right, **Least Significant Bit** (`LSB`), and compares it with `1`, then compares the second bit from the right and repeats until it goes through every bit in every node, once its done then the stack will be sorted.

```c
if ((*stack_a)->index >> i & 1)
	ra(stack_a);
else
	pb(stack_a, stack_b);
```

- If bit is `1` = rotate A (`ra`)
- If bit is `0` = push to B (`pb`)

Then push everything back to A.

```bash
  ⌄
100          |                |   100
000          |                |   000 
110          |                |   110
001          |          010   |   010
101          |   001    110   |   001
010          |   101    000   |   101
011          |   011    100   |   011
----   ----  |   ----   ----  |   ----   ----
a      b     |   a      b     |   a      b
```
We move over one bit and repeat this process.

```bash
 ⌄
100          |                |   100
000          |                |   000 
110          |                |   001
010          |          101   |   101
001          |   010    001   |   010
101          |   110    000   |   110
011          |   011    100   |   011
----   ----  |   ----   ----  |   ----   ----
a      b     |   a      b     |   a      b
```

We repeat one last time for the last available digit.

```bash
⌄
100          |                |   000
000          |                |   001 
001          |                |   010
101          |          011   |   011
010          |   100    010   |   100
110          |   101    001   |   101
011          |   110    000   |   110
----   ----  |   ----   ----  |   ----   ----
a      b     |   a      b     |   a      b
```

The list is now completely sorted.

But for **Radix** to know how many bits to go through (`max_bits`) it needs to find the max amount of bits needed to write the biggest index.
- **7** -> `01111` -> needs 4 bits to write
- **8** -> `10000` -> needs 5 bits to write

```c
int	ft_max_bits(int biggest_index)
{
	int	max_bits;

	max_bits = 0;
	while (biggest_index > 0)
	{
		biggest_index >>= 1;
		max_bits++;
	}
	return (max_bits);
}
```

## Visualization

Here we have 2 visualizations using `push_swap_visualizer`, this tool ofers the ability to visualize any sorting algorithm in push_swap with any amount of numbers.

#### Sorting 100 numbers:

![Visualizer](https://imgur.com/oqhxixd.gif)

#### Sorting 500 numbers:

![Visualizer](https://imgur.com/Pb1KbxG.gif)

## Sources

- [Radix sort](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
- [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
- [Bitwise operators](https://www.programiz.com/c-programming/bitwise-operators)
