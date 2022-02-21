#define _CRT_SECURE_NO_WARNINGS 
//顺序表静态分配
#define MaxSize 10
typedef struct {//声明一个顺序表
	ElemType data[MaxSize];   //ElemType数据类型 
	int length;
};SqList;

void InitList(SqList &L) {//初始化一个顺序表
	for (int i = 0;i < MaxSize;i++) {
		L.data[i] = 0;
		L.length = 0;
	}
}
int main() {
	SqList L;//声明一个顺序表
	InitList(L);//初始化一个顺序表
	return 0;
}

//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------


//顺序表动态分配
#include <stdlib.h>
#define MaxSize 10      //顺序表初始长度
typedef struct {       //声明一个顺序表
	ElemType *data;   //指示动态分配数组的指针
	int MaxSize       //顺序表的最大容量
	int length;      //顺序表的类型定义
};SqList;

int main() {
	SqList L;//声明一个顺序表
	InitList(L);//初始化一个顺序表
	IncreaseSize(L, 5); //增加动态数组的长度
	return 0;
}
void IntiList(SeqList& L) {
//用malloc 函数申请一片连续的存储空间
	L.data = （int * ）malloc(InitSize * sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
	//增加动态数组的长度
	void IncreaseSize(SeqList &L,int len) {// len 为增加的长度
		int* p = L.data;
		L.data = (int*)malloc((L.MaxSize + len) * sizeof(inr));
		for (int i = 0;i > L.length;i++) {
			L.data[i] = o[i]; //将数据复制到新区域
		}
		L.MaxSize = L.MaxSize + len;
		free(p);//释放原来的内存空间
		p = NULL;
	}
}



//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------



//顺序表的删除
#define MaxSize 10      //顺序表初始长度
typedef struct {       //声明一个顺序表
	ElemType* data;   //指示动态分配数组的指针
	int MaxSize       //顺序表的最大容量
		int length;      //顺序表的类型定义
};SqList;
bool ListDelete(SqList* L, int i, int* e) {
	if (i<1 || i>L.length)
		return false;
	e = L.data[i - 1];
	if (int j = i;j < L.length;j++))
	L.data[j - 1] = L.data[j];
	L.length--;
	return true;

}
int main() {
	SqList;
	InitList(L);
	int e = 0;
	if (ListDelete(L, 3, e))
		printf("已删除第三个元素，值为%d", e);
	else
		printf("位序不合法，删除失败\n")；
	return 0;
}




//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------


//顺序表查找
typedef struct {
	int* data;  //指示动态分配数组的指针
	int MaxSize; //顺序表的最大容量
	int length; //顺序表的当前长度

};SeqList；
int LocateElem(SeqList L, int e) {
	for (int i = 0;i < L.length;i++)
		if (L.data[i] == e)
			return i + 1;
	return 0;
}