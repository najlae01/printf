# _printf

_printf project is about building a function as similar as possible to the original function present in the standard library of programming language C, this is a challenge of some difficulty since the original function behaves in very specific ways in certain cases.

This project was built by [Niama SKAY](https://github.com/Niamask) and [Najlae Abarghache](https://github.com/najlae01).

# Features
- The main function uses structures to call the function corresponding to the case, this allows greater code scalability.
- As in the original printf, the function has a buffer that stores and prints the output strings every 1024 bytes.
- Just like the original printf, the returns of our function are the number of characters printed, when the input is incorrect the return is error -1

# How Use
## How to compile
### Requirements
compile on Ubuntu 14.04 LTS
compile with gcc 4.8.4

### Flags to compile
$ gcc -Wall -Werror -Wextra -pedantic *.c

# Tasks required for this project
### 0. I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life
Write a function that produces output according to a format. Handle the following conversion specifiers:
- c
- s
- %

### 1. Education is when you read the fine print. Experience is what you get if you don't
Handle the following conversion specifiers:
- d
- i

### 2. With a face like mine, I do better in print
Handle the following conversion specifiers:
- b

### 3. What one has not experienced, one will never understand in print
Handle the following conversion specifiers:
- u
- x
- o
- x
- X

### 4. Nothing in fine print is ever good news
Use a local buffer of 1024 chars in order to call write as little as possible.

### 5. My weakness is wearing too much leopard print
Handle the following custom conversion specifier
- S : prints the string.
- Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters).

### 6. How is the world ruled and led to war? Diplomats lie to journalists and believe these lies when they see them in print
Handle the following conversion specifier: p

### 7. The big print gives and the small print takes away
Handle the following flag characters for non-custom conversion specifiers:

- ´+´
- space
- ´#´

### 8. Sarcasm is lost in print
Handle the following length modifiers for non-custom conversion specifiers:

- l
- h Conversion specifiers to handle: d, i, u, o, x, X

### 9. Print some money and give it to us for the rain forests
Handle the field width for non-custom conversion specifiers.

### 10. The negative is the equivalent of the composer's score, and the print the performance
Handle the precision for non-custom conversion specifiers.

### 11. It's depressing when you're still around and your albums are out of print
Handle the 0 flag character for non-custom conversion specifiers.

### 12. Every time that I wanted to give up, if I saw an interesting textile, print what ever, suddenly I would see a collection
Handle the - flag character for non-custom conversion specifiers.

### 13. Print is the sharpest and the strongest weapon of our party
Handle the following custom conversion specifier:

- r : prints the reversed string

### 14. The flood of print has turned reading into a process of gulping rather than savoring
Handle the following custom conversion specifier:

- R: prints the rot13'ed string
### 15. *
All the above options work well together.

# Authors 
- Niama SKAY
- Najlae Abarghache
