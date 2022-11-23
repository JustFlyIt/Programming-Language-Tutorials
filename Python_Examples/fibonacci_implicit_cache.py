from functools import lru_cache

@lru_cache(maxsize = 1000)
def fibonacci(n):
  # Input is required to be a positive integer
  if type(n) !=int:
    raise TypeError("n must be a positive integer...")
  if n < 1:
    raise ValueError("n must be a positive interger...")

  # Compute the Nth term
  if n == 1:
    return 1
  elif n == 2:
    return 1
  else:
    return fibonacci(n-1) + fibonacci(n-2)

for n in range(1, 501):
  print(n, ":", fibonacci(n))
