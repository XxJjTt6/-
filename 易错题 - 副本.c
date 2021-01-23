#define _CRT_SECURE_NO_WARNINGS   1
#include <stdio.h>
int main()
{
	int arr[] = { 1, 2, (3, 4), 5 };
	printf("%d\n", sizeof(arr));//计算的是arr数组所占的空间大小
	return 0;
}

#include <stdio.h>
int main()
{
	char str[] = "hello bit";
	printf("%d %d\n", sizeof(str), strlen(str));
	return 0;
} /*str字符数组使用"hello bit"初始化，最终也会将'\0'放置到数组中，因此数组中总共有10个元素

sizeof(str)：获取数组的总大小，10个元素，每个元素占1个字节，因此总共是10个字节

strlen(str) : 获取字符串中有效字符的个数，不算'\0'，因此总共9个有效字符

故上述printf会分别打印：10  9*/