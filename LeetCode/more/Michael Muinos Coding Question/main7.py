# Given n non-negative integers a1,a2,...an where each represents a point at coordinate (i, ai), n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines which together with x-axis form a container, such that the container contains the most water.
# Note: You may not slant the container and n is at least 2.

import time

# my first version
def container_with_most_water_v1(heights):
  left_wall = -1
  right_wall = -1
  max_area = -1
  for i in range(len(heights)):
    for j in range(i + 1, len(heights)):
      area = min(heights[i], heights[j]) * (j - i)
      if area > max_area:
        max_area = area
        left_wall = i
        right_wall = j
  return left_wall, right_wall, max_area


# better solution, linear time complexity
def container_with_most_water_v2(heights):
  left_wall = -1
  right_wall = -1 
  max_area = -1
  i = 0
  j = len(heights) - 1
  while i < j:
    area = min(heights[i], heights[j]) * (j - i) 
    if area > max_area:
        max_area = area
        left_wall = i
        right_wall = j
    if heights[i] <= heights[j]:
      i += 1
    else:
      j -= 1
  return left_wall, right_wall, max_area


def main():
  heights = [1,8,6,2,5,4,8,3,7]
  t0 = time.time()
  r1 = container_with_most_water_v1(heights)
  t1 = time.time()
  r2 = container_with_most_water_v2(heights)
  t2 = time.time()

  print(r1, "time:", t1-t0)
  print(r2, "time:", t2-t1)


if __name__ == '__main__':
  main()