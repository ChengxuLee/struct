#define _CRT_SECURE_NO_WARNINGS 
//˳���̬����
#define MaxSize 10
typedef struct {//����һ��˳���
	ElemType data[MaxSize];   //ElemType�������� 
	int length;
};SqList;

void InitList(SqList &L) {//��ʼ��һ��˳���
	for (int i = 0;i < MaxSize;i++) {
		L.data[i] = 0;
		L.length = 0;
	}
}
int main() {
	SqList L;//����һ��˳���
	InitList(L);//��ʼ��һ��˳���
	return 0;
}

//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------


//˳���̬����
#include <stdlib.h>
#define MaxSize 10      //˳����ʼ����
typedef struct {       //����һ��˳���
	ElemType *data;   //ָʾ��̬���������ָ��
	int MaxSize       //˳�����������
	int length;      //˳�������Ͷ���
};SqList;

int main() {
	SqList L;//����һ��˳���
	InitList(L);//��ʼ��һ��˳���
	IncreaseSize(L, 5); //���Ӷ�̬����ĳ���
	return 0;
}
void IntiList(SeqList& L) {
//��malloc ��������һƬ�����Ĵ洢�ռ�
	L.data = ��int * ��malloc(InitSize * sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
	//���Ӷ�̬����ĳ���
	void IncreaseSize(SeqList &L,int len) {// len Ϊ���ӵĳ���
		int* p = L.data;
		L.data = (int*)malloc((L.MaxSize + len) * sizeof(inr));
		for (int i = 0;i > L.length;i++) {
			L.data[i] = o[i]; //�����ݸ��Ƶ�������
		}
		L.MaxSize = L.MaxSize + len;
		free(p);//�ͷ�ԭ�����ڴ�ռ�
		p = NULL;
	}
}



//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------



//˳����ɾ��
#define MaxSize 10      //˳����ʼ����
typedef struct {       //����һ��˳���
	ElemType* data;   //ָʾ��̬���������ָ��
	int MaxSize       //˳�����������
		int length;      //˳�������Ͷ���
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
		printf("��ɾ��������Ԫ�أ�ֵΪ%d", e);
	else
		printf("λ�򲻺Ϸ���ɾ��ʧ��\n")��
	return 0;
}




//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------


//˳������
typedef struct {
	int* data;  //ָʾ��̬���������ָ��
	int MaxSize; //˳�����������
	int length; //˳���ĵ�ǰ����

};SeqList��
int LocateElem(SeqList L, int e) {
	for (int i = 0;i < L.length;i++)
		if (L.data[i] == e)
			return i + 1;
	return 0;
}