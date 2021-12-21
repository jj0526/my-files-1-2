def hello(count):
    if count == 0:
        return
    print('Hello, python!', count)
    count -=1
    hello(count)
hello(5)