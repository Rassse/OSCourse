import dis

def foo():
    print("Tasty banana!")

print(foo.__code__.co_code)
print([byte for byte in foo.__code__.co_code])

dis.dis(foo)