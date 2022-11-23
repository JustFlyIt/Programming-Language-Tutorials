fibonacci_cache = {}  # Define cache based dictionary

def fibonacci(n):
  # Check for an already cache result
  if n in fibonacci_cache:
    return fibonacci_cache[n]

  # Compute the Nth term
  if n == 1:
    value = 1
  elif n == 2:
    value = 1
  else:
    value = fibonacci(n-1) + fibonacci(n-2)

  # Cache the value and return with it
  fibonacci_cache[n] = value
  return value

for n in range(1, 1001):
  print(n, ":", fibonacci(n))
