#include <stdio.h>
int main(void)
{
  int count, n, t1=0, t2=1, display=0;
  printf("������쳲�������������: ");
  scanf("%d",&n);
  printf("쳲���������Ϊ: %d>%d>", t1, t2); 
  count=2;
  while (count<n)  
  {
      display=t1+t2;
      t1=t2;
      t2=display;
      ++count;
      printf("%3d>",display);
  }
  printf ("\n");
  return 0;
}