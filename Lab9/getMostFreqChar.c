# include <stdio.h>
# include <stdlib.h>

/*

Lab #: 9
Name: Sriram Mohan
*/

int main(int argc, char* argv[]) {
    FILE *fp = fopen(argv[argc-1], "r");

    char buff[255], result = "";
    int count[26] = { 0 };
    char ch[26] = "abcdefghijklmnopqrstuvwxyz";
    int i = 0,j=0, max = 0;
    char c = buff[i],b="";

    while((c=fgetc(fp))!=EOF){
    i=0;
    fgets(buff, 255, (FILE*)fp);
    while(c!='\0'){
      c = buff[i];

      if (c <= 'z' && c >= 'a')
       count[c - 'a']++;

      else if (c <= 'Z' && c >= 'A')
       count[c - 'A']++;
     
      i++;
     }
    i++;
    c=buff[i];
   }

   for (int j = 0; j < 26; j++)
   {
        if (count[j] > max)
        {
            max = count[j];
            result = ch[j];
        }
    }

    printf("The most frequent letter is '%c'. It appeared %d times \n\n", result, max);
    fclose(fp);
    return 0;
 }
