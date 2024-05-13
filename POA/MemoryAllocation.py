
memoryPartition=[100,500,200,300,600]
Process=[212,417,112,426]
total_process=0

# User input
# process input
# n=int(input("Enter number of processes:"))
# for i in range(n):
#     process_allocation=int(input(f"Enter process {i+1}:"))
#     Process.append(process_allocation)


# total memory space calculation
# for i in range(len(memoryPartition)):
#     total_process+=memoryPartition[i]



def firstFit():
    firstFit=[0]*len(memoryPartition)

    for i in Process:
        for j in range(len(memoryPartition)):
            if(i<=memoryPartition[j] and firstFit[j]==0):
                firstFit[j]=i
                break 
    print(firstFit)

# firstFit()


def bestFit():
    best=[0]*len(memoryPartition)

    for i in Process:
        minimum=20000
        for j in range(len(memoryPartition)):
            if(i<=memoryPartition[j] and best[j]==0 and memoryPartition[j]<minimum):
                minimum=memoryPartition[j]
        
        if(minimum!=20000):
            best[memoryPartition.index(minimum)]=i
    print(best)

# bestFit()


def worstFit():
    worst=[0]*len(memoryPartition)

    for i in Process:
        maximum=-1
        for j in range(len(memoryPartition)):
            if(i<=memoryPartition[j] and worst[j]==0 and memoryPartition[j]>maximum):
                maximum=memoryPartition[j]
        
        if(maximum!=-1):
            worst[memoryPartition.index(maximum)]=i
    print(worst)

# worstFit()



# Just to display the best allocation technique in given case
# # best technique for these processes:
# judgementRound={
#     "First Fit":firstFit_memoryEfficiency,
#     "Best Fit":bestFit_memoryEfficiency,
#     "Worst Fit":worstFit_memoryEfficiency
# }

# max_technique=max(judgementRound,key=judgementRound.get)
# print(f"\nFor these processes best technique for max memory utilization is {max_technique} with memory efficiency {judgementRound[max_technique]}")
