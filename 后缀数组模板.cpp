// ���صĺ�׺���鹹���㷨
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// ��ʾһ����׺��index�Ǻ�׺�Ŀ�ʼ�±�λ��
struct suffix
{
    int index;
    char *suff;
};

// �ֵ���ȽϺ�׺
int cmp(struct suffix a, struct suffix b)
{
    return strcmp(a.suff, b.suff) < 0? 1 : 0;
}

// ����txt�ĺ�׺����
int *buildSuffixArray(char *txt, int n)
{
    //���
    struct suffix suffixes[n];

    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].suff = (txt+i);
    }

    // ����
    sort(suffixes, suffixes+n, cmp);

    // ���ڵڼ�����˭
    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;

    return  suffixArr;
}

//��ӡ
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
