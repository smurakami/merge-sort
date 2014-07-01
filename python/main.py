# coding: utf-8

from time import time

def loadFile(filename):
  arrays = []
  with open(filename, 'r') as f:
    for line in f:
      array = readArray(line)
      arrays.append([int(n) for n in array])
  return arrays

def readArray(s):
  return s.split(' ')

def merge(array_a, array_b):
  array = []
  for i in xrange(len(array_a) + len(array_b)):
    if not array_b or array_a and array_a[0] < array_b[0]:
      array.append(array_a.pop(0))
    else:
      array.append(array_b.pop(0))
  return array


def merge_sort(array):
  if (len(array)) == 1:
    return array
  half_len = len(array) / 2
  array_a = array[:half_len]
  array_b = array[half_len:]
  array_a = merge_sort(array_a)
  array_b = merge_sort(array_b)
  array = merge(array_a, array_b)
  return array

LOOP_NUM = 10

if __name__ == "__main__":
  arrays = loadFile('../problem.txt')
  start = time()
  for _ in range(LOOP_NUM):
    for array in arrays:
      # print array
      array = merge_sort(array)
      # print array
  print time() - start
  print len(arrays)
