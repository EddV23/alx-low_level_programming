#!/usr/bin/python3
"""
finds largest palindrome made from the product of two 3-digit
numbers and saves the result in the file 102-result
"""


def is_palindrome(n):
    return str(n) == str(n)[::-1]

largest_palindrome = 0

for i in range(100, 1000):
    for j in range(100, 1000):
        product = i * j
        if is_palindrome(product) and product > largest_palindrome:
            largest_palindrome = product

with open('102-result', 'w') as f:
    f.write(str(largest_palindrome))
    """print(f"{largest_palindrome}", end="")"""
    print("{}".format(largest_palindrome), end="")
