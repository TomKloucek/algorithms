import sys
def eratosthenes_sieve(max):
    numbers = [x for x in range(2,max+1)]
    for cislo in range(2,max+1):
        for nasobek in range(2,(max//cislo)+1):
            numbers[(cislo*nasobek)-2] = 0    
    return [x for x in numbers if x!=0]
eratosthenes_sieve(int(sys.argv[1]))

### Results
# Prime numbers under 25 - time: 0,026s
# Prime numbers under 100,000 - time: 0,088s
# Prime numbers under 250,000 - time: 0,266s
# Prime numbers under 1,000,000 - time: 2,074s
