#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdilb.h>
#include <string.h>
#include <assert.h>
char* my_strstr(const char* str1, const char* str2)
{
    assert(str1 && str2);
    const char* s1 = str1;
    const char* s2 = str2;
    char* p = s1;
    while (*s1 != *s2)
    {
        s1++;
    }
    p = s1;
    while (*p)
    {
        s1 = p;
        s2 = str2;
        while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
        {
            s1++;
            s2++;
        }
        if (*s2 == '\0')
        {
            return p;
        }
        p++;
    }
    return NULL;
}
int main()
{
    char arr1[] = "abbbcddfg";
    char arr2[] = "bcd1";
    char* ret = my_strstr(arr1, arr2);  //����ҵ��˻᷵���ִ��ڲ��Ҵ�����Ԫ�صĵ�ַ���Ҳ����򷵻ؿմ�����NULL
    if (ret == NULL)
    {
        printf("�ִ�������\n");
    }
    else
    {
        printf("%s", ret);  //��ӡhuawei.com  ��Ϊ�ҵ���ַ���ӡ��һֱ��ӡ��\0
    }
    return 0;
}


//strcat
//�ַ���׷��
//Դ�ַ���������\0��β
//Ŀ��ռ�������㹻��Ŀռ䣬������Դ�ַ���������
//Ŀ��ռ������޸�
int main()
{
    char arr[20] = "hello ";
    strcat(arr, "world");
    printf("%s", arr);  //��ӡhello world
    return 0;
}
#include <assert.h>
char* my_strcat(char* dest, const char* sourse)
{
    assert(dest && sourse);
    char* ret = dest;
    //���ҵ�Ŀ���ַ����Ľ�β
    while (*dest != '\0')
    {
        dest++;
    }
    //�ҵ��󿽱���ȥ
    while (*dest++ = *sourse++)
    {
        ;
    }
    return ret;

}
int main()
{
    char arr[20] = "hello ";
    my_strcat(arr, "world");
    //�������Լ����Լ�׷�ӣ���Ϊ����׷�ӵĻ��Ŀ���ַ�����β��\0���ǣ�������ѭ��
    printf("%s", arr);  //��ӡhello world
    return 0;
}



//strcmp
//�Ƚ��ַ���
int main()
{
    char arr1[] = "afdsffas";
    char arr2[] = "asdfdsfa";
    int ret = strcmp(arr1, arr2); 
    if (ret != 0)
    {
        printf("������");
    }
    else
    {
        printf("==");
    }
    return 0;
}
#include <assert.h>
#include <string.h>
int my_strcmp(const char* str1, const char* str2)
{
    assert(str1 && str2);
    while (*str1 == *str2)
    {
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
    if (*str1 > *str2)
        return 1;
    else
        return -1;
}
int main()
{
    char arr1[] = "afdsffas";
    char arr2[] = "asdfdsfa";
    int ret = my_strcmp(arr1, arr2);
    if (ret != 0)
    {
        printf("������");
    }
    else
    {
        printf("==");
    }
    return 0;
}