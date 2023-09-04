#Python program to synchronize two threads

import threading
import time

def thread1():
    for i in range(1,4):
        print("Thread 1:",i)
    time.sleep(0.1)
    for i in range(7,11):
        print("Thread 1:",i)
        
def thread2():
    for i in range(4,7):
        print("Thread 2:",i)
        
if __name__=="__main__":
    t1=threading.Thread(target=thread1)
    t2=threading.Thread(target=thread2)
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    
'''
Thread 1: 1
Thread 1: 2
Thread 1: 3
Thread 2: 4
Thread 2: 5
Thread 2: 6
Thread 1: 7
Thread 1: 8
Thread 1: 9
Thread 1: 10
'''
