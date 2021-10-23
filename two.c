#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int twopows[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};

int isHyperEven(int n)
{
  int canAdd = 0, canSplit = 0, i, j, y, z;
  for(i = 0; i<17; i++)
    for(j = 0; j<i; j++)
    {
      if(n + twopows[j] == twopows[i]) canAdd = 1;
    }
  if(!canAdd) return 0;
  for(i = 0; i<17; i++)
    for(j = 0; j<17; j++)
      for(z = 0; z<=3; z++)
      {
        char si[15], sj[15], sn[15];
        sprintf(si, "%d", twopows[i]);
        sprintf(sj, "%d", twopows[j]);
        sprintf(sn, "%d", n);
        char* s = si;
        for(y = 0; y<z; y++) s = strcat(s, "0");
        s = strcat(s, sj);
        if(!strcmp(sn, s)) canSplit = 1;
      }
  return canSplit;
}

int main()
{
  int T, t, i, j, n;
  scanf("%d", &T);
  for(t = 1; t<=T; t++)
  {
    scanf("%d", &n);
    int res = n+1;
    while(res <= 64512)
    {
      if(isHyperEven(res)) break;
      res++;
    }
    printf("The next hyper-even after %d is %d\n", n, res);
  }
  return 0;
}
