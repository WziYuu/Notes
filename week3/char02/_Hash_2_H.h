#include<stdio.h>
#include<stdlib.h>

struct Hashtable;
struct HashEntry;

typedef struct HashTable *HashTbl;
typedef struct HashEntry Cell;
typedef int Position;
typedef int ElemType; 
typedef char *Key;

enum KindOfEntry{Legal,Empty,Deleted};

struct HashTable{
	int TableSize;
	Cell *TheCell;
};

struct HashEntry{
	Key Elem;
	enum KindOfEntry Info;
};

HashTbl Init(int TableSize);
void DestoryTable(HashTbl H);
Position Find(Key X, HashTbl H);
void Insert(Key X, HashTbl H);

ElemType Hash(char *X,int TableSize){
	unsigned int HashVal = 0;
    while(*X != '\0')
        HashVal = (HashVal) + *X++;
    return HashVal % TableSize;
}
