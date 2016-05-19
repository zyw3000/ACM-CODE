#include <iostream>
#include <string.h>
using namespace std;

void change(char a[],int n,int miyao)
{
	int i,t,count;
	int j = 0;
	int result[1000];
	for(i = 0;i<n;i++)
	{
		count = 0;
		t = a[i];
		while(t)                       //将单个字符加密 
		{
			count++;
			t = t&(t-1);
		}
		if(miyao==1)
		{
			if(count%2 == 0)
			{
				result[j++] = 1;
			}
			else
			{
				result[j++] = 0;
			}
		}
		else
		{
			if(count%2 == 0)
			{
				result[j++] = 0;
			}
			else
			{
				result[j++] = 1;
			}
		}
		
	}
	for(i = 0;i<j;i++)
	{
		cout<<result[i];
	}
	cout<<endl;
}

int main()
{
	int miyao;
	char input[1000];
	memset(input,0,1000);
	while(cin>>input)
	{
		cin>>miyao;
		change(input,strlen(input),miyao);
		memset(input,0,strlen(input));
	}
	return 0;
}








/*01加密

Time Limit:1000MS  Memory Limit:32767K
Total Submit:227 Accepted:131

Description

红胖子对密码门还是不放心,最近又想出一种加密方式，加密方式如下： 
大家都知道数据在计算机里都以二进制数存储，比如字符'a'，内存存储形式为：10000110，在这个形式中它有奇数个 '1'。然后我们用密钥对其加密，密钥只有'0'或'1'，'0'表示偶判断，'1'表示奇判断，假如对字符'a'加密的密钥为'0',则对其进行偶判断，加上一个'1'，使其有偶数个'1'，因此输出'1'。若它的密钥为'1',则进行奇判断，输出'0'。

Input

输入数据有多组，第一行输入一个字符串(字符串长度小于1000)，第二行输入密钥,'0'或'1'。

Output

对字符串中的每个字符进行如上规则的操作，输出操作后的01加密串。

Sample Input


a1
0
abcd1234
1
Sample Output


11
00100010
Hint

上课讲稿 (请右键，选择目标另存为) 
用户名 (请右键，选择目标另存为，文件扩展名为.xls，保存类型下拉框：所有文件) 
提交题目的数量 (请右键，选择目标另存为，文件扩展名为.xls，保存类型下拉框：所有文件) 
欢迎使用 MinGWStudio编译器 */
