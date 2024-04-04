prime_range = [ int(input()) for _ in range(2) ]
primes = [ 2 ]

def get_result(prime_range: list[int]) -> list[int]:
    min_prime = -1
    total = 0
    for i in range(2, prime_range[1] + 1):
        if 1 in [ 1 if (i % p == 0 and i / p != 1) else 0 for p in primes ]: continue

        primes.append(i)

        if i < prime_range[0]: continue

        if min_prime == -1: min_prime = i
        total += i

    return [ total, min_prime ]
        

result = get_result(prime_range)

if result[1] == -1:
    print(-1)
else:
    print(result[0])
    print(result[1])
