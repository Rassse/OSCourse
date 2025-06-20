import dis

def flat(num):

    if num % 3 == 0:

        print ("Fizz")

    elif num % 5 == 0:

        print ("Buzz")

    else:

        print (num)


dis.dis(flat)