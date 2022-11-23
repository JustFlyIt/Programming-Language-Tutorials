# Generate random numbers from interval [3, 7)

import random

def my_random():
    # Random, scale, shift, return...
    return 4*random.random() + 3

for i in range(10):
    print(my_random())
