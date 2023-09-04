class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        
class LinkedList:
    def __init__(self):
        self.head=None
        
    def insertion(self,data):
        newnode=Node(data)
        if not self.head:
            self.head=newnode
        elif data<self.head.data:
            newnode.next=self.head
            self.head=newnode
        else:
            current=self.head
            while(current.next!=None and current.next.data<data):
                current=current.next
            newnode.next=current.next
            current.next=newnode
            
    def deletion(self,data):
        if self.head.data==data:
            self.head=self.head.next
        else:
            current=self.head
            while(current.next!=None):
                if current.next.data==data:
                    break
                current=current.next
            if current.next:
                current.next=current.next.next
             
    def reverse(self):
        prev=None
        current=self.head
        while(current!=None):
            next=current.next
            current.next=prev
            prev=current
            current=next
        self.head=prev
        
    def display(self):
        current=self.head
        while(current!=None):
            print(current.data,end=' ')
            current=current.next
        print()

l=LinkedList()

print("\n1. Insertion\n2. Deletion\n3. Reverse\n4. Display\n5. Exit\n")
while(True):
    print("\nChoice: ")
    n=int(input())
    if n==1:
        print("Enter the data to insert:")
        l.insertion(int(input()))
    elif n==2:
        print("Enter the data to delete:")
        l.deletion(int(input()))
    elif n==3:
        l.reverse()
    elif n==4:
        l.display()
    elif n==5:
        exit(0)
    else:
        print("Invalid Choice!")
