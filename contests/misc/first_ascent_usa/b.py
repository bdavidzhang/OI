#part A
def successor(A:list) -> list:
    n = len(A)
    for i in range(n):
        A[i] += 1
        if A[i] == 3:
            A[i] = 0
            if i == n-1:
                A.append(1)
        else:
            break
    return A
    

# A = [2,2,2]
# print(successor(A))

#part B
def leq(A:list, B:list) -> bool:
    m = len(A)
    n = len(B)
    if n > m:
        for i in range(n-1,m-1,-1):
            if B[i] != 0:
                return True
    elif n < m:
        for i in range(m-1,n-1,-1):
            if A[i] != 0:
                return False
    for i in range(min(n,m)-1,-1,-1):
        # print(i)
        # print(A[i])
        # print(B[i])
        if A[i] < B[i]:
            return True
        if A[i] > B[i]:
            return False
    return True #equal


A = [2,0,2,0]
B = [1,0,2]
print(leq(A,B)) 


#part C
def tritwise_min(A:list, B:list) -> list:
    m = len(A)
    n = len(B)
    result = [0]*min(m,n)
    for i in range(min(m,n)):
        result[i] = min(A[i],B[i])
    return result

    
# A = [2,1]
# B = [0,2,1]
# print(tritwise_min(B,A))

#part D 
def f(A:list,B:list) -> list: 
    if not leq(A,B):
        raise ValueError("A should be less than B")
    cur = A 
    result = cur
    while(leq(cur,B)):
        # print(cur)
        result = tritwise_min(result,cur)
        cur = successor(cur)
    return result



# print(f(A,B))
    

#part E
def f_eff(A:list,B:list) -> list: 
    if not leq(A,B):
        raise ValueError("A should be less than B")
    
    m = len(A)
    n = len(B)
    #if B is longer than A (with nonzero element), then 
    #the result should be all zeros 
    #let idx be the nonzero index, then we will reach some number 
    # 0, ... 0, B[idx], 0 0 0 
    #but the initial state is 
    # A[0], ..., A[m], 0 , ..., 0
    #where m < idx
    for i in range(n-1,m-1,-1):
        if B[i] != 0:
            return [0] * min(m,n)
    
    

    # otherwise, it suffices to consider A and B of the same length, because otherwise 
    # the end will be filled with 0s. 

    
    result = [0] * min(m,n) #result array
    #if there is a chunk of equal values at the end
    split = -1 #find that split index
    for i in range(min(m,n)-1,-1,-1):
        if A[i] == B[i]:
            result[i] = A[i]
            split = i
        else:
            break
    split -= 1
    # print(f"split: {split}")
    #the first digit of A here must be smaller
    #then all the other digits will be 0 
    #because it will have to reach a state 0,...0,B[split],...
    if split >= 0:
        result[split] = A[split]
    else:
        result[min(m,n)-1] = A[min(m,n)-1]
    return result

A = [0,0,0,1,0]
B = [0,0,1,1,0]
print(f_eff(A,B))
print(f(A,B))

def equal(A,B):
    return leq(A,B) and leq(B,A)
   

# print([1,2,3])
# print([2,3,4])


#test leq
# import random
# nums = [0,1,2]
# for _ in range(100):
#     m = random.randint(1,5)
#     n = random.randint(1,5)
#     A = [0]*m
#     B = [0]*n
#     for i in range(m):
#         A[i] = random.choice(nums)
#     for i in range(n):
#         B[i] = random.choice(nums)
#     if leq(A,B):
#         print(leq(A,B))
#         print("A <= B")
#         print(f"A: {A}")
#         print(f"B: {B}") 


import random
nums = [0,1,2]
for _ in range(100):
    m = random.randint(1,5)
    n = random.randint(1,5)
    A = [0]*m
    B = [0]*n
    for i in range(m):
        A[i] = random.choice(nums)
    for i in range(n):
        B[i] = random.choice(nums)
    if leq(A,B):
        # print(leq(A,B))
        # print('-'*20) 
        # print(f"A: {A}")
        # print(f"B: {B}")
        res1 = f_eff(A,B)
        res2 = f(A,B)
        if not equal(res1,res2):
            print('-'*10)
            print("A <= B")
            print(f"f_eff: {res1}")
            print(f"f: {res2}")
            print('-'*10)
#     else:
#         res1 = f_eff(B,A)
#         res2 = f(B,A)
#         if not equal(res1,res2):
#             print('-'*10)
#             print("A > B")
#             print(f"A: {A}")
#             print(f"B: {B}")
#             print(f"f_eff: {res1}")
#             print(f"f: {res2}")