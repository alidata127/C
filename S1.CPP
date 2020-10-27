// Written By Ali Reza Baghlocheloei
// First Written 1384/11/1
//   Last Update 1387/5/5

#include<stdio.h>
#include<string.h>

int dmtopc(int );

int  main(int argc,char* argv[])
{
  FILE * f1;
  FILE * f2;
  char * fn1,*fn2,*temp, *city, *hoz ;
  char ins,c;
  char s1[1658];//,s2[132]; 6*256+122
  int i,j,k,flag,flag2;
  long g;

  g=0;
  printf ("Usage : c  [input file] [output file] \n");

//  if (argc<2)	// seperation character
//    ins='2';
//  else
//    ins=argv[1][0];

  if( argc<2)  	//input file name
    fn1="s68.txt";
  else
    fn1=argv[1];

  if( argc<3  )  //output file name
    {
      if (strlen(fn1)>4){
	strxfrm(temp,fn1,strlen(fn1)-4);
	fn2=temp;
      }
      else
	fn2=fn1;
    }
  else
    fn2=argv[2];

  if ((f1 = fopen(fn1, "r"))== NULL)
    {
      printf( "Cannot open input file.\n");
      return 1;
    }
      /*
if (( f2= fopen(fn2, "w"))
    == NULL)
    {
      printf( "Cannot open output file.\n");
      return 1;
    }
	*/
  s1[0]='\0';
//  s2[0]='\0';
  g=0;

    for(i=0;i<801;i++)		//3*256+33
      s1[i]=c=fgetc(f1);//  c=fgetc(f1);
    s1[++i]=hoz[0]=fgetc(f1);
    s1[++i]=hoz[1]=fgetc(f1);
    hoz[2]='\0';


  for(;i<1658;i++)
    s1[i]=c=fgetc(f1);//  c=fgetc(f1);
  s1[++i]=city[0]=fgetc(f1);
  s1[++i]=city[1]=fgetc(f1);
  city[2]='\0';

  if (( f2= fopen(fn2+t2, "w"))
    == NULL)
    {
      printf( "Cannot open output file.\n");
      return 1;
    }


  flag2=0;
  while (!feof(f1))
    {
      flag=1;
      k=0;
      if(flag2)
	{
	  k=1;
	  flag2=0;
	for(i=k;i<2112;i++)	//end of city   2640
	  c=fgetc(f1);
	  k=0;
	}
//      for(j=0;j<5;j++)
	for(i=k;i<1320;i++)	//page header  1320
	  c=fgetc(f1);
      for(j=0;j<25;j++)
	{
	  s1[0]=c=fgetc(f1);
	  if(c=='1')	// end of page
	    {
	      flag2=2;
	      break;
	    }
	  flag=1;
	  g++;
	  for(i=1;i<528;i++)
	{
	  s1[i]=c=fgetc(f1);
	  if(i==390)//82)//126)//382)
	    if(c=='(')
	      flag=0;
	}
      if(flag)
	{
	  s1[i]='\0';
	  fprintf(f2,"%s",s1);
	  flag=1;
	}
       if(flag2)
	break;
	}
    }

   printf("\n %ld record of File %s converted to %s \n ",g,fn1,fn2);
   fcloseall();
   return 0;
}