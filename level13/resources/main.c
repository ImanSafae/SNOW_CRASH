#include <stdio.h>
#include <string.h>

char str[] = "0123456";

char *ft_des(char *s)
{
	unsigned int i;	 // [esp+2Ch] [ebp-1Ch]
	int v3;			 // [esp+30h] [ebp-18h]
	int j;			 // [esp+34h] [ebp-14h]
	int k;			 // [esp+38h] [ebp-10h]
	char *v6;		 // [esp+3Ch] [ebp-Ch]

	v6 = strdup(s);
	v3 = 0;
	for (i = 0; strlen(v6) > i; ++i) {
		if (v3 == 6)
			v3 = 0;
		if ((i & 1) != 0) {
			for (j = 0; *(char *)(v3 + str) > j; ++j) {
				if (++v6[i] == 127)
					v6[i] = 32;
			}
		} else {
			for (k = 0; *(char *)(v3 + str) > k; ++k) {
				if (--v6[i] == 31)
					v6[i] = 126;
			}
		}
		++v3;
	}
	return v6;
}

int main()
{
	printf("token: %s\n", ft_des("g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|"));
	return 0;
}
