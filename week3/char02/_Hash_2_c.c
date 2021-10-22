#include"_Hash_2_H.h"
int main(){
	HashTbl H;
	H = Init(100);
	Insert("wziyuu", H);;//Insert 函数和Find函数都会输出元素的地址 
	Insert("wzy", H);
	Find("wzy", H);
	Find("wziyuu", H);
	puts(H->TheCell[1].Elem);

	printf("Hash wzy：%d\n",Hash("wzy",100));

}

HashTbl Init(int TblSize){
	HashTbl H;
	H = malloc(sizeof(struct HashTable));
	H->TableSize = TblSize;
	H->TheCell = malloc(TblSize*sizeof(struct HashEntry));
	int i;
	for(i = 0; i < TblSize; i ++){
		H->TheCell[i].Info = Empty;
	}
	return H;
}

void Insert(Key K, HashTbl H){
    Position Tmp;
    Tmp = Find(K,H);
    if(H->TheCell[Tmp].Info != Legal){
        H->TheCell[Tmp].Elem = K;
        H->TheCell[Tmp].Info = Legal;
    }
    printf("Insert:%7s。Location:%d\n",K,Tmp);
}

Position Find(Key K, HashTbl H){
    Position TmpPos;
    int i= 0;//给后面的加平方使用 
    TmpPos = Hash(K,H->TableSize);
    while(H->TheCell[TmpPos].Info != Empty && H->TheCell->Elem != K){
        TmpPos = TmpPos + 2 * ++i + 1;
        if(TmpPos >= H->TableSize)
            TmpPos -= H->TableSize;
    } 
    return TmpPos;
}
