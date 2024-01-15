#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>
#include <assert.h>
//快捷键：ctrl + M + O 折叠所有代码块 

//P34 B30  字符指针

//int main()
//{
//	char* p = "ABCDEF";//or const char* p = "ABCDEF"
//	*p = 'W';
//	printf("%s\n", p);
//	return 0;//错误，因为ABCDEF是常量字符串无法修改
//}

//P32 B29  “float”类型 在内存中的存储方式

//(-1)^S * M * 2^E
//S(1bit)  E(8bit)  M(23bit)     32位浮点数存储模型
//S(1bit)  E(11bit) M(52bit)     64位浮点数存储模型
//  ---    ------  ------------
// S是符号位
// 2^E表示指数位。
// M表示有效数字，大于等于1，小于2。
//Eg：5.0 ——> (-1)^0 * 1.01 * 2^2 ——>S=0 M=1.01 E=2
//
// **：
//特别规定：1、在计算机内部保存M时，默认第一位总是1，因此可以被舍去，只保存后面的0.xxxxxx部分
//         2、E为一个无符号整数，为保证正数，存入内存时E的真实值全部加入中间数127，Eg：E=10+127
//         3、E不全是0或1，真实E值+127存入内存 ——》存储E值
//			  E全为0，E=1-127，则M不再加入首位1，还原接近于0的很小小的数字
//            E全为1，如果有效数字M全为0，表示±无穷大（正负取决于符号位s）

//P32 B28  char存入整形循环（-187——>127）

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

//整形提升，打印相关问题

//int main()
//{
//	char a = -128;
//	char b = 128;
//	printf("%u\n%u\n", a,b);
//	return 0;
//}
//1、进行整形提升是按自身的元素类型
//2、char为有符号整形类型
//3、先截断再整形提升，如char a = -128；先取整形-128补码，再截断后8位二进制位存入a
//4、打印printf前整形提升也是参考元素本身类型，提升后内存中存储的补码视为打印的元素类型，如打印%u，则原码等于补码，直接打印补码即可。%d则求出原码打印


//代码常见错误

//    编译型错误
//直接看错误提示信息（双击），解决问题。或者凭借经验就可以搞定。相对来说简单。
//    链接型错误
//看错误提示信息，主要在代码中找到错误信息中的标识符，然后定位问题所在。一般是标识符名
//不存在或者拼写错误。
//    运行时错误
//借助调试，逐步定位问题。最难搞


//写出好的代码(strcpy,strlen的自写)

//加入assert，加入const修饰传入参数，循环优化等

//strcpy:

//char* mystrcpy(char* dest, const char* sour)//const确保原字符串不被改变
//{
//	assert(dest != NULL);
//	assert(sour != NULL);//确保指针有效性，非空指针
//	char* ret = dest;//保存dest字符串的首地址，以方便return传址
//
//	while (*dest++=*sour++)//集合 判断‘/0’、字符赋值、字符串移动向下一个元素
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

//调试

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


//字符数组逆序

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


//指针加减整数

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

//不同指针类型的作用范围不同int 4，char 1

//int main()
//{
//	int a = 0x11223344;
//	char* pc = &a;
//	*pc = 0;
//	printf("%d\n", a);
//	return 0;
//}

//结构体类型

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
//	//结构体变量.成员名 or 结构体变量指针->成员名
//}

//逗号表达式

//while(exp1,.,expn)
//{
//......
//}

//逻辑与

//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = a && b;
//	printf("%d\n", c);
//	return 0;
//}

//强制类型转换 (int)

// int a = (int)3.14;

//计算二进制整数有多少个1（练习）

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


//操作符详解

//>> -> 右移操作符（移动的是二进制位）

//1.算数右移
// 右边丢弃，左边补原符号位
//2.逻辑右移
// 右边丢弃，左边补0
// 00000000000000000000000000000000
// |
// 符号位（通常是算数右移）

//>> <- 左移操作符（移动的是二进制位）

//1.算数左移
// 左边丢弃，左边补0



//按位与

//00000000000000000000000000000011
//00000000000000000000000000000101
//00000000000000000000000000000001

//按位或

//00000000000000000000000000000011
//00000000000000000000000000000101
//00000000000000000000000000000111

//按位异或 ！

//00000000000000000000000000000011
//00000000000000000000000000000101
//00000000000000000000000000000111

//用按位异或来交换2个数


//（作业）编写一个程序, 接收用户从键盘输入的字符, 当用户输入回车时表示确认输入, 分别统计输入大写字母个数、小写字母个数、0 - 9数字字符个数、空格字符个数以及其它字符个数。

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
//    printf("小写字母个数：%d\n", letter);
//    printf("大写字母个数：%d\n", majuscule);
//    printf("空格字符个数：%d\n", space);
//    printf("数字个数：%d\n", digit);
//    printf("其它字符个数：%d\n", others);
//    return 0;
//}

//&数组名，数组名代表的是整个数组，取出的地址是整个数组的地址

//int main()
//{
//	int arr[] = {1,2,3,4,5,6};
//	printf("%p\n", arr);    //数组首元素的地址
//	printf("%p\n", arr+1);
//
//	printf("%p\n", &arr[0]);//数组首元素的地址
//	printf("%p\n", &arr[0]+1);
//	
//	printf("%p\n", &arr);   //整个数组的地址
//	printf("%p\n", &arr+1);//只有sizeof(),&arr才是整个数组
//	
//}

//冒泡排序

//从低到高

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
//				flag = 0;//本趟排列数据不完全有序
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

//数组在内存中是连续存放的

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
//	return 0;//数组在内存中是连续存放的
//}

//斐波那契数列（递归）(效率低，重复次数大）

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
//int Fib2(int n) //（DIY）
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
//int Fib3(int n) //（参考）
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

//n的阶乘（递归）

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

//递归求字符串长度 不用临时变量（参考）
//大事化小：1+1+1+my_strlen("");

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

//递归求字符串长度   用临时变量（参考）

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

//*递归（函数自己调用自己）

//最简单的的递归

//int main()
//{
//	printf("hehe\n");
//	main();
//	return 0;//stack overflow栈溢出
//}

//定义和调用自定义函数：

//Add.h ->声明  ； Add.c ->函数本体  ； 源.c ->引用头文件即可

//Add.h: #ifndef (是否定义过此函数） ； #define(定义，并取小名） ；#endif 

//#include "Add.h"
//int main()
//{
//	int ADD = Add(2, 3);
//	printf("%d\n", ADD);
//}

//函数链式调用

//int main()
//{
//	int len = 0;
//	int len = strlen("abc");
//	printf("%d\n", len);
//	printf("%d\n", strlen("abc"));
//}

//调用一次函数加一次

//void Add(int* p)
//{
//	(*p)++;
//}
//int main()
//{
//	int num = 0;
//	Add(&num);
//}

//二分查找（函数版）（参考）

//int binary_search(int arr[], int k,int sz)
//{
//	//不能计算元素个数因为传上来arr的不是数组，是指针变量(数组首元素的地址)
//	//×：int sz = sizeof(arr) / sizeof(arr[0]);
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
//	int sz = sizeof(arr) / sizeof(arr[0]);//：在此计算
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

//判断素数（函数版）（练习）

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

//2 . 函数

////当实参传给形参的时候，形参是实参的一份临时拷贝
////对形参的修改是不会改变实参的
//void swap1(int x, int y) //函数调用：传值调用
////x 
////int x和int y开辟了新的空间
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//}
//
//void swap2(int* pa, int* pb) //函数调用：传址调用
////√
////可以让函数和函数外边的变量产生联系
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

//strcpy（参考）

//int main()
//{
//	char arr1[] = "bit";
//	char arr2[20] = "#######";
//	strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

// 1.《 初识&循环 》

// 我 是 猪（goto）（参考）

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	//shutdown -s -t;  shutdown -a;
//	//system("") 执行系统命令
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//	again:
//	printf("快输入:我是猪, 否则你的电脑将在60s内关闭\n输入:>");
//	scanf("%s", input);
//	if (strcmp(input, "我是猪") == 0)
//	{
//		system("shutdown -a");
//		printf("\n哼，算你识相o(￣ヘ￣o＃)\n");
//	}
//	
//	else
//	{
//		goto again;
//	}
//	return 0;
//}

//猜数字游戏（参考）

//思路：创建menu；game函数；利用、改造随机数；循环判断while(1) etc.

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
//    printf("####### 猜数字游戏 ######\n");
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
//        printf("请猜数字:>");
//        scanf("%d", &guess);
//        if (guess > ret)
//        {
//            printf("猜大了\n");
//        }
//        else if (guess < ret)
//        {
//            printf("猜小了\n");
//        }
//        else
//        {
//            printf("\n\n~~~~感谢您猜对了~~~~\n");
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
//    srand((unsigned int)time(NULL));//利用时间戳来设置随机数的生成起始点
//    do
//    {
//        system("cls");
//        menu();
//        printf("请选择：>");
//        scanf("%d", &input);
//
//        switch (input)
//        {
//        case 1:
//            game();
//            break;
//        case 0:
//            printf("已退出\n");
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

//9*9乘法口诀表（参考）

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

//10个整数的最大值（参考）

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


//以下函数用法：#include <math.h>

//常用数学函数 <math.h> （资料）；（参考）

//
//1. abs
//原型：extern int abs(int x);
//功能：求整数x的绝对值
//说明：计算 | x | , 当x不为负时返回x，否则返回 - x
//
//2. fabs
//原型：extern float fabs(float x);
//功能：求浮点数x的绝对值
//说明：计算 | x | , 当x不为负时返回x，否则返回 - x
//
//3. sin
//原型：extern float sin(float x);
//功能：计算x（弧度表示）的正弦值。
//说明：x的值域为[-1.0，1.0]。
//
//
//
//4. asin
//
//原型：extern float asin(float x);
//
//功能：求x（弧度表示）的反正弦值
//
//说明：x的定义域为[-1.0，1.0]，值域为[-π / 2， + π / 2]。
//
//5. cos
//原型：extern float cos(float x);
//功能：求x（弧度表示）的余弦值
//说明：返回值在[-1.0，1.0]之间。
//
//6. acos
//
//原型：extern float acos(float x);
//
//功能：求x（弧度表示）的反余弦值
//
//说明：x的定义域为[-1.0，1.0]，值域为[0，π]。
//
//
//7. tan
//原型：extern float tan(float x);
//功能：计算x（弧度表示）的正切值。
//说明：返回x的正切值。
//
//
//8. atan
//原型：extern float atan(float x);
//功能：求x（弧度表示）的反正切值
//说明：值域为(-π / 2， + π / 2)。
//
//
//9. atan2
//原型：extern float atan2(float y, float x);
//功能：求y / x（弧度表示）的反正切值
//说明：值域为(-π / 2， + π / 2)。
//
//
//10. sinh
//原型：extern float sinh(float x);
//功能：计算x（弧度表示）的双曲正弦值。
//说明：sinh(x) = (e ^ x - e ^ (-x)) / 2。
//
//
//11. cosh
//原型：extern float cosh(float x);
//功能：求x的双曲余弦值
//说明：cosh(x) = (e ^ x + e ^ (-x)) / 2
//
//
//12. tanh
//原型：extern float tanh(float x);
//功能：求x的双曲正切值
//说明：tanh(x) = (e ^ x - e ^ (-x)) / (e ^ 2 + e ^ (-x))
//
//
//13. ceil
//原型：extern float ceil(float x);
//功能：求不小于x的最小整数
//说明：返回x的上限，如74.12的上限为75， - 74.12的上限为 - 74。返回值为float类型。
//
//
//14. floor
//原型：extern float floor(float x);
//功能：求不大于x的最达整数
//说明：返回x的下限，如74.12的下限为74， - 74.12的下限为 - 75。返回值为float类型。
//
//
//15. exp
//原型：extern float exp(float x);
//功能：求e的x次幂
//说明：e = 2.718281828...
//
//
//16. fmod
//原型：extern float fmod(float x, float y);
//功能：计算x / y的余数
//说明：返回x - n * y，符号同y。n = [x / y](向离开零的方向取整)
//
//
//17. modf
//原型：extern float modf(float num, float* i);
//功能：将浮点数num分解成整数部分和小数部分。
//说明：返回小数部分，将整数部分存入* i所指内存中。
//
//
//18. frexp
//原型：extern float frexp(float x, int* exp);
//功能：把浮点数x分解成尾数和指数。
//说明：x = m * 2 ^ exp，m为规格化小数。返回尾数m，并将指数存入exp中。
//
//
//19. ldexp
//原型：extern float ldexp(float x, int exp);
//功能：装载浮点数。
//说明：返回x * 2 ^ exp的值。
//
//
//20. hypot
//原型：extern float hypot(float x, float y);
//功能：对于给定的直角三角形的两个直角边，求其斜边的长度。
//说明：返回斜边值。
//
//21. log
//原型：extern float log(float x);
//功能：计算x的自然对数。
//说明：x的值应大于零。
//
//
//22. log10
//原型：extern float log10(float x);
//功能：计算x的常用对数。
//说明：x的值应大于零。
//
//
//23. pow
//原型：extern float pow(float x, float y);
//功能：计算x的y次幂。
//说明：x应大于零，返回幂指数的结果。
//
//
//24. pow10
//原型：extern float pow10(float x);
//功能：计算10的x次幂。
//说明：相当于pow(10.0, x)。
//
//25. sqrt
//原型：extern float sqrt(float x);
//功能：计算x的平方根。
//说明：x应大于等于零。

//求0-100含9的数字（参考）（作业）

//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		//个位上的9
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//	    if (i / 10 == 9)//不用elseif以平行判断99
//		{
//			count++;
//		}
//
//	}
//	printf("count = %d\n", count);
//}

// 判断素数的规则 1.试除法 2.试除法pro  优化：(i=a*b ; a,b中至少有一个数<=开平方i)

// 3.试除法proo  优化：(偶数都不是素数),<开平方i换成（a+b)/2>

//《素数求解的n种境界》（参考）

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
//int main() //sqrt() -> 开平方的数学库函数
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
//int main() //sqrt() -> 开平方的数学库函数
//{
//	int i = 0;
//	int count = 0;
//	for (i = 101; i <= 200; i+=2)//优化:偶数都不是素数
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

//初识结构体（参考）

//struct Book         //→创建结构体
//{
//    char name[20];
//    short price;
//};
//
//int main()
//{
//    struct Book b1 = { "c语言",55 };
//    printf("书名：%s ,价格：%d\n", b1.name, b1.price);
//    b1.price = 15;         //→（修改变量方法）
//    printf("改后价格：%d\n", b1.price);
//    struct Book* pb = &b1;
//
//    //上note : 取地址操作符使用方法
//    //下note：解引用
//
//    printf("%s\n", pb->name);
//    printf("%d\n", pb->price);
//        //或者是
//    printf("%s\n", (*pb).name);
//    printf("%d\n", (*pb).price);
//
//            return 0;
//}

//定义宏（参考）

//#define MAX(X, Y) (X>Y?X: Y)
//
//int main()
//{
//    int a = 10;
//    int b = 20;
//    max = MAX(a, b);
//    return 0;
//}

//定义函数（参考）

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
//    printf("输入两个操作数:>");
//    scanf("%d %d", &num1, &num2);
//    sum = Add(num1, num2);
//    printf("sum = %d\n", sum);
//    return 0;
//}

//编写代码，演示多个字符从两端移动，向中间汇聚（参考）

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

//在一个有序数组中二分查找具体的某个数字n（参考）

//int main()
//{
//	int k = 0;
//	scanf("%d", &k); //输入查找的数字
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

//计算闰年（参考）

//int main()
//{
//	//1.能被4整除，且不能被100整除的是闰年
//	//2.能被400整除的是闰年
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

//计算闰年pro（参考）

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

//求公约数（参考）

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

//求公约数（DIY）

////求公约数(diy)
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
//	//辗转相除法
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
//	printf("公约数:>%d\n", b);
//	return b;
//}

//0-x间的3的倍数（DIY）

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

//0-x间的3的倍数（参考）

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

//比较3数大小（练习）

//int main()
//{
//	int a, b, c;
//	printf("输入三个整数，以空格隔断:>");
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
//	printf("从大到小为:>%d %d %d", a, b, c);
//}

//指针数组（参考）
//int* arr[10] = { 0 };
 
//数组指针
//int(*arr)[10] = { 0 };

//函数指针
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




