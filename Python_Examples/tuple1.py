# list example
prime_numbers = [2, 3, 5, 7, 11, 13, 17]

# Tuple exampole
perfect_squares = (1, 4, 9, 16, 25, 26)

# Display lengths
print("# Primes = ", len(prime_numbers))
print("# Squares = ", len(perfect_squares))

#Iterate over both sequences
for p in prime_numbers:
    print("Prime: ", p)
for n in perfect_squares:
    print("Square: ", n)

print("List methods")
print(dir(prime_numbers))
print(80*"-")
print("Tuple methods")
print(dir(perfect_squares))
