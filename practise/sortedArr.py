def generate_sorted_array(size):
  """Generates a sorted array of size."""
  array = []
  for i in range(size):
    array.append(i)
  return sorted(array)


def main():
  size = 180
  array = generate_sorted_array(size)
  s = ' '.join(str(x) for x in array)
  print(s)


if __name__ == "__main__":
  main()