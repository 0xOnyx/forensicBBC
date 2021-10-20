
#include <stdio.h>
#include <stdlib.h>

int lengthWithNoSpace(int *str)
{
  int res;
  int i;

  res = 0;
  i = 0;
  
  while(str[i] != '\0')
  {
    if(str[i] != 32)
      res++;
    i++;
  }

  return res;
}

int length_str(char *str)
{   
  int i;
  i = 0;

  while(str[i] != '\0')
    i++;

  return i;
}


int convert_to_int(char *str, int **array)
{
  int length;
  length = length_str(str);

  int *res;
  res = (int *)malloc(sizeof(int) * length);

  int i;
  i = 0;
  while( str[i] != '\0')
  {
    res[i] = str[i] - 96; 
    i++;
  }

  *array = res; 
  
  return length;

}

void print_res_white_zero(int *res, int length)
{
  int i;

  i = 0;

  while(i < (length -1 ))
  {

    printf("%.2d - ", res[i]);

    i++;

  }
  printf("%.2d\n", res[i]);
}


char *rot13(char *str)
{
  int length;
  length = length_str(str);

  int i;
  i = 0;

  while(i < length)
  {
    if( str[i] > 109)
      str[i] -= 13;
    else 
      str[i] += 13;

    i++;
  }
  return str;
}

int main(int argc, char **argv)
{

  int *res;
  char *cipher;
  int length;

  cipher = rot13(argv[1]);
  printf("rot13=> %s\n", cipher);

  length = convert_to_int(cipher, &res);

  print_res_white_zero(res, length);

  return 0;
}
