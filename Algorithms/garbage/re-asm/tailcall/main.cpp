int fibonacci(int n, int res, int next)
{
  if (n == 0)
    return res;
  return fibonacci(n - 1, next, res + next);
};

int main(void)
{
	fibonacci(10,0,1);
	return 0;
};