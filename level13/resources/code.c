#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char * ft_des(char *param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  char bVar5;
  unsigned int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  bVar5 = 0;
  pcVar2 = strdup(param_1);
  local_1c = 0;
  local_20 = 0;
  do {
    uVar3 = 0xffffffff;
    pcVar4 = pcVar2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + (uint)bVar5 * -2 + 1;
    } while (cVar1 != '\0');
    if (~uVar3 - 1 <= local_20) {
      return pcVar2;
    }
    if (local_1c == 6) {
      local_1c = 0;
    }
    if ((local_20 & 1) == 0) {
      if ((local_20 & 1) == 0) {
        for (local_14 = 0; local_14 < "0123456"[local_1c]; local_14 = local_14 + 1) {
          pcVar2[local_20] = pcVar2[local_20] + -1;
          if (pcVar2[local_20] == '\x1f') {
            pcVar2[local_20] = '~';
          }
        }
      }
    }
    else {
      for (local_18 = 0; local_18 < "0123456"[local_1c]; local_18 = local_18 + 1) {
        pcVar2[local_20] = pcVar2[local_20] + '\x01';
        if (pcVar2[local_20] == '\x7f') {
          pcVar2[local_20] = ' ';
        }
      }
    }
    local_20 = local_20 + 1;
    local_1c = local_1c + 1;
  } while(1);
}



int main(void)
{
  char *uVar2;
  
  uVar2 = ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I");
  printf("your token is %s\n",uVar2);
  return 0;
}

/*char *ft_des(char *s)
{
  unsigned int i; // [esp+2Ch] [ebp-1Ch]
  int v3; // [esp+30h] [ebp-18h]
  int j; // [esp+34h] [ebp-14h]
  int k; // [esp+38h] [ebp-10h]
  char *v6; // [esp+3Ch] [ebp-Ch]

  v6 = strdup(s);
  v3 = 0;
  for ( i = 0; strlen(v6) > i; ++i )
  {
    if ( v3 == 6 )
      v3 = 0;
    if ( (i & 1) != 0 )
    {
      for ( j = 0; *(char *)(v3 + 134514368) > j; ++j )
      {
        if ( ++v6[i] == 127 )
          v6[i] = 32;
      }
    }
    else
    {
      for ( k = 0; *(char *)(v3 + 134514368) > k; ++k )
      {
        if ( --v6[i] == 31 )
          v6[i] = 126;
      }
    }
    ++v3;
  }
  return v6;
}


int main() {
  char *v4 = ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I");
  printf("%s\n", v4);
  return 0;
}*/
