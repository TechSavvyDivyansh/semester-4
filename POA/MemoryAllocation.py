# (Divyansh Modi-60004220034-C1-2) (Memory Allocation)

memoryPartition=[100,500,200,300,600]
Process=[]
total_process=0


# process input
n=int(input("Enter number of processes:"))
for i in range(n):
    process_allocation=int(input(f"Enter process {i+1}:"))
    Process.append(process_allocation)


# total memory space calculation
for i in range(len(memoryPartition)):
    total_process+=memoryPartition[i]



# best fit
print("\n---Best Fit---")

bestFit=[0]*len(memoryPartition)
allocated_process_best=0
tempMemory_best=memoryPartition[0:]

for i in Process:
    tempList = []
    for j in range(len(tempMemory_best)):
        if (i <= tempMemory_best[j] and bestFit[j]==0):
            tempList.append(tempMemory_best[j])
    if tempList:
        key = min(tempList)
        posn = tempMemory_best.index(key)
        bestFit[posn] = i


for i in range(len(bestFit)):
    allocated_process_best+=bestFit[i]

print(bestFit)
bestFit_memoryEfficiency=allocated_process_best/total_process
print(f'Memory efficiency:{bestFit_memoryEfficiency}')
    



# First fit
print("\n---First fit---")

firstFit=[0]*len(memoryPartition)
allocated_process_first=0
tempMemory_first=memoryPartition[0:]

for i in Process:
    for j in range(len(tempMemory_first)):
        if(i<=tempMemory_first[j] and firstFit[j]==0):
            firstFit[j]=i
            break
for i in range(len(firstFit)):
    allocated_process_first+=firstFit[i]

print(firstFit)
firstFit_memoryEfficiency=allocated_process_first/total_process
print(f"Memory Efficiency:{firstFit_memoryEfficiency}")




#worst fit
print("\n---Worst Fit---")

worstFit=[0]*len(memoryPartition)
allocated_process_worst=0
tempMemory_worst=memoryPartition[0:]


for i in Process:
    tempList = []
    for j in range(len(tempMemory_worst)):
        if (i <= tempMemory_worst[j] and worstFit[j]==0):
            tempList.append(tempMemory_worst[j])
    if tempList:
        key = max(tempList)
        posn = tempMemory_worst.index(key)
        worstFit[posn] = i


for i in range(len(worstFit)):
    allocated_process_worst+=worstFit[i]

print(worstFit)
worstFit_memoryEfficiency=allocated_process_worst/total_process
print(f'Memory efficiency:{worstFit_memoryEfficiency}')



# best technique for these processes:
judgementRound={
    "First Fit":firstFit_memoryEfficiency,
    "Best Fit":bestFit_memoryEfficiency,
    "Worst Fit":worstFit_memoryEfficiency
}

max_technique=max(judgementRound,key=judgementRound.get)
print(f"\nFor these processes best technique for max memory utilization is {max_technique} with memory efficiency {judgementRound[max_technique]}")
