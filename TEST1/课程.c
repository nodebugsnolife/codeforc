#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>
#include <assert.h>
//��ݼ���ctrl + M + O �۵����д���� 

//P34 B30  �ַ�ָ��

//int main()
//{
//	char* p = "ABCDEF";//or const char* p = "ABCDEF"
//	*p = 'W';
//	printf("%s\n", p);
//	return 0;//������ΪABCDEF�ǳ����ַ����޷��޸�
//}

//P32 B29  ��float������ ���ڴ��еĴ洢��ʽ

//(-1)^S * M * 2^E
//S(1bit)  E(8bit)  M(23bit)     32λ�������洢ģ��
//S(1bit)  E(11bit) M(52bit)     64λ�������洢ģ��
//  ---    ------  ------------
// S�Ƿ���λ
// 2^E��ʾָ��λ��
// M��ʾ��Ч���֣����ڵ���1��С��2��
//Eg��5.0 ����> (-1)^0 * 1.01 * 2^2 ����>S=0 M=1.01 E=2
//
// **��
//�ر�涨��1���ڼ�����ڲ�����Mʱ��Ĭ�ϵ�һλ����1����˿��Ա���ȥ��ֻ��������0.xxxxxx����
//         2��EΪһ���޷���������Ϊ��֤�����������ڴ�ʱE����ʵֵȫ�������м���127��Eg��E=10+127
//         3��E��ȫ��0��1����ʵEֵ+127�����ڴ� �������洢Eֵ
//			  EȫΪ0��E=1-127����M���ټ�����λ1����ԭ�ӽ���0�ĺ�СС������
//            EȫΪ1�������Ч����MȫΪ0����ʾ�����������ȡ���ڷ���λs��

//P32 B28  char��������ѭ����-187����>127��

//int main()
//{   char a[1000];
//    int i;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));//255
//    return 0;
//}

//������������ӡ�������

//int main()
//{
//	char a = -128;
//	char b = 128;
//	printf("%u\n%u\n", a,b);
//	return 0;
//}
//1���������������ǰ������Ԫ������
//2��charΪ�з�����������
//3���Ƚض���������������char a = -128����ȡ����-128���룬�ٽضϺ�8λ������λ����a
//4����ӡprintfǰ��������Ҳ�ǲο�Ԫ�ر������ͣ��������ڴ��д洢�Ĳ�����Ϊ��ӡ��Ԫ�����ͣ����ӡ%u����ԭ����ڲ��룬ֱ�Ӵ�ӡ���뼴�ɡ�%d�����ԭ���ӡ


//���볣������

//    �����ʹ���
//ֱ�ӿ�������ʾ��Ϣ��˫������������⡣����ƾ�辭��Ϳ��Ը㶨�������˵�򵥡�
//    �����ʹ���
//��������ʾ��Ϣ����Ҫ�ڴ������ҵ�������Ϣ�еı�ʶ����Ȼ��λ�������ڡ�һ���Ǳ�ʶ����
//�����ڻ���ƴд����
//    ����ʱ����
//�������ԣ��𲽶�λ���⡣���Ѹ�


//д���õĴ���(strcpy,strlen����д)

//����assert������const���δ��������ѭ���Ż���

//strcpy:

//char* mystrcpy(char* dest, const char* sour)//constȷ��ԭ�ַ��������ı�
//{
//	assert(dest != NULL);
//	assert(sour != NULL);//ȷ��ָ����Ч�ԣ��ǿ�ָ��
//	char* ret = dest;//����dest�ַ������׵�ַ���Է���return��ַ
//
//	while (*dest++=*sour++)//���� �жϡ�/0�����ַ���ֵ���ַ����ƶ�����һ��Ԫ��
//	{
//		;
//	}	
//	return ret;
//}
//int main()
//{
//	char arr1[] = "#######";
//	char arr2[] = "bit";
//	printf("%s\n", mystrcpy(arr1, arr2));
//}

//����

//int main()
//{
//	int i = 0;
//	int sum = 0;
//	int n = 0;
//	int ret = 1;
//	scanf("%d", &n);
//	for (i = 0; i <= n; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= 1; j++)
//		{
//			ret *= j;
//		}
//		sum = +ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}


//�ַ���������

//int mylen(char *arr)
//{
//	int cou = 0;
//	while (*arr !='\0')
//	{
//		arr++;
//		cou++;
//	}
//	return cou;
//}
//void reverse(char* arr)
//{
//	char tmp = arr[0];
//	int len = mylen(arr);
//	arr[0] = arr[len - 1];
//	arr[len - 1] = '\0';
//	if(mylen(arr+1)>=2)
//	reverse(arr + 1);
//	arr[len - 1] = tmp;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse(arr);
//	printf("%s\n", arr);
//	return 0;
//}


//ָ��Ӽ�����

//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* p;
//	for (p = &a; p < &a[5];)
//	{
//		*p++ ;
//		printf("%d %d %d %d %d \n", a[0],a[1],a[2],a[3],a[4]);
//	}
//
//	return 0;
//}

//��ָͬ�����͵����÷�Χ��ͬint 4��char 1

//int main()
//{
//	int a = 0x11223344;
//	char* pc = &a;
//	*pc = 0;
//	printf("%d\n", a);
//	return 0;
//}

//�ṹ������

//struct stu
//{
//	char name[10];
//	int age;
//	char id[20];
//};
//int main()
//{
//	struct stu stu1 = { "johnwick",35,"20220721"};
//	printf("%s\n", stu1.name);
//	printf("%d\n", stu1.age);
//	printf("%s\n", stu1.id);
//
//	struct stu* ps = &stu1;
//	printf("%s\n", (*ps).name);
//	printf("%s\n", ps->name);
//	return 0;
//
//	//�ṹ�����.��Ա�� or �ṹ�����ָ��->��Ա��
//}

//���ű��ʽ

//while(exp1,.,expn)
//{
//......
//}

//�߼���

//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = a && b;
//	printf("%d\n", c);
//	return 0;
//}

//ǿ������ת�� (int)

// int a = (int)3.14;

//��������������ж��ٸ�1����ϰ��

//int main()
//{
//	int a = 0;
//	int count = 0;
//	scanf("%d", &a);
//	for (int i = 0; i < 32; i++)
//	{
//		int b = a & 1;
//		if (b == 1)
//			count++;
//		a = a >> 1;
//	}
//	printf("%d\n", count);
//}


//���������

//>> -> ���Ʋ��������ƶ����Ƕ�����λ��

//1.��������
// �ұ߶�������߲�ԭ����λ
//2.�߼�����
// �ұ߶�������߲�0
// 00000000000000000000000000000000
// |
// ����λ��ͨ�����������ƣ�

//>> <- ���Ʋ��������ƶ����Ƕ�����λ��

//1.��������
// ��߶�������߲�0



//��λ��

//00000000000000000000000000000011
//00000000000000000000000000000101
//00000000000000000000000000000001

//��λ��

//00000000000000000000000000000011
//00000000000000000000000000000101
//00000000000000000000000000000111

//��λ��� ��

//00000000000000000000000000000011
//00000000000000000000000000000101
//00000000000000000000000000000111

//�ð�λ���������2����


//����ҵ����дһ������, �����û��Ӽ���������ַ�, ���û�����س�ʱ��ʾȷ������, �ֱ�ͳ�������д��ĸ������Сд��ĸ������0 - 9�����ַ��������ո��ַ������Լ������ַ�������

//#include <stdio.h>
//int main()
//{
//    int letter = 0, majuscule = 0 , space = 0, digit = 0, others = 0;
//    char x;
//    scanf("%c", &x);
//    for (; (x = getchar()) != '\n';)
//    {
//        if (x >= 'a' && x <= 'z')
//            letter++;
//        else if (x >= 'A' && x <= 'Z')
//            majuscule++;
//        else if (x >= '0' && x <= '9')
//            digit++;
//        else if (x == ' ')
//            space++;
//        else
//            others++;
//    }
//    printf("Сд��ĸ������%d\n", letter);
//    printf("��д��ĸ������%d\n", majuscule);
//    printf("�ո��ַ�������%d\n", space);
//    printf("���ָ�����%d\n", digit);
//    printf("�����ַ�������%d\n", others);
//    return 0;
//}

//&����������������������������飬ȡ���ĵ�ַ����������ĵ�ַ

//int main()
//{
//	int arr[] = {1,2,3,4,5,6};
//	printf("%p\n", arr);    //������Ԫ�صĵ�ַ
//	printf("%p\n", arr+1);
//
//	printf("%p\n", &arr[0]);//������Ԫ�صĵ�ַ
//	printf("%p\n", &arr[0]+1);
//	
//	printf("%p\n", &arr);   //��������ĵ�ַ
//	printf("%p\n", &arr+1);//ֻ��sizeof(),&arr������������
//	
//}

//ð������

//�ӵ͵���

//void bubble_sort(int arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;//�����������ݲ���ȫ����
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//int main()
//{
//	int i = 0;
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr,sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//�������ڴ�����������ŵ�

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%p\n", &arr[i]);
//	}
//
//	return 0;//�������ڴ�����������ŵ�
//}

//쳲��������У��ݹ飩(Ч�ʵͣ��ظ�������

//int count = 0;
//int Fib1(int n)
//{
//	if (n == 3)
//	{
//		count++;
//	}
//	if (n <= 2)
//		return 1;
//	else
//		return Fib1(n - 1) + Fib2(n - 2);
//}
//int Fib2(int n) //��DIY��
//{
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	if (n == 1 || n == 2)
//		return 1;
//	else
//	{
//		int i = 0;
//		for (i = 3; i <= n; i++)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//		return c;
//	}
//}
//int Fib3(int n) //���ο���
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fib2(n);
//	printf("ret = %d\n", ret);
//	//printf("count = %d\n", count);
//	return 0;
//}

//n�Ľ׳ˣ��ݹ飩

//int Fac1(int n)
//{
//	if (n <= 1)
//	return 1;
//	else
//		return n*Fac1(n - 1);
//
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fac1(n);
//	printf("%d\n", ret);
//	return 0;
//}

//�ݹ����ַ������� ������ʱ�������ο���
//���»�С��1+1+1+my_strlen("");

//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("len = %d\n", len);
//}

//�ݹ����ַ�������   ����ʱ�������ο���

//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("len = %d\n", len);
//}

//*�ݹ飨�����Լ������Լ���

//��򵥵ĵĵݹ�

//int main()
//{
//	printf("hehe\n");
//	main();
//	return 0;//stack overflowջ���
//}

//����͵����Զ��庯����

//Add.h ->����  �� Add.c ->��������  �� Դ.c ->����ͷ�ļ�����

//Add.h: #ifndef (�Ƿ�����˺����� �� #define(���壬��ȡС���� ��#endif 

//#include "Add.h"
//int main()
//{
//	int ADD = Add(2, 3);
//	printf("%d\n", ADD);
//}

//������ʽ����

//int main()
//{
//	int len = 0;
//	int len = strlen("abc");
//	printf("%d\n", len);
//	printf("%d\n", strlen("abc"));
//}

//����һ�κ�����һ��

//void Add(int* p)
//{
//	(*p)++;
//}
//int main()
//{
//	int num = 0;
//	Add(&num);
//}

//���ֲ��ң������棩���ο���

//int binary_search(int arr[], int k,int sz)
//{
//	//���ܼ���Ԫ�ظ�����Ϊ������arr�Ĳ������飬��ָ�����(������Ԫ�صĵ�ַ)
//	//����int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);//���ڴ˼���
//	int k = 7;
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("error\n");
//	}
//	else
//	{
//		printf("found:%d\n", ret);
//	}
//	return 0;
//}

//�ж������������棩����ϰ��

//int is_prime(int n)
//{
//	int a = 0;
//	for (a = 2; a <= (n / 2); a++)
//	{
//		if (n % a == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//
//int main()
//{
//	int i = 0;
//	for (i = 100; i < 200; i++)
//	{
//		if (is_prime(i) == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}

//2 . ����

////��ʵ�δ����βε�ʱ���β���ʵ�ε�һ����ʱ����
////���βε��޸��ǲ���ı�ʵ�ε�
//void swap1(int x, int y) //�������ã���ֵ����
////x 
////int x��int y�������µĿռ�
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//}
//
//void swap2(int* pa, int* pb) //�������ã���ַ����
////��
////�����ú����ͺ�����ߵı���������ϵ
//{
//	int tmp = 0;
//	tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int* pa = &a;
//	int* pb = &b;
//	swap1(a, b);
//	printf("a=%d,b=%d\n", a, b);
//	swap2(&a, &b);
//	printf("a=%d,b=%d", a, b);
//	return 0;
//}

//strcpy���ο���

//int main()
//{
//	char arr1[] = "bit";
//	char arr2[20] = "#######";
//	strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

// 1.�� ��ʶ&ѭ�� ��

// �� �� ��goto�����ο���

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	//shutdown -s -t;  shutdown -a;
//	//system("") ִ��ϵͳ����
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//	again:
//	printf("������:������, ������ĵ��Խ���60s�ڹر�\n����:>");
//	scanf("%s", input);
//	if (strcmp(input, "������") == 0)
//	{
//		system("shutdown -a");
//		printf("\n�ߣ�����ʶ��o(���أ�o��)\n");
//	}
//	
//	else
//	{
//		goto again;
//	}
//	return 0;
//}

//��������Ϸ���ο���

//˼·������menu��game���������á������������ѭ���ж�while(1) etc.

//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <windows.h>
//#include <time.h>
//
//void menu()
//{
//    
//    printf("#########################\n");
//    printf("####### ��������Ϸ ######\n");
//    printf("#########################\n");
//    printf("##  1.play ### 2.exit ##\n");
//    printf("#########################\n");
//}
//
//void game()
//{
//    int ret = 0;
//    int guess = 0;
//    //time_t time(time_t* timer)
//    ret = rand() % 100 + 1;
//    //printf("%d\n", ret);
//    while (1)
//    {
//        printf("�������:>");
//        scanf("%d", &guess);
//        if (guess > ret)
//        {
//            printf("�´���\n");
//        }
//        else if (guess < ret)
//        {
//            printf("��С��\n");
//        }
//        else
//        {
//            printf("\n\n~~~~��л���¶���~~~~\n");
//            Sleep(3000);
//            break;
//        }
//    }
//}
//
//
//int main()
//{
//    int input = 0;
//    srand((unsigned int)time(NULL));//����ʱ����������������������ʼ��
//    do
//    {
//        system("cls");
//        menu();
//        printf("��ѡ��>");
//        scanf("%d", &input);
//
//        switch (input)
//        {
//        case 1:
//            game();
//            break;
//        case 0:
//            printf("���˳�\n");
//            break;
//        default:
//            printf("Error\n");
//            break;
//        }
//
//    } while (input);
//
//
//
//    return 0;
//}

//9*9�˷��ھ����ο���

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ", i, j, i * j);
//		}
//		printf("\n");
//
//	}
//	return 0;
//}

//10�����������ֵ���ο���

//int main()
//{
//	int arr[] = { -6,-2,-3,-4,-1,-5,-8,-12,-10 };
//	int max = arr[0];
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("max = %d\n", max);
//	return 0;
//}


//���º����÷���#include <math.h>

//������ѧ���� <math.h> �����ϣ������ο���

//
//1. abs
//ԭ�ͣ�extern int abs(int x);
//���ܣ�������x�ľ���ֵ
//˵�������� | x | , ��x��Ϊ��ʱ����x�����򷵻� - x
//
//2. fabs
//ԭ�ͣ�extern float fabs(float x);
//���ܣ��󸡵���x�ľ���ֵ
//˵�������� | x | , ��x��Ϊ��ʱ����x�����򷵻� - x
//
//3. sin
//ԭ�ͣ�extern float sin(float x);
//���ܣ�����x�����ȱ�ʾ��������ֵ��
//˵����x��ֵ��Ϊ[-1.0��1.0]��
//
//
//
//4. asin
//
//ԭ�ͣ�extern float asin(float x);
//
//���ܣ���x�����ȱ�ʾ���ķ�����ֵ
//
//˵����x�Ķ�����Ϊ[-1.0��1.0]��ֵ��Ϊ[-�� / 2�� + �� / 2]��
//
//5. cos
//ԭ�ͣ�extern float cos(float x);
//���ܣ���x�����ȱ�ʾ��������ֵ
//˵��������ֵ��[-1.0��1.0]֮�䡣
//
//6. acos
//
//ԭ�ͣ�extern float acos(float x);
//
//���ܣ���x�����ȱ�ʾ���ķ�����ֵ
//
//˵����x�Ķ�����Ϊ[-1.0��1.0]��ֵ��Ϊ[0����]��
//
//
//7. tan
//ԭ�ͣ�extern float tan(float x);
//���ܣ�����x�����ȱ�ʾ��������ֵ��
//˵��������x������ֵ��
//
//
//8. atan
//ԭ�ͣ�extern float atan(float x);
//���ܣ���x�����ȱ�ʾ���ķ�����ֵ
//˵����ֵ��Ϊ(-�� / 2�� + �� / 2)��
//
//
//9. atan2
//ԭ�ͣ�extern float atan2(float y, float x);
//���ܣ���y / x�����ȱ�ʾ���ķ�����ֵ
//˵����ֵ��Ϊ(-�� / 2�� + �� / 2)��
//
//
//10. sinh
//ԭ�ͣ�extern float sinh(float x);
//���ܣ�����x�����ȱ�ʾ����˫������ֵ��
//˵����sinh(x) = (e ^ x - e ^ (-x)) / 2��
//
//
//11. cosh
//ԭ�ͣ�extern float cosh(float x);
//���ܣ���x��˫������ֵ
//˵����cosh(x) = (e ^ x + e ^ (-x)) / 2
//
//
//12. tanh
//ԭ�ͣ�extern float tanh(float x);
//���ܣ���x��˫������ֵ
//˵����tanh(x) = (e ^ x - e ^ (-x)) / (e ^ 2 + e ^ (-x))
//
//
//13. ceil
//ԭ�ͣ�extern float ceil(float x);
//���ܣ���С��x����С����
//˵��������x�����ޣ���74.12������Ϊ75�� - 74.12������Ϊ - 74������ֵΪfloat���͡�
//
//
//14. floor
//ԭ�ͣ�extern float floor(float x);
//���ܣ��󲻴���x���������
//˵��������x�����ޣ���74.12������Ϊ74�� - 74.12������Ϊ - 75������ֵΪfloat���͡�
//
//
//15. exp
//ԭ�ͣ�extern float exp(float x);
//���ܣ���e��x����
//˵����e = 2.718281828...
//
//
//16. fmod
//ԭ�ͣ�extern float fmod(float x, float y);
//���ܣ�����x / y������
//˵��������x - n * y������ͬy��n = [x / y](���뿪��ķ���ȡ��)
//
//
//17. modf
//ԭ�ͣ�extern float modf(float num, float* i);
//���ܣ���������num�ֽ���������ֺ�С�����֡�
//˵��������С�����֣����������ִ���* i��ָ�ڴ��С�
//
//
//18. frexp
//ԭ�ͣ�extern float frexp(float x, int* exp);
//���ܣ��Ѹ�����x�ֽ��β����ָ����
//˵����x = m * 2 ^ exp��mΪ���С��������β��m������ָ������exp�С�
//
//
//19. ldexp
//ԭ�ͣ�extern float ldexp(float x, int exp);
//���ܣ�װ�ظ�������
//˵��������x * 2 ^ exp��ֵ��
//
//
//20. hypot
//ԭ�ͣ�extern float hypot(float x, float y);
//���ܣ����ڸ�����ֱ�������ε�����ֱ�Ǳߣ�����б�ߵĳ��ȡ�
//˵��������б��ֵ��
//
//21. log
//ԭ�ͣ�extern float log(float x);
//���ܣ�����x����Ȼ������
//˵����x��ֵӦ�����㡣
//
//
//22. log10
//ԭ�ͣ�extern float log10(float x);
//���ܣ�����x�ĳ��ö�����
//˵����x��ֵӦ�����㡣
//
//
//23. pow
//ԭ�ͣ�extern float pow(float x, float y);
//���ܣ�����x��y���ݡ�
//˵����xӦ�����㣬������ָ���Ľ����
//
//
//24. pow10
//ԭ�ͣ�extern float pow10(float x);
//���ܣ�����10��x���ݡ�
//˵�����൱��pow(10.0, x)��
//
//25. sqrt
//ԭ�ͣ�extern float sqrt(float x);
//���ܣ�����x��ƽ������
//˵����xӦ���ڵ����㡣

//��0-100��9�����֣��ο�������ҵ��

//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		//��λ�ϵ�9
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//	    if (i / 10 == 9)//����elseif��ƽ���ж�99
//		{
//			count++;
//		}
//
//	}
//	printf("count = %d\n", count);
//}

// �ж������Ĺ��� 1.�Գ��� 2.�Գ���pro  �Ż���(i=a*b ; a,b��������һ����<=��ƽ��i)

// 3.�Գ���proo  �Ż���(ż������������),<��ƽ��i���ɣ�a+b)/2>

//����������n�־��硷���ο���

//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = 0;
//		
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//
//		if (i == j)
//		{
//			count++;
//			printf("%d ", i);
//		}
//
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}

//#include <math.h>
//int main() //sqrt() -> ��ƽ������ѧ�⺯��
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = 0;
//
//		for (j = 2; j < sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//
//		if (i > sqrt(i))
//		{
//			count++;
//			printf("%d ", i);
//		}
//
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}

//#include <math.h>
//int main() //sqrt() -> ��ƽ������ѧ�⺯��
//{
//	int i = 0;
//	int count = 0;
//	for (i = 101; i <= 200; i+=2)//�Ż�:ż������������
//	{
//		int j = 0;
//
//		for (j = 2; j < sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//
//		if (i > sqrt(i))
//		{
//			count++;
//			printf("%d ", i);
//		}
//
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}

//��ʶ�ṹ�壨�ο���

//struct Book         //�������ṹ��
//{
//    char name[20];
//    short price;
//};
//
//int main()
//{
//    struct Book b1 = { "c����",55 };
//    printf("������%s ,�۸�%d\n", b1.name, b1.price);
//    b1.price = 15;         //�����޸ı���������
//    printf("�ĺ�۸�%d\n", b1.price);
//    struct Book* pb = &b1;
//
//    //��note : ȡ��ַ������ʹ�÷���
//    //��note��������
//
//    printf("%s\n", pb->name);
//    printf("%d\n", pb->price);
//        //������
//    printf("%s\n", (*pb).name);
//    printf("%d\n", (*pb).price);
//
//            return 0;
//}

//����꣨�ο���

//#define MAX(X, Y) (X>Y?X: Y)
//
//int main()
//{
//    int a = 10;
//    int b = 20;
//    max = MAX(a, b);
//    return 0;
//}

//���庯�����ο���

//int Add(int x, int y)
//{
//    int z = x + y;
//    return z;
//}
//int main()
//{
//    int num1 = 0;
//    int num2 = 0;
//    int sum = 0;
//    printf("��������������:>");
//    scanf("%d %d", &num1, &num2);
//    sum = Add(num1, num2);
//    printf("sum = %d\n", sum);
//    return 0;
//}

//��д���룬��ʾ����ַ��������ƶ������м��ۣ��ο���

//#include <string.h>
//#include <Windows.h>
//#include <stdlib.h>
//int main()
//{
//	char arr1[] = "welcome to bit!!!!!!";
//	char arr2[] = "####################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(300);
//		system("cls");
//		left++;
//		right--;
//	}
//
//
//	return 0;
//}

//��һ�����������ж��ֲ��Ҿ����ĳ������n���ο���

//int main()
//{
//	int k = 0;
//	scanf("%d", &k); //������ҵ�����
//
//	int arr[] = { 4,5,6,7,8,9,10,11,12,13 };
//	            //0,1,2,3,4,5, 6, 7, 8, 9
//	int left = 0;
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("found:%d\n", mid);
//			break;
//
//		}
//	}
//	if (left > right)
//	{
//		printf("not found");
//	}
//	return 0;
//}

//�������꣨�ο���

//int main()
//{
//	//1.�ܱ�4�������Ҳ��ܱ�100������������
//	//2.�ܱ�400������������
//
//	int year = 0;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (year % 4 == 0 && year % 100 != 0)
//		{
//			printf("%d ", year);
//			count++;
//		}
//
//		else if (year % 400 == 0)
//		{
//			printf("%d ", year);
//			count++;
//		}
//	}
//	printf("\ncount = %d\n", count);
//	return 0;
//}

//��������pro���ο���

//int main()
//{
//	int year = 0;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		{
//			printf("%d ", year);
//			count++;
//		}
//	}
//	printf("\ncount = %d\n", count);
//	return 0;
//}

//��Լ�����ο���

//int main()
//{
//	int m = 0;
//	int n = 0;
//	int r = 0;
//	scanf("%d%d", &m, &n);
//	while (r = m % n)
//	{
//		m = n;
//		n = r;
//	}
//	printf("%d\n", n);
//	return 0;
//}

//��Լ����DIY��

////��Լ��(diy)
//int main()
//{
//	int a, b;
//	int i = 1;
//	printf("please input 2 numbers saperated by space:>");
//	scanf("%d%d", &a, &b);
//	//input '0'
//	if (a == 0 || b == 0)
//	{
//		printf("not support '0'");
//		return 0;
//	}
//	//adjustment
//	if (b > a)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}// make a > b
//	//շת�����
//	for (i = 1;i != 0;)
//	{
//		i = a % b;
//		if (i != 0)
//		{
//			a = b;
//			b = i;
//		}
//		
//	}
//	printf("��Լ��:>%d\n", b);
//	return b;
//}

//0-x���3�ı�����DIY��

//int main()
//{
//	int p = 0;
//	int i = 0;
//	printf("input a target number:>");
//	scanf("%d", &p);
//	int t = p / 3;
//	for (i = 1; i <= t; i++)
//	{
//		int a = 3 * i;
//		printf("%d\n", a);
//	}
//}

//0-x���3�ı������ο���

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}

//�Ƚ�3����С����ϰ��

//int main()
//{
//	int a, b, c;
//	printf("���������������Կո����:>");
//	scanf("%d%d%d", &a, &b, &c);//1 2 3
//	if (b > a)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//
//	if (c > a)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//
//	if (c > b)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//
//
//
//
//	printf("�Ӵ�СΪ:>%d %d %d", a, b, c);
//}

//ָ�����飨�ο���
//int* arr[10] = { 0 };
 
//����ָ��
//int(*arr)[10] = { 0 };

//����ָ��
//int Add_2(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int (*p_add) (int,int) = Add_2;
//	printf("p\n", p_add);
//	return 0;
//}




