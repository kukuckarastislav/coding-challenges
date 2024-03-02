# Given two word (beginWord and endWord), and a dictionarys word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
# 1. Only one letter can be changed at a time.
# 2. Each transformed word must exist in the word list
# Note:
# Return 0 if there is no such transformation sequence
# All words have the same length
# All words contain only lowercase alphabetic characters
# You may asume no duplicates in the word list
# You may assume beginWord and endWord are non-empty and are not the same
# Example 1
# Input:
#   beginWord = "hit", endWord = "cog",
#   wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
# Output: 5

from collections import deque


def get_number_of_diff_chars(str1, str2):
    return sum(x != y for x, y in zip(str1, str2))


def ladder_length(begin_word, end_word, word_list):
  que = deque()
  visited_set = set()
  changes = 1
  que.append(begin_word)
  visited_set.add(begin_word)

  print(que)
  print(visited_set)
  print(changes)
  print()

  while len(que) > 0:
    for i in range(len(que)):
      curr_word = que.popleft()
      if curr_word == end_word:
        return changes
      for word in word_list:
        if get_number_of_diff_chars(word, curr_word) == 1:
          if word not in que and word not in visited_set:
            que.append(word)
            visited_set.add(word)
            print(que)
            print(visited_set)
            print(changes)
            print()
    changes += 1  
  return 0




def main():
  beginWord = "hit"
  endWord = "cog"
  wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
  r = ladder_length(beginWord, endWord, wordList)
  print(r)


if __name__ == '__main__':
  main()