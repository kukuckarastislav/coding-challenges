# Sliding Window Algorithm - Longest Substring Without Repeating Characters
# for string "PWWKEW" we have "WKE" and "KEW"


def longest_substring_without_repeating_characters_v1(s):
  longest_subs = ""
  substrings = []

  for i in range(len(s)):
    for j in range(i+1, len(s)):
      char_set = set()
      all_chars_unique = True
      for c in s[i:j+1]:
        if c in char_set:
          all_chars_unique = False
          break
        else:
          char_set.add(c)
      if all_chars_unique:
        substrings.append(s[i:j+1])
        if len(s[i:j+1]) > len(longest_subs):
          longest_subs = s[i:j+1]
  return substrings, longest_subs


def longest_substring_without_repeating_characters_v2(s):
  i = 0
  j = 0
  longest_subs = ""
  char_set = set()
  while i < len(s):
    while s[i] in char_set:
      char_set.remove(s[j])
      j+=1
    char_set.add(s[i])
    if (i - j + 1) > len(longest_subs):
      longest_subs = s[j:i+1]
    i+=1
  return longest_subs


def main():
  s = "PWWKEW"
  print(longest_substring_without_repeating_characters_v1(s))
  print(longest_substring_without_repeating_characters_v2(s))


if __name__ == '__main__':
  main()