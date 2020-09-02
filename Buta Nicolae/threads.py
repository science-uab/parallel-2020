import threading
from multiprocessing import Queue   

results = []
results2 = []

def take_numbers(q):
    print('Enter the numbers:')
    for i in range(0,3):
        num1 = int(input('Enter first number: '))
        num2 = int(input('Enter second number: '))
        q.put(num1)
        q.put(num2)

def add_num(q):
    for i in range(0,3):
        num1 = q.get()
        num2 = q.get()
        results.append(num1+num2)
        results2.append(num1-num2)

q = Queue()
t2 = threading.Thread(target=add_num, args=(q, ))
t1 = threading.Thread(target=take_numbers, args=(q, ))

t2.start()
t1.start()
t2.join()
t1.join()
q.close()

for result in results:
    print ("adunare =",  result)

for result in results2:
    print ("scadere =",  result)