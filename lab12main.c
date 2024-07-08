#include <stdlib.h>
#include <stdio.h>
#include "lab12.h"

void PrintEmployee(Employee * p)
{
	if (p)
	{
		printf("\t%s %s %s (%c)\n",p->fname, p->mname, p->lname, p->tshirtsize);
	}
	else
	{
		printf("\tNULL pointer!\n");
	}
}

int main() 
{
	int array[] = { 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 };

	PHeap heap = HeapConstruct();

	for (int i=0;i<sizeof(array)/sizeof(array[0]); i++)
	{
		//printf("Inserting %d\n",array[i]);
		HeapInsert(heap, array[i],NULL);
		//PrintHeap(heap);
		//printf("\n\n");
	}

	//printf("\nHeap:\n");
	//PrintHeap(heap);
	//printf("\n\n");

	for (int i=0;i<sizeof(array)/sizeof(array[0]); i++)
	{
		void * temp;
		int key=HeapDelete(heap,&temp);
		printf("%d deleted\n",key);
	}

	HeapDestruct(heap);

	// Make sure we don't leak memory
	heap=HeapConstruct();
	HeapDestruct(heap);

	// Try adding something more interesting to the heap
	Employee employees[] =
	{
		{"George","W","Bush",'z'},
		{"James","Edward","Ries",'M'},
		{"Laura","Christine","Ries",'m'},
		{"Murphy","","Ries",'X'},
		{"Cisco","","Ries",'S'},
		{"James","AlternateDimension","Ries",'L'},
		{"James","EvilJimR","Ries",'X'},
		{"Lawrence","David","Ries",'x'},
		{"Paul","David","Polly",'L'},
		{"Alan","Jerome","Lammers",'X'},
		{"Earl","Daniel","Kraus",'l'},
		{"William","David","Moser",'X'},
		{"William","Jefferson","Clinton",'A'},
	};
	int count = sizeof(employees)/sizeof(employees[0]);
	heap=HeapConstruct();

	for (int i=0;i<count;i++)
	{
		HeapInsert(heap, count-i,&(employees[i]));
	}

	printf("\nEmployees should be in reverse order as we delete them:\n");
	for (int i=0;i<count; i++)
	{
		Employee * pEmp;
		HeapDelete(heap,(void *)&pEmp);
		PrintEmployee(pEmp);
	}

	HeapDestruct(heap);

	// Try a few NULL checks
	HeapInsert(NULL,0,NULL);
	HeapDelete(NULL,NULL);
	HeapDestruct(NULL);

}