
#assignment 1

class linear_probing:
    def __init__(self,n):
        node=[0," "]
        self.hash_table=[node for i in range(n)]
        self.n=n
        
    def insert(self):
        name=input("enter the name: ")
        phone=int(input("enter the phone number: "))
        
        for i in range(0,self.n):
            index=(phone+i)%self.n
            if (self.hash_table[index]==[0," "]):
                self.hash_table[index]=[phone,name]
                break
            else:
                continue
            print()
            
    def display(self):
        print(self.hash_table)
    
    def search(self):
        phone=int(input("enter the phonenumber to be searched: "))
        comp=0
        for i in range(0,self.n):
            index=(phone+i)%self.n
            comp+=1
            if self.hash_table[index][0]==phone:
                print(self.hash_table[index])
                print("index:",index)
                print("comprisions made:",comp)
                break
            else:
                continue
            
            
            
class quadratic_probing:
    def __init__(self,n):
        node=[0," "]
        self.hash_table=[node for i in range(n)]
        self.n=n
        
    def insert(self):
        name=input("enter the name: ")
        phone=int(input("enter the phone number: "))
        
        for i in range(0,self.n):
            index=(phone+i*i)%self.n
            if (self.hash_table[index]==[0," "]):
                self.hash_table[index]=[phone,name]
                break
            else:
                continue
            
    def display(self):
        print(self.hash_table)
    
    def search(self):
        phone=int(input("enter the phonenumber to be searched: "))
        comp=0
        for i in range(0,self.n):
            index=(phone+i*i)%self.n
            comp+=1
            if self.hash_table[index][0]==phone:
                print(self.hash_table[index])
                print("index: ",index)
                print("comprisions made:",comp)
                break
            else:
                continue
            print() 
            
n=int(input("the number of inputs is? ")) 
q=quadratic_probing(n)
for i in range(n):
    q.insert()
q.search()
q.display()

linear=linear_probing(n)
for i in range(n):
    linear.insert()

linear.search()
linear.display()



        
