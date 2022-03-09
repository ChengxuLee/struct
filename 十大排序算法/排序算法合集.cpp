#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//void bubbleSort(int arr[],int len) {//从大到小 
//	for (int i = 0;i < len-1;i++) {
//		for (int k = 0;k < len - 1 - i;k++) {
//			if (arr[k]<arr[k+1]) {
//				int tmp = arr[k];
//				arr[k] = arr[k + 1];
//				arr[k + 1] = tmp;
//			}
//		}	
//	}	
//}
// 
// //选择排序
//void selectSort(int arr[], int len) {
//	//在所有数中寻找最大/最小的元素 与第i位进行交换
//	int min = 0;
//	for (int i = 0;i < len - 1;i++) {
//		min = i;//每次交换完进行重置
//		for (int k = i;k < len;k++) { //k从第i项继续开始 因为i之前已经排过序了
//			if (arr[k] < arr[min]) {
//				min = k;
//			}
//		}
//		if (arr[min]<arr[i]) {
//			int tmp = arr[min];
//			arr[min] = arr[i];
//			arr[i] = tmp;
//		}
//	}
//
//}

//快速排序
//void QuickSort(int arr[], int low, int high) {
//	int i = low, j = high;
//	if (i >= j) return;
//	int tmp = arr[low];
//	while (i<j) {
//		while (arr[j]>=tmp&&i<j) {
//			j--;
//		}
//		while (arr[i] <= tmp && i < j) {
//			i++;
//		}
//		if (i < j) {
//			swap(arr[i], arr[j]);
//		}
//	}
//	swap(arr[low], arr[i]);
//	QuickSort(arr, low, i - 1);
//	QuickSort(arr,i+1,high);
//}


//插入排序
//void insertSort(int arr[], int len) {
//	for (int i = 1;i < len - 1;i++) {
//		int tmp = arr[i]; //存下 i的数 后面会被覆盖
//		int j = i - 1;
//		for (j;j >= 0 && arr[j] > tmp;j--) {//与要插入的值进行比较 
//			arr[j + 1] = arr[j];   //大于要插入的值则向后移动 再与前面的值比
//	}
//		arr[j + 1] = tmp;//这个值小于插入的值 则 插入
//	}
//}


//归并排序
//void merge(int arr[],int newarr[],int left,int right,int mid) {
//		//定义新数组的头，原左数组头，原右数组头
//	int pos_l = left, pos_r = mid+1, pos = left;
//	while (pos_l<=mid&&pos_r<=right) {
//		if (arr[pos_l]<=arr[pos_r]) {
//			newarr[pos++] = arr[pos_l++];
//		}
//		else {
//			newarr[pos++] = arr[pos_r++];
//		}
//	}
//	while (pos_l <= mid) {
//		newarr[pos++] = arr[pos_l++];
//	}
//	while (pos_r <= right) {
//		newarr[pos++] = arr[pos_r++];
//	}
//
//	while (left<= right) {
//		arr[left] = newarr[left];
//		left++;
//	}
//}
//void divide(int arr[], int  newarr[], int left, int right) {//分治
//	if (left<right) {
//		int mid = (left + right) / 2;
//		divide(arr, newarr, left, mid);//递归左区间
//		divide(arr, newarr, mid + 1, right);//递归又区间
//		merge(arr, newarr, left,right,mid);//归并
//	}
//};
//void mergeSort(int arr[],int len) {//归并排序入口
//
//	int left = 0, right = len - 1;
//	int* newarr = new int[len];
//	divide(arr,newarr,left,right);
//
//}
int main() {
	int arr[8] = { 45,8,12,6,4,8,9,45 };
	int len = sizeof(arr) / sizeof(arr[0]);
	/*bubbleSort(arr,len);*/
	/*selectSort(arr, len);*/
  /*  QuickSort(arr,0,7);*/
	//insertSort(arr,8);
	/*mergeSort(arr, 8);*/
	for (int i = 0;i < len;i++) {
		cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}