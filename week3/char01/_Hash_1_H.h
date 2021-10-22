#include<stdio.h>
#include<stdlib.h>

//��Ҫ�����ṹ�壬һ����ɢ��ֵ����һ��������ɢ��ֵ��Ӧ��Ԫ�أ�������
struct HashTable;
struct ListNode;

typedef struct ListNode *Position;
typedef Position List; 
typedef struct HashTable *HashTbl; 
typedef int ElemType; 
typedef char *Key;

struct HashTable{
	int TableSize;
	List *TheList; 
};

struct ListNode{
	Key Elem;
	List Next;
};

HashTbl Init(int TableSize);
void DestoryTable(HashTbl H);
Position Find(Key X, HashTbl H);
void Insert(Key X, HashTbl H);

int Hash(char *X,int TableSize){
	unsigned int HashVal;
    while(*X != '\0')
        HashVal = (HashVal << 5) + *X++;
    return HashVal % TableSize;
}

