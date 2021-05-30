# Experiment Report 2
## Task 1
1. gcc
2. 
```
$(CC) $(CFLAGS) $(LIBS) -o btest bits.c btest.c decl.c tests.c
```
3. 
```
rm -f *.o btest fshow ishow *~
```
4. Line 11
5. Line 14
6. 

## Task 2

### Running Result

### Source Code
```
int allOddBits(int x) {

   int mask=0xAA;
   mask=(mask<<8)+mask;
   mask=(mask<<16)+mask;
   return !((x&(mask))^mask);
   
}
```

```
int isLessOrEqual(int x, int y) {

   int mask=1<<31;

   int diffsign1=(x&~y)&mask; //return 1 iff x<0 and y>=0

   int diffsign0=(y&~x)&mask;
   
   int SameNumber=x^y;
   
   int xy = x+(~y+1);
   
   xy=(xy&mask)|(!xy);

   return (!!(diffsign1 | !SameNumber |( (!!xy) )))&(!diffsign0);
}
```

```
int logicalNeg(int x) {
  return ((x|(~x+1))>>31)+1;
}
```

```
unsigned floatScale2(unsigned uf) {
//your codes here

   unsigned int sign=uf&0x80000000;
   unsigned int exp=uf&0x7F800000;
   unsigned int frac=uf&0x007fffff;
   
   if(exp==0x7f800000) 
      return uf; // positive infinity or Nan
   if(exp==0&&frac!=0)
      return sign+exp+(frac<<1);
   if(exp!=0)
      return sign+exp+0x00800000+frac;
   return uf;
}
```

```
int floatFloat2Int(unsigned uf) {

   unsigned int sign=uf&0x80000000;
   unsigned int exp=uf&0x7f800000;
   unsigned int frac=uf&0x007fffff;
   unsigned int result = frac|0x00800000;
   int sameSign;

   if( (!(uf&0x7fffffff)) ||exp < 0x3f800000)
      return 0;
   if(exp>0x4f000000)
      {return 0x80000000;}

   if(((exp>>23)>=150))
      result=result <<((exp>>23)-150);
   else
      result=result >>(150-(exp>>23));

   sameSign=sign^(result&0x80000000);

   if(!sameSign)
      return result;
   else if(!(result>>31))
      return (~result+1);
   else 
      return 0x80000000;
}
```
