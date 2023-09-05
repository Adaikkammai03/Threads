import multiprocessing
import random
import time

def thread1(queue):
    while True:
        i=random.randint(0,100)
        queue.put(f"Thread Job 1: {i}")
        time.sleep(1)

def thread2(queue):
    while True:
        i=random.randint(100,200)
        queue.put(f"Thread Job 2: {i}")
        time.sleep(1)

queue=multiprocessing.Queue()
p1=multiprocessing.Process(target=thread1,args=(queue,))
p2=multiprocessing.Process(target=thread2,args=(queue,))
p1.start()
p2.start()
while True:
    print(str(queue.get()))

