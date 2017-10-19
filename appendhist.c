//Name: Abraham Yesgat
//  main.c
//student #: 260740998
//  Created by Abraham Yesgat on 2016-09-21.
//  Copyright © 2016 Abraham Yesgat. All rights reserved.
/*This code takes in a string on command line and concatenates every argument in the String while displaying a histogram for every distinct character in the string from scrath*/



#include <stdio.h>
#include <stdlib.h>

void append (char*out, char*in);
void toString (int argc,char*argv[],char*buffer);
int doHist (char buffer[], char hist[]);
void displayHist(char hist[],int distinct_chars);

int main(int argc, char*argv[]) {
   
char buffer[100]= "";
toString(argc,argv,buffer);

char hist[256]="";
int distinct_chars;
    
    distinct_chars=doHist(buffer, hist);
    displayHist(hist, distinct_chars);
    return 0;
}


void toString(int argc,char *argv[],char buffer[])
{
    int i;                                                // variable for the forloop
    for (i=1; i<argc; i++){
        append(buffer, argv[i]);
    }
    printf("%s\n",buffer);
}



void append(char out[], char in[])
{
    int i = 0,last = 0;  // start going through the out until the end of out
    while (out[last]!='\0')//increment until we reach the end of out
        last++;
    
    while (in[i]!='\0')
    {
           out[last+i]=in[i]; //we are adding in to out and going through all the "terms of in"
            i++;                //we increment the i until it ends
    }
   out[last+i]='\0';            // we add the null space that is at the end of every string
}



int doHist(char buffer[], char hist[]) {
    int i=0, k=0;
    for (i=0; i<256; i++)/* makes Each entry in array 0*/
    hist[i]=0;
    i=0;
    while(buffer[i]!='\0') /* run through the string count */
        hist[buffer[i++]]++;
    for (i=0;i<256;i++)
        if (hist[i]!=0) /* counts number of characters in string */
            k++;
    return k;
}

void displayHist(char hist[],int distinct_chars)
{
    int i,barlength;
  
    int MAXSCALE=25;
    int max = 0;
    for (i=0;i<256;i++)
        if ((hist[i])>max)
            max=hist[i];
    printf("%d distinct characters found", distinct_chars);
    printf("\n");
    for (i=0;i<256;i++)
    {
        if (hist[i]!= 0)
        {
        printf("[%c] %d ", i, hist[i]);
        barlength=(int)(((double)hist[i])/((double)max)*((double)MAXSCALE));
        int k;
        for (k=0;k<=barlength;k++)
        printf("*");
        printf("\n");
        }
    
    }
    
                
        
    
    return;
                    }
