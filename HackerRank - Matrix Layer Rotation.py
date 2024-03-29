# Problem: www.hackerrank.com/challenges/matrix-rotation-algo/problem
#
# The algorithm decomposes the matrix into a number of lists and rotates them
# After the rotation the matrix is reconstructed from the lists

def rotatelist(lst,r):
    for _ in range(0,r):
        lst = [lst[-1]] + lst[:-1]
    return lst


def matrixRotation(matrix, r):

    rows = len(matrix)
    columns = len(matrix[0])
    
    #Number of lists created inside matrix
    lists = int (min(rows, columns) / 2) 

    for j in range (0,lists):
        left_side = list()
        right_side = list()
        down_side = list()
        up_side = list()
        
        #decompose matrix into lists
        for i in range(j, rows-j):                  
            left_side.append(matrix[i][j]) 

        for i in range(rows-1-j,-1+j,-1):
            right_side.append(matrix[i][columns-j-1])

        for i in range (j+1,columns-j-1):
            down_side.append(matrix[rows-j-1][i])

        for i in range (columns-2-j, j, -1):
            up_side.append(matrix[j][i])

        full_list = left_side + down_side + right_side + up_side
        
        identity_rotation = ((rows-1-2*j) + (columns-1-2*j))*2  

        new_list = rotatelist(full_list, r%identity_rotation) 
    
        #Compose the matrix 
        for i in range(j, rows-j):                          
            if new_list:
                matrix[i][j] = new_list.pop(0)
        
        
        for i in range (j+1,columns-j-1):
            if new_list:
                matrix[rows-j-1][i] = new_list.pop(0)
        
        
        for i in range(rows-1-j,-1+j,-1):
            if new_list:
                matrix[i][columns-j-1] = new_list.pop(0)
            
        for i in range (columns-2-j, j, -1):
            if new_list:
                matrix[j][i] = new_list.pop(0)
      
    for i in range(0,rows):                         
        for j in range (0,columns):
            print(matrix[i][j], end = " ")
        print()
        
