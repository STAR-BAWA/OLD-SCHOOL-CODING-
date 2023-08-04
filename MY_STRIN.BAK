/*
1) str_count(char str[50])-->returns no. of char.
2) str_compare(char str1[50],char str2[50])-->returns diff. b/w ASCII values of 2 strings
*/

//1)to count no. of characters in string
int str_count(char str[50])
{
  int count=0,i=0;
  while(str[i]!=NULL)
  {
     count++;
     i++;
  }
  return count;
}
//2)to return diff. b/w 2 strings on the basis of their ASCII values
int str_cmpare(char str1[50],char str2[50])
{
  int i=0,j=0,sum1=0,sum2=0;
  for(;i<str_count(str1)||j<str_count(str2);i++,j++)
  {
    sum1+=(int)str1[i];
    sum2+=(int)str2[j];
  }
  return sum1-sum2;
}