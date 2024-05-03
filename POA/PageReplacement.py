
frames=int(input("Enter number of frames:"))
# frames=3

n=int(input("Enter the number of processes:"))
# n=14
pageReq=[]

for i in range(n):
    pageReq.append(int(input("Enter Page number:")))
print(pageReq)


def fifo():
    hit=0
    miss=0
    PageTable=[]
    fifoTrack=[]



    for i in pageReq:
        if(len(PageTable)<frames):
            if(i in PageTable):
                hit+=1
            else:
                PageTable.append(i)
                fifoTrack.append(i)
                miss+=1
        else:
            if(i in PageTable):
                hit+=1
            else:
                PageTable[PageTable.index(fifoTrack[0])]=i
                fifoTrack.pop(0)
                fifoTrack.append(i)
                miss+=1
        print(f"number:{i} fifo track={fifoTrack} Page Table:{PageTable} , Miss:{miss}, Hit:{hit}")

    print(f"\nTotal hits:{hit} and miss:{miss}")
    print(f"%miss:{(miss/n)*100}%")
    print(f"%hit:{(hit/n)*100}%")




#LRU

def lru():
    hit=0
    miss=0
    PageTable=[]
    lruTrack=[]

    for i in pageReq:
        if(len(PageTable)<frames):
            if(i in PageTable):
                lruTrack.remove(i)
                lruTrack.append(i)
                hit+=1
            else:
                lruTrack.append(i)
                PageTable.append(i)
                miss+=1
        else:
            if(i in PageTable):
                lruTrack.remove(i)
                lruTrack.append(i)
                hit+=1
            else:
                PageTable[PageTable.index(lruTrack[0])]=i
                lruTrack.pop(0)
                lruTrack.append(i)
                miss+=1

        print(f"number:{i} lru track={lruTrack} Page Table:{PageTable} , Miss:{miss}, Hit:{hit}")

    print(f"\nTotal hits:{hit} and miss:{miss}")
    print(f"%miss:{(miss/n)*100}%")
    print(f"%hit:{(hit/n)*100}%")




def optimal():
    hit=0
    miss=0
    PageTable=[]
    optimalTrack={}
    tempOptimal=pageReq[:]

    for i in pageReq:
        
        if(len(PageTable)<frames):
            if(i in PageTable):
                hit+=1
            else:
                PageTable.append(i)
                miss+=1
            optimalTrack[i]=0  #to start filling tracking dictionary

        else:            
            if(i in PageTable):
                hit+=1
            else:       
                optimalTrack[i]=0                                       #adding new page request to track      
                tempOptimal=tempOptimal[(tempOptimal.index(i)):]        #shortening check area entire table-table checked till now . imp to shorten the list to ensure [4,7,3,4] but [4,7,3] is covered. it should take 2nd 4 not 1st

                for key,value in optimalTrack.items():
                    if(key in tempOptimal):
                        optimalTrack[key]=tempOptimal.index(key)        #changing value of track key:index of element in tempOptimal
                    else:
                        optimalTrack[key]=1000                          #maximising element not possible to take it first   to  be replaced

               

                max_key=max(optimalTrack,key=optimalTrack.get)          #getting key with max value from dictionary
                optimalTrack.pop(max_key)                               #removing page not required from track
                PageTable[PageTable.index(max_key)]=i                   #updating page table finally
                miss+=1

    
        print(f"element:{i} ,optimal track:{optimalTrack}, pageTable:{PageTable} ,miss:{miss} ,hit:{hit}")
    print(f"hit:{hit} miss:{miss}")



print("\nFIFO:")
fifo()
print("\nLRU:")
lru()
print("\noptimal:")
optimal()


