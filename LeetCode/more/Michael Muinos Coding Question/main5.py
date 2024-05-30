# Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists
# Example:
# Input: 1->2->4, 1->3->4
# Output: 1->1->2->3->4->4


def merge_lists(l1, l2):
  new_list = []
  n1 = len(l1)
  n2 = len(l2)
  i1 = 0
  i2 = 0
  while i1 < n1 and i2 < n2:
    if l1[i1] < l2[i2]:
      new_list.append(l1[i1])
      i1 += 1
    else:
      new_list.append(l2[i2])
      i2 += 1
  while i1 < n1:
    new_list.append(l1[i1])
    i1 += 1
  while i2 < n2:
    new_list.append(l2[i2])
    i2 += 1
  return new_list


def main():
  l1 = [1,2,4,5,1000]
  l2 = [8,9,11,12,14,156]
  l = merge_lists(l1, l2)
  print(l)


if __name__ == '__main__':
  main()
