# You are given an nxn 2D matrix representing an image
# Rotate the image by 90 degrees (clockwise)
# Note: You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
# DO NOT allocate another 2D matrix and do the rotation

# 1 2 3 4 5
# 6 7 8 9 a
# b c d e f
# g h i j k
# l m n o p

# My version
def rotate_matrix_v1(mat):
  if len(mat) < 1:
    return None
  if len(mat[0]) != len(mat):
    return None
  
  def rotate(mat, j, i):
    n = len(mat[0]) - 1
    
    temp = mat[n - i][j]
    mat[n - i][j] = mat[n - j][n - i]
    mat[n - j][n - i] = mat[i][n - j]
    mat[i][n - j] = mat[j][i]
    mat[j][i] = temp
    

  for j in range(0, len(mat)//2):
    for i in range(j, len(mat[0]) - 1 - j):
      rotate(mat, j, i)


def rotate_matrix_v2(mat):
  n = len(mat)
  # transpose
  for i in range(0, n):
    for j in range(i, n):
      mat[i][j], mat[j][i] = mat[j][i], mat[i][j]
  # Reverse
  for i in range(0, n):
    for j in range(0, n//2):
      mat[i][j], mat[i][n - 1 - j] = mat[i][n - 1 - j], mat[i][j]


def print_matrix(mat):
  for col in mat:
    for x in col:
      print(x, end=' ')
    print()
  print()


def main():
  mat = [
    [1,2,3,19],
    [4,5,6,28],
    [7,8,9,75],
    [36,58,96,35],
  ]
  print_matrix(mat)
  rotate_matrix_v1(mat)
  print_matrix(mat)
  

if __name__ == '__main__':
  main()