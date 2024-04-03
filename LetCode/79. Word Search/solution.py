class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])

        if len(word) > n*m:
            return False        

        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]:
                    if self.findWord(board, word, 0, i, j):
                        return True
        
        return False
    
    def findWord(self, board: List[List[str]], word: str, depth: int, i: int, j: int) -> bool:

        if board[i][j] == '':
            return False
        
        if word[depth] != board[i][j]:
            return False
        
        temp = board[i][j]
        board[i][j] = ''

        depth += 1

        if depth == len(word):
            return True
        
        m = len(board)
        n = len(board[0])

        found = False
        if i - 1 >= 0:
            found = self.findWord(board, word, depth, i-1, j)
        if not found and j - 1 >= 0:
            found = self.findWord(board, word, depth, i, j-1)
        if not found and i + 1 < m:
            found = self.findWord(board, word, depth, i+1, j)
        if not found and j + 1 < n:
            found = self.findWord(board, word, depth, i, j+1)
        
        board[i][j] = temp
        
        return found