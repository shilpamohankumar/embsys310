//address of variables x and y are swapped implicitely
void swap5( int** a, int** b) {
    int *temp = *a;             
    *a = *b;
    *b = temp;
    assert(**a == 2);
    assert(**b == 1);
    // they're swapped!
}

int main()
{
  int x = 1;
  int y = 2;
  int* xp = &x;
  int* yp = &y;
  swap5(&xp, &yp); //passing the address of pointer variables
  assert(xp == &y);
  assert(yp == &x);
  assert(x == 1);
  assert(y == 2);
  
  return 0;
}