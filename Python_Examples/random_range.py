# Generate random numbers from interval [3, 7)]

import random

def range_random():
    # Random, scale, shift, return...
    return 4*random.random() + 3

for i in range(10):
    print(range_random())
