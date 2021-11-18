#include <search.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
         int key;
               char* value;
} IntegerStringMap;

int compar(const void *l, const void *r)
{
   const IntegerStringMap *lm = l;
   const IntegerStringMap *lr = r;
   return lm->key - lr->key;
}

int main(int argc, char **argv)
{
   void *root = 0;

   IntegerStringMap *a = malloc(sizeof(IntegerStringMap));
   a->key = 2;
   a->value = strdup("two");
   tsearch(a, &root, compar); /* insert */

   IntegerStringMap *find_a = malloc(sizeof(IntegerStringMap));
   find_a->key = 2;

   void *r = tfind(find_a, &root, compar); /* read */
   printf("%s", (*(IntegerStringMap**)r)->value);

   return 0;
}
