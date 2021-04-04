#include "sfp.h"
#include <stdlib.h>
sfp int2sfp(int input){
	int sfpmax=(2<<16)-32;
    int sfpmin=-((2<<16)-32);
	sfp x;
	if(input>sfpmax)
	{
		x = sfpmax;
	}
	else if(x<sfpmin)
	{
		x = sfpmin;
	}
	else
	{
		x = (sfp) input;
	}
return x;
}

int sfp2int(sfp input){
}

sfp float2sfp(float input){
}

float sfp2float(sfp input){
}

sfp sfp_add(sfp a, sfp b){
	
}

sfp sfp_mul(sfp a, sfp b){
	
}

char* sfp2bits(sfp result){
  int c, k, k2;
  int m=0;
  int w=0;
  int Exp;
  int r=0;
  
  int array[11];
  int array1[16];
  int array2[5];
  int array3[10];
  if(result == 0000000000000000)
  {
  	for(m;m<15;m++)
  	{
  		array1[m]=0;
	  }
  }
  else{ 
  	if(result > 0)
	  {
	  	array1[0]=0;
	   } 
	else{
		array1[0]=1;
	}
  	
  
  for (c = 10; c >= 0; c--)
  {
    k = result >> c;

    if (k & 1){
	
      array[10-c]=1;
    }
    else{
      array[10-c]=0;
	}
    
  }
  	if(array[0]!=0)
  	{
  		for(c=1;c<11;c++)
  		{
  			 array3[w]=array[c]; 
  			w++;
		  }
  		Exp=25;
  	}
  	else{
  		while(array[m]==0)
  	{
  		m++;
  	}
  	c=m+1;
  	for(c;c<=10;c++)
  	{
  		array3[w]=array[c];
  		w++;
	  }
  	for(w;w<10;w++)
  	{
  		array3[w]=0;
	  }
  	
    }
    
  Exp = 25 - m;
  for (c = 4; c >= 0; c--)
  {
    k2 = Exp >> c;

    if (k2 & 1){
	
      array2[5-c]=1;
    }
    else{
      array2[5-c]=0;
	}
  }
  for(c=1;c<=5;c++)
  {
  	array1[c]= array2[c];
  }
  for(c=6;c<=15;c++)
  {
  	array1[c]=array3[c-6];
  }

  
}
char* arraysfp = (char*)malloc(sizeof(char)*17);
for(c=0;c<=15;c++)
{
	arraysfp[c]=array1[c]+'0';
}
  arraysfp[16] = '\0';
  return arraysfp;
}


