*This project has been created as part of the 42 curriculum by <sdubuiss>.*

# Libft
## Description

Libft is an individual project from the 42 curriculum.

The goal of this project is to create a personal C library by reimplementing standard C library functions and developing additional utility functions.

This project helps develop a deeper understanding of the C language, pointers, memory allocation, strings, and linked lists.

The resulting library is compiled into a static library named libft.a, which can be reused in future C projects.

Features

The library is organized into several categories:

Character checks and conversions.
String manipulation.
Memory management.
String and integer conversions.
Output functions.
Additional utility functions.
Singly linked list manipulation.
Detailed Library Description
1. Character Functions

ft_isalpha

Checks whether a character is alphabetic.

ft_isdigit

Checks whether a character is a decimal digit.

ft_isalnum

Checks whether a character is alphabetic or numeric.

ft_isascii

Checks whether a value belongs to the ASCII range.

ft_isprint

Checks whether a character is printable.

ft_toupper

Converts a lowercase letter to uppercase.

ft_tolower

Converts an uppercase letter to lowercase.

2. String Functions

ft_strlen

Calculates the length of a string.

ft_strchr

Searches for the first occurrence of a character in a string.

ft_strrchr

Searches for the last occurrence of a character in a string.

ft_strncmp

Compares two strings up to a specified number of characters.

ft_strlcpy

Copies a string into a destination while respecting the destination size.

ft_strlcat

Concatenates strings while respecting the destination size.

ft_strnstr

Searches for a substring within a specified length.

ft_strdup

Duplicates a string using dynamic memory allocation.

ft_substr

Creates a substring from a given string.

ft_strjoin

Concatenates two strings into a newly allocated string.

ft_strtrim

Removes specified characters from the beginning and end of a string.

ft_split

Splits a string into an array of strings using a delimiter.

ft_strmapi

Creates a new string by applying a function to each character.

ft_striteri

Applies a function to each character of a string.

3. Memory Functions

ft_memset

Fills a memory area with a specified byte.

ft_bzero

Sets a memory area to zero.

ft_memcpy

Copies bytes between non-overlapping memory areas.

ft_memmove

Copies bytes safely when memory areas overlap.

ft_memchr

Searches for a byte in a memory area.

ft_memcmp

Compares two memory areas.

ft_calloc

Allocates memory and initializes it to zero.

4. Conversion Functions

ft_atoi

Converts a string into an integer.

ft_itoa

Converts an integer into a newly allocated string.

5. Output Functions

ft_putchar_fd

Writes a character to a specified file descriptor.

ft_putstr_fd

Writes a string to a specified file descriptor.

ft_putendl_fd

Writes a string followed by a newline to a specified file descriptor.

ft_putnbr_fd

Writes an integer to a specified file descriptor.

6. Additional Utility Functions

ft_substr

Extracts a substring from a string.

ft_strjoin

Creates a new string by concatenating two strings.

ft_strtrim

Removes specified characters from both ends of a string.

ft_split

Splits a string into an array of strings.

ft_itoa

Converts an integer into a string.

These functions provide reusable tools for string processing and data manipulation.

7. Linked List Functions

The linked list functions operate on a singly linked list defined by the t_list structure in libft.h.

Each node contains a pointer to its content and a pointer to the next node.

c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;


ft_lstnew

Allocates and initializes a new list node.

ft_lstadd_front

Adds a node at the beginning of a list.

ft_lstsize

Counts and returns the number of nodes in a list.

ft_lstlast

Returns the last node of a list.

ft_lstadd_back

Adds a node at the end of a list.

ft_lstdelone

Deletes one node by applying a supplied deletion function to its content and freeing the node.

ft_lstclear

Deletes all nodes in a list and sets the list pointer to NULL.

ft_lstiter

Applies a function to the content of every node in a list.

ft_lstmap

Creates a new list by applying a function to each node's content.

These functions provide practice with pointers, structures, function pointers, dynamic memory allocation, and memory management.


## Instructions
Requirements

To compile the library, you need:

A C compiler, such as cc or gcc.
make.
The standard C library and development headers.
Compilation

Clone the repository and enter the project directory.

bash
git clone <repository-url>
cd libft


Compile the library.

bash
make


This should generate the static library libft.a, provided the Makefile is configured accordingly.

Cleaning

Remove object files.

bash
make clean


Remove object files and the compiled library.

bash
make fclean


Rebuild the project from scratch.

bash
make re

Using the Library

Include the library header in your C source file.

c
#include "libft.h"


Compile your program with the library.

bash
cc -Wall -Wextra -Werror -I. main.c -L. -lft -o program


Run the executable.

bash
./program

Testing

A dedicated test file can be used to check the behavior of the library functions.

For example, compile the linked list tests with the library and the required test helper functions.

bash
cc -Wall -Wextra -Werror -I. test_lst.c -L. -lft -o test_lst


Run the tests.

bash
./test_lst


If test.h contains helper functions such as print_section and print_result, their implementations must also be linked during compilation.

Project Structure

The repository may contain the following files, depending on the project organization.

text
libft/
├── Makefile
├── libft.h
├── ft_*.c
└── README.md


libft.h

Contains function prototypes and the linked list structure.

ft_*.c

Contains the implementations of the library functions.

Makefile

Compiles the source files into the static library.



README.md

Documents the project, its functions, and its compilation instructions.

## Resources

The following resources are useful for learning C, understanding standard library behavior, and managing memory.

C reference: https://en.cppreference.com/w/c
Linux manual pages: https://www.man7.org/linux/man-pages/
GCC documentation: https://gcc.gnu.org/onlinedocs/
GNU Make manual: https://www.gnu.org/software/make/manual/
POSIX specifications: https://pubs.opengroup.org/onlinepubs/9699919799/
The official Libft project subject provided by 42.
Use of AI

AI tools were used as supplementary assistance during the development of this project.

They were used to explain C functions, pointers, linked lists, function pointers, and dynamic memory management.

AI assistance was also used to suggest test cases for linked list functions, including ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back, ft_lstdelone, ft_lstclear, ft_lstiter, and ft_lstmap.

Additional assistance was used to organize test code, identify duplicate function definitions, explain memory management issues, and prepare this README.

The generated suggestions were reviewed and adapted during development. The developer remains responsible for understanding, testing, and validating the final implementation.

