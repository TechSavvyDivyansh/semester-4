
# frames=int(input("Enter number of frames:"))
frames=3
# n=int(input("Enter the number of processes:"))
n=14
pageReq=[4,7,3,0,1,7,3,8,5,4,5,3,4,7]

# for i in range(n):
#     pageReq.append(int(input("Enter Page number:")))
# print(pageReq)


#fifo
def fifo():
    hit=0
    miss=0
    PageTable=[-1]*frames
    temp=0

    for i in pageReq:
        
        if(pageReq[i] in PageTable):
            hit+=1

        else:
            miss+=1
            PageTable[temp]=i
            temp=(temp+1)%frames
           
        print(f"number:{i} Page Table:{PageTable} , Miss:{miss}, Hit:{hit}")



#LRU

def lru():
    hit=0
    miss=0
    PageTable=[-1]*frames
    lruTrack=[-1]*frames


    for i in range(n):
        if(pageReq[i] in PageTable):
            hit+=1
            lruTrack[PageTable.index(pageReq[i])]=i
        
        else:
           miss+=1
           index=lruTrack.index(min(lruTrack))
           PageTable[index]=pageReq[i] 
           lruTrack[index]=i
 
        print(f"Page Request: {pageReq[i]}, LRU Track: {lruTrack}, Page Table: {PageTable}, Miss: {miss}, Hit: {hit}")



def optimal():
    hit=0
    miss=0
    PageTable=[-1]*frames
    optimalTrack=[-1]*frames
    count=0

    
    for i in range(n):
        
        if(pageReq[i] in PageTable):
            hit+=1
        
        else:
            miss+=1

            if(count<frames):
                PageTable[count]=pageReq[i]
                count+=1
            else:
                for k in range(frames):
                    if(PageTable[k] in pageReq[i+1:]):
                        optimalTrack[k]=pageReq[i+1:].index(PageTable[k])
                    else:
                        optimalTrack[k]=10000
                
                PageTable[optimalTrack.index(max(optimalTrack))]=pageReq[i]


        print(f"element:{i} ,optimal track:{optimalTrack}, pageTable:{PageTable} ,miss:{miss} ,hit:{hit}")
                    
                        

                
            





# print("\nFIFO:")
# fifo()
print("\nLRU:")
lru()
# print("\noptimal:")
# optimal()


