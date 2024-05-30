# You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.
# Input [1,1,2,3,3,4,4,8,8]
# Output 2
# Input [3,3,7,7,10,11,11]
# Output 10


def find_single_element(nums):
  if len(nums) == 0:
    return None
  
  left = 0
  right = len(nums) - 1
  while left < right:
    mid = left + (right - left) // 2 # (left + right)/2 can produce overflow 
    if nums[mid] == nums[mid - 1]:
      if mid % 2 == 0:
        # check left side
        right = mid - 2
      else:
        # check right side
        left = mid + 1
    elif nums[mid] == nums[mid + 1]:
      if mid % 2 == 0:
        # check right side
        left = mid + 2
      else:
        # check left side
        right = mid - 1
    else:
      return nums[mid]
  return nums[left]


def find_single_element_v2(nums):
  i = 0
  while i < len(nums):
    if nums[i] != nums[i + 1]:
      return nums[i]
    i += 2


def main():
  nums = [1,1,2,3,3,4,4,8,8]
  print(find_single_element(nums))
  print(find_single_element_v2(nums))


if __name__ == '__main__':
  main()
