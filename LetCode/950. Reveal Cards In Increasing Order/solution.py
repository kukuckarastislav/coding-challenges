class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort(reverse = True)
        n = len(deck)
        res_que = deque()
        
        res_que.appendleft(deck[0])
        for i in range(1, n):
            res_que.appendleft(res_que.pop())
            res_que.appendleft(deck[i])

        return res_que
        