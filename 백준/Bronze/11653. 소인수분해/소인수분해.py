primes = [ 2 ]

N = int(input())
i = 2

while N != 1:
    if N % i != 0:
        i += 1
        continue

    N = N / i

    print(i)