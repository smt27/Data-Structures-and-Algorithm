



class dictionary:
    def __init__(self):
        self.HashTable=[[]for i in range(10)]  #created hashtable of size 10
    
    def gethash(self,key):
        return key%10
    
    def insert(self,key,value):
        hashvalue=self.gethash(key)
        inserted=False
        for i in range(len(self.HashTable[hashvalue])):
            if(self.HashTable[hashvalue][i][0]==key):
                HashTable[hashvalue][i][1]=value
                inserted=True
        if not inserted:
            self.HashTable[hashvalue].append([key,value])
             
        
    
    def search(self,key):
        hashvalue=self.gethash(key)
        for i in range(len(self.HashTable[hashvalue])):
            if(self.HashTable[hashvalue][i][0]==key):
                print("key: ",self.HashTable[hashvalue][i][0])
                print("value: ",self.HashTable[hashvalue][i][1])
                return
        print("data not found\n")
            
                
    
    def update(self,key):
        hashvalue=self.gethash(key)
        value=input("enter the new value: ")
        for i in range(len(self.HashTable[hashvalue])):
            if(self.HashTable[hashvalue][i][0]==key):
                self.HashTable[hashvalue][i][1]=value
                print("data updated successfully")
            else:
                print("data not found to be updated so will get inserted ")
                insert(key,value)
        
        
    def display(self):
        for i in range(len(self.HashTable)):
            for j in range(len(self.HashTable[i])):
                if(self.HashTable!=0):
                    print(self.HashTable[i][j][0],"->",self.HashTable[i][j][1])


    def delete(self,key):
        hashvalue=self.gethash(key)
        for i in range(len(self.HashTable[hashvalue])):
            
            if(self.HashTable[hashvalue][i][0]==key):
                del self.HashTable[hashvalue][i]
                print("the key successfully deleted\n")
                return
        print("key not found")





dicti=dictionary()
print("The operations on dictionary")
while(True):
  
    print("1.insert\t2.search\t3.delete\t4.update\t5.display\t6.exit")
    e=int(input("enter your choice: "))
    if(e==1):
        key=int(input("enter key: "))
        value=input("enter value: ")
        dicti.insert(key,value)
        
    elif(e==2):
        key=int(input("enter key to search: "))
        dicti.search(key)
        
    elif(e==3):
        key=int(input("enter the key to delete: "))
        dicti.delete(key)
        
    elif(e==4):
        key=int(input("enter the key to update: "))
        dicti.update(key)
        
    elif(e==5):
        dicti.display()
        
    elif(e==6):
        print("exited successfully")
        break
    
    else:
        print("enter valid input")
