# Given a non-empty list of words, return the k most frequent elements.
# Your answer should be sorted by frequenccy from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

# Example 1:
# Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
# Output: ["i", "love"]
# Explanation: "i" and "love" are the two most frequent words.
# Note that "i" comes before "love" due to a lower alphabetical order.

# Example 2:
# Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
# Output: ["the", "is", "sunny", "day"]
# Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
# with the number of occurrence being 4, 3, 2 and 1 respectively.

# Note:
# 1. You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
# 2. Input words contain only lowercase letters.

# Follow up:
# 1. Try to solve it in O(n log k) time and O(n) extra space.


def fun(words, k):
  dict_words = dict()
  for word in words:
    if word in dict_words:
      dict_words[word] += 1
    else:
      dict_words[word] = 1
  list_words = list(dict_words.items())
  list_words.sort(key=lambda x: (-x[1], x[0]))
  return list_words[:k]


def main():
  words = ["i", "love", "leetcode", "i", "love", "coding"]
  k = 2
  print(fun(words, k))


if __name__ == '__main__':
  main()