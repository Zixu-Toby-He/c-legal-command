#include <stdio.h>
#include <stdlib.h>

int isTheCommondIllegal(char* commond)
{
	int toReturn;
	toReturn=system(commond);
	system("cls");
	return toReturn;
}

int main()
{
	char cmd[10]="python /?";
	int isPythonIllegal;
	isPythonIllegal = isTheCommondIllegal(cmd);
	if (isPythonIllegal)
	{
		puts("你现在还不能运行这个程序，你还需要经历以下步骤才能运行这个程序\n"
			"\t1. 在https://www.python.org/ 下载“python 3.9.13”并安装（更新版本不保证兼容但应该问题不大）\n"
			"\t2. 安装“numpy”包（https://blog.csdn.net/weixin_39773158/article/details/109925138）\n"
			"\t3. 安装“matplotlib”包（https://blog.csdn.net/weixin_45272908/article/details/118530431）\n"
			"\n"
			"若不希望这么麻烦的话可以在 https://www.anaconda.com/ 点击“Download”绿色按钮下载“Anaconda”并安装\n"
			"\t当你点击“程序运行.py”文件并弹出选择打开方式时请选择python");
	}
	else
	{
		puts("你已经安装python，请直接打开“程序运行.py”开始运行\n\n顺带一提，你的python版本如下");
		system("python --version");
		putchar('\n');
	}
	system("pause");
	return EXIT_SUCCESS;
}