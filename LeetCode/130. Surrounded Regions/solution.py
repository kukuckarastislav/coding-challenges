'''
Runtime
116
ms
Beats
77.21%
of users with Python3
Memory
17.75
MB
Beats
98.28%
of users with Python3
'''
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        n = len(board)
        m = len(board[0])

        def fill(i, j):
            board[i][j] = 'S'
            for dx, dy in [(-1,0),(0,-1),(1,0),(0,1)]:
                ii = i + dx
                jj = j + dy
                if ii >= 0 and ii < n and jj >= 0 and jj < m and board[ii][jj] == 'O':
                    fill(ii, jj)

        for i in range(n):
            for j in [0, m-1]:
                if board[i][j] == 'O':
                    fill(i, j)
        
        for j in range(m):
            for i in [0, n-1]:
                if board[i][j] == 'O':
                    fill(i, j)
        

        for i in range(n):
            for j in range(m):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == 'S':
                    board[i][j] = 'O'







'''
Runtime
118
ms
Beats
68.51%
of users with Python3
Memory
27.35
MB
Beats
8.94%
of users with Python3
'''
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        n = len(board)
        m = len(board[0])

        def fill(i, j, charFrom, charTo):
            board[i][j] = charTo
            for dx, dy in [(-1,0),(0,-1),(1,0),(0,1)]:
                ii = i + dx
                jj = j + dy
                if ii >= 0 and ii < n and jj >= 0 and jj < m and board[ii][jj] == charFrom:
                    fill(ii, jj, charFrom, charTo)


        def saveBorders(charFrom, charTo):
            for i in range(n):
                if board[i][0] == charFrom:
                    fill(i, 0, charFrom, charTo)
                if board[i][m-1] == charFrom:
                    fill(i, m-1, charFrom, charTo)

            for j in range(m):
                if board[0][j] == charFrom:
                    fill(0, j, charFrom, charTo)
                if board[n-1][j] == charFrom:
                    fill(n-1, j, charFrom, charTo)
            
        
        saveBorders('O', 'S')
        
        for i in range(n):
            for j in range(m):
                if board[i][j] == 'O':
                    fill(i, j, 'O', 'X')

        saveBorders('S', 'O')