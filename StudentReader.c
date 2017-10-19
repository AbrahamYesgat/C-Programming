/*
 260740998-Abraham Yesgat
 This program assumes that
 a names and IDs data file (location and name) is passed as the first argument
 a marks data files is passed as the second argument
 an ID number is passed as the third argument
 */


#define NUMRECORDS 50
#define MAXNAMELENGTH 15
#include <stdio.h>
#include <stdlib.h>


//Define structure to hold student data
struct StudentRecord
{
    char FirstNames[MAXNAMELENGTH];
    char LastNames[MAXNAMELENGTH];
    int IDNums;
    int Marks;
};

void swap(struct StudentRecord *x, struct StudentRecord *y);
void quicksort(unsigned int left , unsigned int right,struct StudentRecord SRecords[NUMRECORDS]);
int search(int val, int left, int right, struct StudentRecord SRecords[]);


int main(int argc, char * argv[]) {
    
    struct StudentRecord SRecords[NUMRECORDS];
    int recordnum;
    //Read in Names and ID data
    FILE * NamesIDsDataFile;
    if((NamesIDsDataFile = fopen(argv[1], "r")) == NULL){
        printf("Can't read from file %s\n", argv[1]);
        exit(1);
    }
    for (recordnum=0;recordnum<NUMRECORDS;recordnum++){
        fscanf (NamesIDsDataFile, "%s%s%d", &(SRecords[recordnum].FirstNames[0]),&(SRecords[recordnum].LastNames[0]),&(SRecords[recordnum].IDNums));
    }
    fclose(NamesIDsDataFile);
    
    //Read in marks data
    FILE * MarksDataFile;
    if((MarksDataFile = fopen(argv[2], "r")) == NULL){
        printf("Can't read from file %s\n", argv[2]);
        exit(1);
    }
    for (recordnum=0;recordnum<NUMRECORDS;recordnum++){
        fscanf (MarksDataFile, "%d", &(SRecords[recordnum].Marks));
    }
    fclose(MarksDataFile);
    
    //Print out data as read in
    for(recordnum=0;recordnum<NUMRECORDS;recordnum++){
        printf("%s %s %d %d\n",SRecords[recordnum].FirstNames,SRecords[recordnum].LastNames,SRecords[recordnum].IDNums, SRecords[recordnum].Marks);
    }
    
    printf("\n\nRecords sorted by ID\n");
    quicksort(0,49,SRecords); /* sorting ID number the array of results*/
    for(recordnum=0;recordnum<NUMRECORDS;recordnum++)
        printf("%s %s %d %d\n",SRecords[recordnum].FirstNames,SRecords[recordnum].LastNames,SRecords[recordnum].IDNums, SRecords[recordnum].Marks);
    /*printing the sorted list*/
    
    //search segment
    int number= atoi(argv[3]); /*assigning an int value to argv[3] (student number) inputted*/
    recordnum=search(number, 0, 50,SRecords); /*calling the search function with 50 as                       upper bound*/
   if (recordnum>=0)
    printf("\n\nID: %d Student: %s,%s: %d\n",number,SRecords[recordnum].LastNames,SRecords[recordnum].FirstNames,SRecords[recordnum].Marks);
    else /* i.e when the recordnum returns value of -1*/
    printf("\nID:%d does not exist\n\n",number);
    
    return EXIT_SUCCESS;
}




void swap(struct StudentRecord *x, struct StudentRecord *y)
{
    struct StudentRecord temp=*x;
    *x = *y;
    *y = temp;
}


void quicksort(unsigned int left , unsigned int right,struct StudentRecord SRecords[]){
    unsigned int i, mid;
    int pivot;
    if (left>= right)
        return ; //nothing  to  sort
    swap(SRecords+left,SRecords+((left+right)/2)); //pivot  is  midpoint;  move  to  IDNums  side
    pivot=SRecords[mid=left].IDNums;
    //separate  into  side  <  pivot  ( IDNums+1  to  mid) and  side  >=  pivot  (mid+1  to  Marks )
    for (i=left+1;i<=right;i++)
        if (SRecords[i].IDNums< pivot)
            swap (SRecords + ++mid,SRecords+i);
    //restore  pivot  position
    swap(SRecords+left,SRecords+mid);
    //sort  two  sides
    if (mid>left)
        quicksort(left,mid-1,SRecords);
    if (mid<right)
        quicksort(mid+1,right,SRecords);
    
    
}

int search(int val, int left, int right, struct StudentRecord SRecords[])  {
    int M;
    while (left<right){
        M =(left+right-1)/2;
        if (val == SRecords[M].IDNums)
            return M;/*found*/
        else if (val<SRecords[M].IDNums)
            right = M;  /*in  first  half  */
        else
            left = M+1;/*in second half */
    }
    return -1; /*not Found*/
    
}
