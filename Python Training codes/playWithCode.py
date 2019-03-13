
N = int(input())

if N%2 != 0:
    print("Weird")
else:
    if N in range(2, 5):
        print("Not Weird")
    elif N in range(6, 20):
        print("Weird")
    elif N > 20:
        print("Not Weird")

for N in range (2,6):
    print(N)
    N = N + 1
    
###############################
    
a = int(input())
b = int(input())
print(a + b)
print(a - b)
print(a * b)
print(a // b)
print(a /b)
