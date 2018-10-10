#include"stdio.h"
#include"stdafx.h"
#include"stdlib.h"
#include"windows.h"
#define M 100 //队列的最大值

//数据结构的定义///////////////////////////////////////////////////
struct bool_stack
{
	int bit[M] = {}; //bool数的储存区
	int top = 0; //初始化栈顶
};

struct data2
{
	char symbol[8] = {}; //符号位
	float p = 0; //概率位
	struct bool_stack word = {}; //码字储存栈
	int code = 2; //每次分配时的编码储存位
	struct data2 *next = (struct data2 *)malloc(sizeof(struct data2));; //指向其运算父节点
	struct data2 *bubnext = (struct data2 *)malloc(sizeof(struct data2));; //指向冒泡排序的下一个人
};

struct data3
{
	char symbol[8] = {}; //符号位
	float p = 0; //概率位
	struct bool_stack word = {}; //码字储存栈
	int code = 3; //每次分配时的编码储存位
	struct data3 *next = (struct data3 *)malloc(sizeof(struct data3));; //指向其运算父节点
	struct data3 *bubnext = (struct data3 *)malloc(sizeof(struct data3));; //指向冒泡排序的下一个人
};

int main(void)
{
	//观察者选项///////////////////////////////////////////////////

	char order[20];
	printf("如需详细计算过程，请在下方输入：hellounderworld\n如只需计算结果，请输入任意其他字符\n【指令待输入】：");
	scanf_s("%s", &order, 20);
	int testflag = 0;
	if (strcmp(order, "hellounderworld") == 0)
	{
		printf("\n观察者模式已开启\n");
		testflag = 1;
		printf("Welcome to UnderWorld, Stranger\n\n");
		system("color 1F");
	}

	//编码进制选择////////////////////////////////////////////////////
	int sys;
	int sysendflag = 0;
	printf("\n > 请输入进制数（2 或 3）：");
	scanf_s("%d", &sys);
	while (sys != 2 && sys != 3)
	{
		printf("【!】输入非法,无法对您的选择的进制数进行编码,请重新输入：");
		scanf_s("%d", &sys);
	}

	//————————————————————————————————————————————————————————————
	if (testflag == 1)
	{
		if (sys == 2)
		{
			printf(" > 您的选择为：二进制\n > 已确认\n\n");
		}
		else
		{
			printf(" > 您的选择为：三进制\n > 已确认\n\n");
		}
	}
	//————————————————————————————————————————————————————————————

	int num; //待编码符号个数

	printf("\n > 请输入待编码符号个数（1~35）：");
	scanf_s("%d", &num);
	while (num>M || num<0)
	{
		printf("【!】所输入个数非法，请输入合法数字（1~35）：");
		scanf_s("%d", &num);
	}

	//————————————————————————————————————————————————————————————
	if (testflag == 1)
	{
		printf(" > 所输入输入待编码符号个数num为：%d\n > 已确认\n\n", num);
	}
	//————————————————————————————————————————————————————————————

	printf("\n");

	char ori_symbol[M][8];
	float ori_p[M];
	int i; //原始数据输入计数变量
	float p0 = 0;
	for (i = 0; i<num; i++) //依次输入数据
	{
		printf(" > 请输入第%d个符号：", i + 1);
		scanf_s("%s", &ori_symbol[i], 8);
		while (strlen(ori_symbol[i])>6)
		{
			printf("【!】所输入符号需少于5个字符，请重新输入：");
			scanf_s("%s", &ori_symbol[i], 8);
		}
		printf(" > 请输入第%d个符号的概率值：", i + 1);
		scanf_s("%f", &ori_p[i]);
		p0 = p0 + ori_p[i];
		while (p0>1 || ori_p[i]<0)
		{
			printf("【!】所输入概率值不合法，请计算后重新输入：");
			scanf_s("%s", &ori_symbol[i], 8);
		}
	}

	struct data2 node[M]; //原始节点数组
	for (i = 0; i<num; i++) //依次输入数据
	{
		strcpy_s(node[i].symbol, ori_symbol[i]);  //符号位
		node[i].p = ori_p[i]; //概率位
		node[i].bubnext = &node[0];
	}

	//————————————————————————————————————————————————————————————
	if (testflag == 1)
	{
		printf("\n > 所输入待编码符号及其概率为：");
		for (i = 0; i < num; i++) //依次输入数据
		{
			printf("%s(%f), ", node[i].symbol, node[i].p);
		}
		printf("\n > 已确认\n\n");
	}
	//————————————————————————————————————————————————————————————

	if (sys == 3)
	{
		struct data3 endnode;
		endnode.symbol[0] = { 'E' };
		endnode.symbol[1] = { 'N' };
		endnode.symbol[2] = { 'D' };

		struct data3 node[M]; //原始节点数组
		for (i = 0; i<num; i++) //依次输入数据
		{
			strcpy_s(node[i].symbol, ori_symbol[i]);  //符号位
			node[i].p = ori_p[i]; //概率位
			node[i].bubnext = &node[0];
		}

		//计算补零个数
		int zero_3; //中间计算变量
		int zero; //最终补零个数
		zero_3 = num / 3 + num % 3; //给计算中间变量赋初值
		while (zero_3 > 3)
		{
			zero_3 = (zero_3 / 3) + (zero_3 % 3);
		}
		zero = 3 - zero_3;
		//————————————————————————————————————————————————————————————
		if (testflag == 1)
		{
			printf(" > 输入%d个符号时，需补%d个零\n > 已确认\n\n", num, zero);
		}
		//————————————————————————————————————————————————————————————

		//————————————————————————————————————————————————————————————
		if (testflag == 1)
		{
			printf(" > 所输入待编码符号及其概率为：");
			for (i = 0; i < num + zero; i++) //依次输入数据
			{
				printf("%s(%f), ", node[i].symbol, node[i].p);
			}
			printf("\n > 已确认\n\n");
		}
		//————————————————————————————————————————————————————————————

		//初次的冒泡排序//////////////////////////////////////////////////
		int bub_n, bub_i, bub_j;
		struct data3 bub_dummy;
		bub_n = num + zero;
		bub_i = 0;
		while (bub_i <= (bub_n - 1))
		{
			bub_j = bub_i;
			while (bub_j <= bub_n)
			{
				bub_j++;
				if (node[bub_i].p < node[bub_j].p) //最大的放在最前面,水面是最大的数，下标为0
				{
					bub_dummy.p = node[bub_i].p;
					strcpy_s(bub_dummy.symbol, node[bub_i].symbol);

					node[bub_i].p = node[bub_j].p;
					strcpy_s(node[bub_i].symbol, node[bub_j].symbol);

					node[bub_j].p = bub_dummy.p;
					strcpy_s(node[bub_j].symbol, bub_dummy.symbol);
				}
			}
			bub_i++;
		}

		//——————————————————————————————————————————————————————————————
		if (testflag == 1)
		{
			printf(" > 第一次排序后的结果：");
			for (i = 0; i < num + zero; i++) //依次输入数据
			{
				printf("%s(%f), ", node[i].symbol, node[i].p);
			}
			printf("\n > 已确认\n\n");
		}
		//—————————————————————————————————————————————————————————————

		//冒泡节点链接///////////////////////////////////////////////////

		node[0].bubnext = &endnode;
		for (i = 1; i<num + zero; i++)
		{
			node[i].bubnext = &node[i - 1]; //进行冒泡链接
		}

		//——————————————————————————————————————————————————————————————
		if (testflag == 1)
		{
			printf(" > 按冒泡链接输出的结果：");
			struct data3 *bub_link;
			bub_link = &node[num + zero - 1];
			while (bub_link != &endnode)
			{
				printf("%s(%f), ", (*bub_link).symbol, (*bub_link).p);
				bub_link = (*bub_link).bubnext;
			}
			printf("\n > 已确认\n\n");
			bub_link = &endnode;
		}
		//——————————————————————————————————————————————————————————————

		//循环部分开始///////////////////////////////////////////////////////
		struct data3 *seafloor;
		seafloor = &node[num + zero - 1];
		seafloor->bubnext = node[num + zero - 1].bubnext;
		struct data3 sum[M]; //等一下用的合成节点
		int k = 0; //合成节点数组的当前可用位置标记
		float psum = 0;
		float plus1, plus2, plus3;

		while (psum != 1)
		{
			//	4、选出概率最小的两个节点进行操作

			seafloor->code = 0; //因为已经排序，所以最后一个就是最小的
			seafloor->bubnext->code = 1; //倒数第二个就是次小的
			seafloor->bubnext->bubnext->code = 2;
			plus1 = seafloor->p;
			plus2 = seafloor->bubnext->p;
			plus3 = seafloor->bubnext->bubnext->p;
			psum = plus1 + plus2 + plus3;

			//——————————————————————————————————————————————————————————————————
			if (testflag == 1)
			{
				printf(" >【第%d次迭代循环】———————————————————————————————————————\n\n", k + 1);
				printf("（1）输出当前步的一位编码：");
				printf("%d(%f)，%d(%f)，%d(%f)", seafloor->code, plus1, seafloor->bubnext->code, plus2, seafloor->bubnext->bubnext->code, plus3);
				printf("\n > 已确认\n\n");

				printf("（2）输出概率计算过程：");
				printf("%s(%f) + %s(%f) + %s(%f) = 合成量(%f)", seafloor->symbol, plus1, seafloor->bubnext->symbol, plus2, seafloor->bubnext->bubnext->symbol, plus3, psum);
				printf("\n > 已确认\n\n");
			}
			//——————————————————————————————————————————————————————————————————

			if (psum == 1)
			{
				seafloor->next = &endnode;
				seafloor->bubnext->next = &endnode;
				seafloor->bubnext->bubnext->next = &endnode;
				break;
			}
			else //新节点生成
			{
				sum[k].p = psum; //和概率 【?????】为什么这一句没法给sum[k].p赋上值？
				seafloor->next = &sum[k]; //将概率最小的节点的next链接到新节点
				seafloor->bubnext->next = &sum[k]; //将概率次小的节点的next也链接到新节点
				seafloor->bubnext->bubnext->next = &sum[k];
				sum[k].bubnext = seafloor->bubnext->bubnext->bubnext; //将新节点和“概率最大的节点的下一个冒泡点”相连
				seafloor = &sum[k]; //改变冒泡起点，相当于把处理过的三个点踢出了冒泡集合
				k++; //这个k已经用过了，换下一个
			}

			//——————————————————————————————————————————————————————————————————
			struct data3 *bub_link;
			bub_link = seafloor;
			bub_link->bubnext = seafloor->bubnext;
			if (testflag == 1)
			{
				printf("（3）输出新节点sum[%d]：", k - 1);
				printf("%s(%f)", sum[k - 1].symbol, sum[k - 1].p);
				printf("\n > 已确认\n\n");

				printf("（4）连入新节点后，冒泡链接输出的结果：");
				while (bub_link != &endnode)
				{
					printf("%s(%f), ", bub_link->symbol, bub_link->p);
					bub_link = bub_link->bubnext;
				}
				printf("\n > 已确认\n\n");
			}
			//——————————————————————————————————————————————————————————————————

			//新节点作单次冒泡处理///////////////////////////////////////////////////
			struct data3 *newnode; //始终指向新节点
			newnode = seafloor;
			struct data3 *comp; //记录当前正在比较的节点
			comp = seafloor->bubnext; //初始化
			struct data3 *dummy1; //用于临时储存在海底上一层的节点位置
			dummy1 = (struct data3 *)malloc(sizeof(struct data3));
			int seaflag = 1; //用于判断是不是第一次换海底位置，应该只有第一次需要换一下海底
			while (comp != &endnode)
			{
				if ((comp->p)<(newnode->p))
				{
					if (seaflag == 1)
					{
						seafloor = comp;
						seaflag = 0;
					}
					dummy1->bubnext = comp;
					newnode->bubnext = comp->bubnext;
					comp->bubnext = newnode;
					dummy1 = comp;
					comp = newnode->bubnext;
				}
				else
				{
					break; //没有换位，因为更高的水面是有序的，所以不用比了
				}
			}

			//————————————————————————————————————————————————————————————————
			if (testflag == 1)
			{
				printf("（5）新节点冒泡后，冒泡链接输出的结果：");
				bub_link = seafloor;
				while (bub_link != &endnode)
				{
					printf("%s(%f), ", bub_link->symbol, bub_link->p);
					bub_link = bub_link->bubnext;
				}
				printf("\n > 已确认\n\n");
			}
			//————————————————————————————————————————————————————————————————
		}
		//循环部分结束//////////////////////////////////////////////////////////////

		//将编好的码字整理，入word栈/////////////////////////////////////////////////
		struct data3 *now;
		int load_code;
		for (i = 0; i < num; i++)
		{
			now = &node[i];
			now->next = node[i].next;
			while (now->code != 3)
			{
				load_code = now->code;
				node[i].word.bit[node[i].word.top] = load_code;
				node[i].word.top++;
				now = now->next;
			}
			printf("\n");
		}

		//输出最终结果////////////////////////////////////////////
		printf("——————————————————————————————————————————\n\n\n\n\n\n【最终编码结果】：\n\n");
		for (i = 0; i<num; i++) //每次循环都是不同的符号
		{
			printf(" >【%s】的编码为：", node[i].symbol);
			node[i].word.top--;
			while ((node[i].word).top >= 0) //每次循环都是同一符号码字的不同位
			{
				printf("%d", node[i].word.bit[node[i].word.top]);
				node[i].word.top--;
			}
			printf("\n\n");
		}
	}
	else
	{
		struct data2 node[M]; //原始节点数组
		for (i = 0; i<num; i++) //依次输入数据
		{
			strcpy_s(node[i].symbol, ori_symbol[i]);  //符号位
			node[i].p = ori_p[i]; //概率位
			node[i].bubnext = &node[0];
		}

		//————————————————————————————————————————————————————————————
		if (testflag == 1)
		{
			printf("\n > 所输入待编码符号及其概率为：");
			for (i = 0; i < num; i++) //依次输入数据
			{
				printf("%s(%f), ", node[i].symbol, node[i].p);
			}
			printf("\n > 已确认\n\n");
		}
		//————————————————————————————————————————————————————————————

		struct data2 endnode;
		endnode.symbol[0] = { 'E' };
		endnode.symbol[1] = { 'N' };
		endnode.symbol[2] = { 'D' };

		//初次的冒泡排序//////////////////////////////////////////////////
		int bub_n, bub_i, bub_j;
		struct data2 bub_dummy;
		bub_n = num;
		bub_i = 0;
		while (bub_i <= (bub_n - 1))
		{
			bub_j = bub_i;
			while (bub_j <= bub_n)
			{
				bub_j++;
				if (node[bub_i].p < node[bub_j].p) //最大的放在最前面,水面是最大的数，下标为0
				{
					bub_dummy.p = node[bub_i].p;
					strcpy_s(bub_dummy.symbol, node[bub_i].symbol);

					node[bub_i].p = node[bub_j].p;
					strcpy_s(node[bub_i].symbol, node[bub_j].symbol);

					node[bub_j].p = bub_dummy.p;
					strcpy_s(node[bub_j].symbol, bub_dummy.symbol);
				}
			}
			bub_i++;
		}

		//——————————————————————————————————————————————————————————————
		if (testflag == 1)
		{
			printf(" > 第一次排序后的结果：");
			for (i = 0; i < num; i++) //依次输入数据
			{
				printf("%s(%f), ", node[i].symbol, node[i].p);
			}
			printf("\n > 已确认\n\n");
		}
		//—————————————————————————————————————————————————————————————

		//冒泡节点链接///////////////////////////////////////////////////

		node[0].bubnext = &endnode;
		for (i = 1; i<num; i++)
		{
			node[i].bubnext = &node[i - 1]; //进行冒泡链接
		}

		//——————————————————————————————————————————————————————————————
		struct data2 *bub_link;
		bub_link = &node[num - 1];
		if (testflag == 1)
		{
			printf(" > 按冒泡链接输出的结果：");
			while (bub_link != &endnode)
			{
				printf("%s(%f), ", (*bub_link).symbol, (*bub_link).p);
				bub_link = (*bub_link).bubnext;
			}
			printf("\n > 已确认\n\n");
			bub_link = &endnode;
		}
		//——————————————————————————————————————————————————————————————

		//循环部分开始///////////////////////////////////////////////////////
		struct data2 *seafloor;
		seafloor = &node[num - 1];
		seafloor->bubnext = node[num - 1].bubnext;
		struct data2 sum[M]; //等一下用的合成节点
		int k = 0; //合成节点数组的当前可用位置标记
		float psum = 0;
		float plus1, plus2;

		while (psum != 1)
		{
			//	4、选出概率最小的两个节点进行操作

			seafloor->code = 0; //因为已经排序，所以最后一个就是最小的
			(seafloor->bubnext)->code = 1; //倒数第二个就是次小的
			plus1 = seafloor->p;
			plus2 = seafloor->bubnext->p;
			psum = plus1 + plus2;

			//——————————————————————————————————————————————————————————————————
			if (testflag == 1)
			{
				printf(" >【第%d次迭代循环】—————————————————————————————————————————\n\n", k + 1);
				printf("（1）输出当前步的一位编码：");
				printf("%d(%f)，%d(%f)", seafloor->code, plus1, seafloor->bubnext->code, plus2);
				printf("\n > 已确认\n\n");

				printf("（2）输出概率计算过程：");
				printf("%s(%f) + %s(%f) = 合成量(%f)", seafloor->symbol, plus1, seafloor->bubnext->symbol, plus2, psum);
				printf("\n > 已确认\n\n");
			}
			//——————————————————————————————————————————————————————————————————

			if (psum == 1)
			{
				seafloor->next = &endnode;
				seafloor->bubnext->next = &endnode;
				break;
			}
			else //新节点生成
			{
				sum[k].p = psum; //和概率 【?????】为什么这一句没法给sum[k].p赋上值？
				seafloor->next = &sum[k]; //将概率最小的节点的next链接到新节点
				seafloor->bubnext->next = &sum[k]; //将概率次小的节点的next也链接到新节点
				sum[k].bubnext = seafloor->bubnext->bubnext; //将新节点和概率次小的节点的下一个冒泡点相连
				seafloor = &sum[k]; //改变冒泡起点，相当于把处理过的两个点踢出了冒泡集合
				k++; //这个k已经用过了，换下一个
			}

			//——————————————————————————————————————————————————————————————————
			struct data2 *bub_link;
			bub_link = seafloor;
			bub_link->bubnext = seafloor->bubnext;
			if (testflag == 1)
			{
				printf("（3）输出新节点sum[%d]：", k - 1);
				printf("%s(%f)", sum[k - 1].symbol, sum[k - 1].p);
				printf("\n > 已确认\n\n");

				printf("（4）连入新节点后，冒泡链接输出的结果：");
				while (bub_link != &endnode)
				{
					printf("%s(%f), ", bub_link->symbol, bub_link->p);
					bub_link = bub_link->bubnext;
				}
				printf("\n > 已确认\n\n");
			}
			//——————————————————————————————————————————————————————————————————

			//新节点作单次冒泡处理///////////////////////////////////////////////////
			struct data2 *newnode; //始终指向新节点
			newnode = seafloor;
			struct data2 *comp; //记录当前正在比较的节点
			comp = seafloor->bubnext; //初始化
			struct data2 *dummy1; //用于临时储存在海底上一层的节点位置
			dummy1 = (struct data2 *)malloc(sizeof(struct data2));
			int seaflag = 1; //用于判断是不是第一次换海底位置，应该只有第一次需要换一下海底
			while (comp != &endnode)
			{
				if ((comp->p)<(newnode->p))
				{
					if (seaflag == 1)
					{
						seafloor = comp;
						seaflag = 0;
					}
					dummy1->bubnext = comp;
					newnode->bubnext = comp->bubnext;
					comp->bubnext = newnode;
					dummy1 = comp;
					comp = newnode->bubnext;
				}
				else
				{
					break; //没有换位，因为更高的水面是有序的，所以不用比了
				}
			}

			//————————————————————————————————————————————————————————————————
			if (testflag == 1)
			{
				printf("（5）新节点冒泡后，冒泡链接输出的结果：");
				bub_link = seafloor;
				while (bub_link != &endnode)
				{
					printf("%s(%f), ", bub_link->symbol, bub_link->p);
					bub_link = bub_link->bubnext;
				}
				printf("\n > 已确认\n\n");
			}
			//————————————————————————————————————————————————————————————————
		}
		//循环部分结束//////////////////////////////////////////////////////////////

		//将编好的码字整理，入word栈/////////////////////////////////////////////////
		struct data2 *now;
		int load_code;
		for (i = num - 1; i >= 0; i--)
		{
			now = &node[i];
			now->next = node[i].next;
			while (now->code != 2)
			{
				load_code = now->code;
				node[i].word.bit[node[i].word.top] = load_code;
				node[i].word.top++;
				now = now->next;
			}
			printf("\n");
		}
		//将整理好的码字输出////////////////////////////////////////////////////////
		printf("——————————————————————————————————————————\n\n\n\n\n\n【最终编码结果】：\n\n");
		for (i = 0; i<num; i++) //每次循环都是不同的符号
		{
			printf(" >【%s】的编码为：", node[i].symbol);
			node[i].word.top--;
			while ((node[i].word).top >= 0) //每次循环都是同一符号码字的不同位
			{
				printf("%d", node[i].word.bit[node[i].word.top]);
				node[i].word.top--;
			}
			printf("\n\n");
		}
	}

	printf("\n");
	system("pause");
	return 0;
}