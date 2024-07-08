#ifndef _LAB12_H
#define _LAB12_H


// Data types
typedef struct _Heap Heap;
typedef Heap * PHeap;
struct _Employee
{
	char fname[256];
	char mname[256];
	char lname[256];
	char tshirtsize;
};
typedef struct _Employee Employee;


// Prototypes
PHeap HeapConstruct();
int HeapInsert(PHeap heap, int key, void * inputData);
int HeapDelete(PHeap heap, void ** outputData);
void HeapDestruct(PHeap heap);
void PrintHeap(PHeap heap);

#endif