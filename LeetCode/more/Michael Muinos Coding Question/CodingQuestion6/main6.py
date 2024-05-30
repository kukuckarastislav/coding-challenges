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


class Node:
  def __init__(self, begin_word, end_word, word_list, parent_node, state) -> None:
    self.begin_word = begin_word
    self.end_word = end_word
    self.word_list = word_list

    self.parent_node = parent_node
    self.state = state

    if self.parent_node != None:
      self.depth = self.parent_node.depth + 1
    else:
      self.depth = 0

    self.next_states = []
    for word in self.word_list:
      if self.get_number_of_diff_chars(self.state, word) == 1:
        self.next_states.append(word)

    self.next_nodes = []
    for next_state in self.next_states:
      parent = self.parent_node
      circular_state = False
      while parent != None:
        if parent.state == next_state:
          circular_state = True
          break
        parent = parent.parent_node
      if not circular_state:
        new_node = Node(begin_word, end_word, word_list, self, next_state)
        self.next_nodes.append(new_node)

    
  def get_number_of_diff_chars(self, str1, str2):
    return sum(x != y for x, y in zip(str1, str2))
  

  def print_node(self):
    print("State:",self.state)
    print("Childs: ", end="")
    for next_node in self.next_nodes:
      print(next_node.state, end=', ')
    print()
    print()
    for next_node in self.next_nodes:
      next_node.print_node()


  def find_final_node(self):
    if self.state == self.end_word:
      return self

    final_nodes = []
    for next_node in self.next_nodes:
      final_node = next_node.find_final_node()
      if final_node != None:
        final_nodes.append(final_node)
    if len(final_nodes) > 0:
      final_nodes.sort(key=lambda x: x.depth)
      return final_nodes[0]
    return None 
  

  def find_shortest_transformation_sequence(self):
    final_node = self.find_final_node()
    path = []
    node_it = final_node
    while node_it != None:
      path.append(node_it.state)
      node_it = node_it.parent_node
    path.reverse()
    return path
  

def main():
  beginWord = "hit"
  endWord = "cog"
  wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
  head = Node(beginWord, endWord, wordList, None, beginWord)
  path = head.find_shortest_transformation_sequence()
  print(len(path))
  for i in range(len(path)):
    if i == len(path) - 1:
      print(path[i])
    else:
      print(path[i], end=' -> ')


if __name__ == '__main__':
  main()