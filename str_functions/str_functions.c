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
    char arr1[] = "www.huawei.com";
    char arr2[] = "huawei";
    char* ret = my_strstr(arr1, arr2);  //如果找到了会返回字串在查找串中首元素的地址，找不到则返回空串，即NULL
    if (ret == NULL)
    {
        printf("字串不存在\n");
    }
    else
    {
        printf("%s", ret);  //打印huawei.com  因为找到地址后打印会一直打印到\0
    }
    return 0;
}


//strcat
//字符串追加
//源字符串必须以\0结尾
//目标空间必须有足够大的空间，能容下源字符串的内容
//目标空间必须可修改
int main()
{
    char arr[20] = "hello ";
    strcat(arr, "world");
    printf("%s", arr);  //打印hello world
    return 0;
}
#include <assert.h>
char* my_strcat(char* dest, const char* sourse)
{
    assert(dest && sourse);
    char* ret = dest;
    //先找到目标字符串的结尾
    while (*dest != '\0')
    {
        dest++;
    }
    //找到后拷贝过去
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
    //不可以自己给自己追加，因为后面追加的会把目标字符串结尾的\0覆盖，导致死循环
    printf("%s", arr);  //打印hello world
    return 0;
}



//strcmp
//比较字符串
int main()
{
    char arr1[] = "afdsffas";
    char arr2[] = "asdfdsfa";
    int ret = strcmp(arr1, arr2); 
    if (ret != 0)
    {
        printf("不等于");
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
        printf("不等于");
    }
    else
    {
        printf("==");
    }
    return 0;
}
