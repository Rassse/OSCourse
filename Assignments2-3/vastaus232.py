import sys

def printf(format, *args):

    sys.stdout.write(format % args)

printf("moikka %s\n", "maailma")