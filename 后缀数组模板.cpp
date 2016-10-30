// 朴素的后缀树组构造算法
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// 表示一个后缀，index是后缀的开始下标位置
struct suffix
{
    int index;
    char *suff;
};

// 字典序比较后缀
int cmp(struct suffix a, struct suffix b)
{
    return strcmp(a.suff, b.suff) < 0? 1 : 0;
}

// 构造txt的后缀数组
int *buildSuffixArray(char *txt, int n)
{
    //结果
    struct suffix suffixes[n];

    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].suff = (txt+i);
    }

    // 排序
    sort(suffixes, suffixes+n, cmp);

    // 排在第几的是谁
    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;

    return  suffixArr;
}

//打印
void printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    char txt[] = "banana";
    int n = strlen(txt);
    int *suffixArr = buildSuffixArray(txt,  n);
    cout << "Following is suffix array for " << txt << endl;
    printArr(suffixArr, n);
    return 0;
}
