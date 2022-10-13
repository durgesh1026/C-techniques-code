# Gcd is the function to find the gcd of two numbers .
# Here this function uses the euclidean algorithm.
def gcd(a, b):

    # checking if b is greater than a.
    if(b>a):
        return gcd(b,a)

    # checking if the number a is zero then b is the result.    
    if b == 0:
        return a
    
    # returning the gcd in which a becomes b and b becomes b%a.
    return gcd(b,a%b)

# Driver code start from Here

# Taking input of a integer a . 
a = input("Enter the first Number : ")
# Taking input of the second integer that is b.
b = input("Enter the second Number : ")

# Finding the gcd of a and b using the gcd function.
res = gcd(int(a),int(b))

#Printing the gcd of two numbers.
print("The gcd of "+ a + " and "+ b+" is " + str(res))