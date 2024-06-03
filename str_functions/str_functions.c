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
    p = s1;   //找到第一个和首字母相同的元素的地址
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
        printf("%s", ret);  //这里会打印出 huawei.com  因为找到地址后打印会一直打印到\0
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


//strtok 
//切割字符串
int main()
{
    const char* sep = "@.";     // 将你要分割的所有符号全放sep中
    char email[] = "asdfs@fahhauis.cfdom";  // 要分割的字符串
    char ep[30] = { 0 };
    strcpy(ep, email);  //strtok是一个很怪的函数，它会将你要分割的符号变成\0即上面的 (@ .) 会变成\0这样如果直接对原字符串使用的话，就会改变原字符串，所以一般先将原字符串拷贝到其他数组里

    char* ret = strtok(ep, sep);
    printf("%s\n", ret);  //asdfs\0fahhauis.cfdom

    ret = strtok(NULL, sep);
    printf("%s\n", ret);  //asdfs\0 fahhauis\0cfdom

    ret = strtok(NULL, sep);
    printf("%s\n", ret);  //asdfs\0fahhauis\0 cfdom

    //巧妙运用for循环
    for (ret = strtok(ep, sep); ret != NULL; ret = strtok(NULL, sep))
    {
        printf("%s\n", ret);
    }
    return 0;
}



                         //strerror
              //返回错误码，所对应的错误信息
// C语言的库函数，在执行失败的时候，都会设置错误码
#include <errno.h>
int main()
{

    // errno - C语言设置的一个全局的错误码存放的变量  要引用头文件
    FILE* pf = fopen("test.c", "r");
    if (pf == NULL)
    {
        printf("%s\n", strerror(errno));
        return 1;
    }
    else
    {

    }
    return 0;
}
