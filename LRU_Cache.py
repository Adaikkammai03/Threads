class LRUCache:
  
    def __init__(self):
        self.cache={}
      
    def get(self,key):
        if key in self.cache:
            self.cache.move_to_end(key)
            return self.cache[key]
        else:
            return None
          
    def put(self,key,value):
        if key in self.cache:
            self.cache.move_to_end(key)
        elif len(self.cache)>=n:
            self.cache.popitem(0)
        self.cache[key]=value
      
    def display(self):
        for i in self.cache.items():
            print(*i)

lru_cache=LRUCache()

print("Enter capacity for Dictionary:")
n=int(input())

print("\n1. Put Data\n2. Get Data\n3. Display\n4. Exit")
while True:
    print("\nEnter your choice:")
    x=int(input())
    if x==1:
        key,val='',0
        print("\nDictionary Key:")
        key=input()
        print("\nDictionary Value:")
        val=int(input())
        lru_cache.put(key,val)
    elif x==2:
        print("Dictionary Key:")
        key=input()
        lru_cache.get(key)
    elif x==3:
        print("The Dictionary Elements are...")
        lru_cache.display()
    elif x==4:
        exit(0)
    else:
        print("Invalid Choice!")
