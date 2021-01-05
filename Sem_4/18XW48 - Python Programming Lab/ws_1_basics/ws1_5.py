def isPrime(num):
    
    for i in range(2, num):
        if (num % i) == 0:
            return False       
    return True

if __name__  == "__main__":
    
    for i in range(2, 51):
        if isPrime(i):
            print(i)