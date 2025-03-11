#include <iostream>

int fib(int n)
{
  if (n <= 0)
    return 0;
  else if (n == 1)
    return 1;
  return fib(n - 1) + fib(n - 2);
}

int main()
{
  for (int i = -1; i < 10; i++)
  {
    std::cout << fib(i) << std::endl;
  }
}