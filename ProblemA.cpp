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
		while(t)                       //�������ַ����� 
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








/*01����

Time Limit:1000MS  Memory Limit:32767K
Total Submit:227 Accepted:131

Description

�����Ӷ������Ż��ǲ�����,��������һ�ּ��ܷ�ʽ�����ܷ�ʽ���£� 
��Ҷ�֪�������ڼ�����ﶼ�Զ��������洢�������ַ�'a'���ڴ�洢��ʽΪ��10000110���������ʽ������������ '1'��Ȼ����������Կ������ܣ���Կֻ��'0'��'1'��'0'��ʾż�жϣ�'1'��ʾ���жϣ�������ַ�'a'���ܵ���ԿΪ'0',��������ż�жϣ�����һ��'1'��ʹ����ż����'1'��������'1'����������ԿΪ'1',��������жϣ����'0'��

Input

���������ж��飬��һ������һ���ַ���(�ַ�������С��1000)���ڶ���������Կ,'0'��'1'��

Output

���ַ����е�ÿ���ַ��������Ϲ���Ĳ���������������01���ܴ���

Sample Input


a1
0
abcd1234
1
Sample Output


11
00100010
Hint

�Ͽν��� (���Ҽ���ѡ��Ŀ�����Ϊ) 
�û��� (���Ҽ���ѡ��Ŀ�����Ϊ���ļ���չ��Ϊ.xls���������������������ļ�) 
�ύ��Ŀ������ (���Ҽ���ѡ��Ŀ�����Ϊ���ļ���չ��Ϊ.xls���������������������ļ�) 
��ӭʹ�� MinGWStudio������ */
