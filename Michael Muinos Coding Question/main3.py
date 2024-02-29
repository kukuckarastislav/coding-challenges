# Given two non-negative integers num1 and num2 representend as string, return the sum of num1 and num2
# Note:
# 1. The lenght of both num1 and num2 is < 5100
# 2. Both num1 and num2 contains only digits 0-9
# 3. Both num1 and num2 does not contain any leading zero
# 4. you must not use any built-in BigInteger library or convert the inputs to integer directly

def char_to_digit(c: str):
  return ord(c) - 48
    

def sum_two_number_string(num1: str, num2: str):
  result = 0
  i = 0
  i1 = len(num1) - 1
  i2 = len(num2) - 1
  
  while True:
    digit1 = char_to_digit(num1[i1]) if i1 >= 0 else 0
    digit2 = char_to_digit(num2[i2]) if i2 >= 0 else 0
    result += (digit1 + digit2) * 10**i

    i += 1
    i1 -= 1
    i2 -= 1

    if i1 < 0 and i2 < 0:
      break

  return result


def main():
  num1 = "56573522"
  num2 = "23985685684"
  print('Result is', sum_two_number_string(num1, num2), int(num1)+int(num2))


if __name__ == '__main__':
 main()