#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    char data[20];          //指名字
    struct Node *next;
}Node;

//把每一个文件夹看成一个头结点，存放在指针数组里
int v = 0;                   //定义全局变量v便于创建文件夹
Node *a[100] = {NULL};       //定义一个指针数组指向各个文件夹

void caidan1()      //输出菜单
{
    printf("\n\n\t              选择式菜单\n");
    printf("\t+====================================+\n");
    printf("\t+                                    +\n");
    printf("\t+        1：建立文件夹               +\n");
    printf("\t+                                    +\n");
    printf("\t+        2：查看文件夹               +\n");
    printf("\t+                                    +\n");
    printf("\t+        3：删除文件夹               +\n");
    printf("\t+                                    +\n");
    printf("\t+        4：对文件操作               +\n");
    printf("\t+                                    +\n");
    printf("\t+        0：退出程序                 +\n");
    printf("\t+                                    +\n");
    printf("\t+====================================+\n");
}

void caidan2()      //输出对文件操作菜单
{
    printf("\n\n\t+====================================+\n");
    printf("\t+                                    +\n");
    printf("\t+         1：创建文件                +\n");
    printf("\t+                                    +\n");
    printf("\t+         2：删除文件                +\n");
    printf("\t+                                    +\n");
    printf("\t+         3：显示某文件夹中的文件    +\n");
    printf("\t+                                    +\n");
    printf("\t+         4：对文件内容操作          +\n");
    printf("\t+                                    +\n");
    printf("\t+         0：返回上层操作            +\n");
    printf("\t+                                    +\n");
    printf("\t+====================================+\n");
}

void caidan3()
{
    printf("\n\n\t===============================================================\n");
    printf("\t 1-读取代码信息  2-增加一行代码  3-删除一行代码  4-修改一行代码\n");
    printf("\t 5-按代码查找    6-按标号查      0-返回上层操作\n");
    printf("\t===============================================================\n");
}

int search_wenjianjia(char temp1[])        //根据文件夹名称搜索文件夹
{
    int i;                     //寻找所在的文件夹,即头结点
    for (i = 0; i < v; i++)
    {
        if (a[i] != NULL && strcmp(a[i]->data, temp1) == 0)
            return i;       //搜索成功返回文件夹的位置
    }
    if (i == v)
    {
        return -1;   //搜索失败返回-1
    }
}

Node *search_wenjian(int i, char temp2[])    //根据文件夹位置和文件名称搜索文件
{
    Node *q = a[i];
    while (q->next != NULL)
    {
        if (strcmp(q->next->data, temp2) == 0)
            return q;                           //文件存在返回上一结点
        else
            q = q->next;
    }
    return NULL;                       //文件不存在返回NULL

}

void create_folio()   //建立文件夹
{
    printf("请输入你要建立的文件夹的名称:");
    Node *head  = (Node*)malloc(sizeof(Node));
    gets(head->data);
    if (search_wenjianjia(head->data) != -1)    //判断是否已经存在同名文件夹
    {
        printf("此文件夹已存在\n");
        return;
    }
    a[v] = head;
    a[v]->next = NULL;
    v++;
}

void look_folio()     //查看文件夹
{
    printf("文件夹如下所示：\n");
    int i, s = 1;           //s用来判断是否有文件夹
    for (i = 0; i < v; i++)
    {
            if (a[i]->data != NULL)
            {
                printf("%s  ",a[i]->data);
                s = 0;
            }
    }
    if ( s == 1)
        printf("无文件夹\n");
    printf("\n");
}

void delete_folio()     //删除文件夹
{
    printf("请输入你要删除的文件夹名称:");
    char temp1[20];
    gets(temp1);
    int i = search_wenjianjia(temp1);   //搜索文件夹位置
    if (i == -1)
        printf("此文件夹不存在\n");
    else
    {
        free(a[i]);
        a[i] = NULL;
    }
}

void create_file()         //创建文件
{
    char  ch, temp1[20], temp2[20];  // temp1为文件夹名字，temp2为文件名字。
    printf("请输入你要创建的文件所在文件夹的名字：");
    gets(temp1);

    int i = search_wenjianjia(temp1);       //判断输入的文件夹是否存在
    if (i == -1)
    {
        printf("输入的文件夹不存在\n");
        return;
    }

    printf("请输入你要创建的文件的名字：");
    gets(temp2);

    if (search_wenjian(i, temp2) != NULL)     //判断输入的文件名是否已经存在
    {
        printf("输入的文件名已存在\n");
        return;
    }

    FILE *t;
    if ((t = fopen(temp2, "w")) == NULL)    //打开输出文件并使t指向此文件
    {
        printf("无法打开此文件\n");
        return ;
    }

    printf("请输入文件内容（以$结束）\n");
    ch = getchar();
    while (ch != '$')
    {
        fputc(ch,t);
        ch = getchar();
    }

    Node *p = (Node *)malloc(sizeof(Node));
    Node *q;
    q = a[i];
    strcpy(p->data, temp2);     //传递文件名字
    p->next = NULL;
    while (q->next != NULL)  //把该文件放在链表的后面
    {
        q = q->next;
    }
    q->next = p;
    fclose(t);          //关闭文件
}

void delete_file()          //删除文件
{
    char temp1[20], temp2[20];      // 分别存放文件夹名和文件名
    printf("请输入你要删除的文件所在文件夹的名字：");
    gets(temp1);

    int i = search_wenjianjia(temp1);   //查找文件夹位置并判断文件夹是否存在
    if (i == -1)
    {
        printf("输入的文件夹不存在\n");
        return;
    }

    printf("请输入你要删除的文件的名字：");
    gets(temp2);

    Node *p = search_wenjian(i, temp2);        //搜索文件位置同时判断要删除的文件是否存在
    if(p == NULL)
    {
        printf("输入的文件名不存在，无法删除\n");
        return;
    }

    Node *q;
    q = p->next;
    p->next = p->next->next;
    if (remove(q->data) == 0)      //判断是否删除成功
        printf("删除成功\n");
    else
        printf("删除失败\n");
    free(q);
    q = NULL;
}

void show_file()         //显示某文件夹中的文件
{
    char temp1[20];
    printf("请输入你要显示的文件夹的名字：");
    gets(temp1);

    int i = search_wenjianjia(temp1);       //搜索并判断文件夹是否存在
    if (i == -1)
    {
        printf("输入的文件夹不存在\n");
        return;
    }

    Node *p = a[i];
    if (p->next == NULL)        //判断该文件夹是否为空
    {
        printf("该文件夹下不存在文件\n");
        return;
    }

    printf("该文件夹下的文件分别为：\n");   //输出该文件夹下所有文件
    while (p->next != NULL)
    {
        printf("%s  ",p->next->data);
        p = p->next;
    }
    printf("\n");
}

void read_file()    //读取代码信息，把一个文件的信息输出出来
{
    char temp1[20], temp2[20];
    printf("请输入你要读取文件所在的文件夹名：");
    gets(temp1);

    int i = search_wenjianjia(temp1);       //搜索并判断文件夹是否存在
    if (i == -1)
    {
        printf("输入的文件夹不存在\n");
        return;
    }

    printf("请输入你要读取的文件名：");
    gets(temp2);

    Node *p = search_wenjian(i, temp2);
    if (p == NULL)     //判断要读取的文件是否存在
    {
        printf("要读取的文件不存在\n");
        return;
    }

    char ch;        //读取文件
    FILE *fp;
    if((fp=fopen(p->next->data,"r"))==NULL)
    {
        printf("file cannot be opened\n");
        return;
    }
    while((ch = fgetc(fp)) != EOF)
        printf("%c", ch);
    fclose(fp);
}

void copy_file(char temp1[], char temp2[])            //把一个文件的东西复制到另一个文件中
{
    FILE *in, *out;
    char ch;
    if ((in = fopen(temp1,"r")) == NULL)
    {
        printf("无法打开此文件\n");
        return;
    }
    if ((out = fopen(temp2,"w")) == NULL)
    {
        printf("无法打开此文件\n");
        return;
    }
    while (!feof(in))         //如果未遇到输入文件的结束标志
    {
        ch=fgetc(in);         //从输入文件中读入一个字符，暂时放在变量ch中
        fputc(ch,out);        //将ch写到输出文件中
    }
    fclose(in);
    fclose(out);
}

int judge_hanghao(char temp[], int x)        //按行操作时判断输入的行号是否正确
{
    FILE *fp;
    if ((fp = fopen(temp, "r")) == NULL)
    {
        printf("无法打开此文件\n");
        return;
    }
    char buf[1000];
    int linecnt = 0;                   //用来记录行号
    while (fgets(buf, 1000, fp)) // fgets循环读取，直到文件最后，才会返回NULL
        linecnt++; // 累计行数
    fclose(fp);
    if (x > linecnt)
        return 0;
    return 1;
}

void add_a_line_code()        //增加一行代码
{
    char temp1[20], temp2[20];     // 分别为文件夹名称  文件名称
    printf("请输入你要操作的文件所在的文件夹名称：");
    gets(temp1);

    int i = search_wenjianjia(temp1);       //搜索并判断文件夹是否存在
    if (i == -1)
    {
        printf("输入的文件夹不存在\n");
        return;
    }

    printf("请输入你要操作的文件名：");
    gets(temp2);

    Node *p = search_wenjian(i, temp2);     //p为文件的上一结点
    if (p == NULL)        //判断要读取的文件是否存在
    {
        printf("要读取的文件不存在\n");
        return;
    }

    int x;              //  表示在第几行增加代码
    printf("你要在第几行增加代码：");
    scanf("%d", &x);
    getchar();

    if (judge_hanghao(p->next->data, x - 1) == 0)   //判断输入的行号是否正确
    {
        printf("输入的行号错误\n");
        return;
    }

    char temp3[100];    //存放要增加的代码
    printf("请输入你要增加的一行代码:");
    gets(temp3);

    FILE *fp1, *fp2;                //把一个文件的东西复制到另一个文件中
    copy_file(p->next->data, "temp_file");

    if((fp1=fopen(p->next->data,"w"))==NULL)
    {
        printf("file cannot be opened\n");
        return;
    }
    if((fp2=fopen("temp_file","r"))==NULL)
    {
        printf("file cannot be opened\n");
        return;
    }

    char str[256] = {0};
    int t = 0;          //用来计算行号
    while(t < x - 1)        //复制x行前面的部分
    {
        fgets(str, 256, fp2);
        fputs(str, fp1);
        t++;
    }

    fputs(temp3, fp1);      //输入增加的一行
    fputs("\n", fp1);

    while (fgets(str, 256, fp2) != NULL)      //复制剩下的部分
    {
        fputs(str, fp1);
    }
    fclose(fp1);
    fclose(fp2);
    remove("temp_file");
}

void delete_a_line_code()      //删除一行代码
{
    char temp1[20], temp2[20];     // 分别为文件夹名称  文件名称
    printf("请输入你要操作的文件所在的文件夹名称：");
    gets(temp1);

    int i = search_wenjianjia(temp1);       //搜索并判断文件夹是否存在
    if (i == -1)
    {
        printf("输入的文件夹不存在\n");
        return;
    }

    printf("请输入你要操作的文件名：");
    gets(temp2);

    Node *p = search_wenjian(i, temp2);     //p为文件的上一结点
    if (p == NULL)        //判断要读取的文件是否存在
    {
        printf("要读取的文件不存在\n");
        return;
    }

    int x;              //  表示在第几行删除代码
    printf("你要在第几行删除代码:");
    scanf("%d", &x);
    getchar();

    if (judge_hanghao(p->next->data, x) == 0)   //判断输入的行号是否正确
    {
        printf("输入的行号错误\n");
        return;
    }

    FILE *fp1, *fp2;                //把一个文件的东西复制到另一个文件中
    copy_file(p->next->data, "temp_file");

    if((fp1=fopen(p->next->data,"w"))==NULL)
    {
        printf("file cannot be opened\n");
        return;
    }
    if((fp2=fopen("temp_file","r"))==NULL)
    {
        printf("file cannot be opened\n");
        return;
    }

    char str[256] = {0};
    int t = 0;          //用来计算行号
    while(t < x - 1)        //复制x行前面的部分
    {
        fgets(str, 256, fp2);
        fputs(str, fp1);
        t++;
    }

    fgets(str, 256, fp2);       //取出要删除的一行

    while (fgets(str, 256, fp2) != NULL)      //复制剩下的部分
    {
        fputs(str, fp1);
    }
    fclose(fp1);
    fclose(fp2);
    remove("temp_file");
}

void change_a_line_code()   //修改一行代码
{
    char temp1[20], temp2[20];     // 分别为文件夹名称  文件名称
    printf("请输入你要操作的文件所在的文件夹名称：");
    gets(temp1);

    int i = search_wenjianjia(temp1);       //搜索并判断文件夹是否存在
    if (i == -1)
    {
        printf("输入的文件夹不存在\n");
        return;
    }

    printf("请输入你要操作的文件名：");
    gets(temp2);

    Node *p = search_wenjian(i, temp2);     //p为文件的上一结点
    if (p == NULL)        //判断要读取的文件是否存在
    {
        printf("要读取的文件不存在\n");
        return;
    }

    int x;              //  表示在第几行修改代码
    printf("你要在第几行修改代码：");
    scanf("%d", &x);
    getchar();

    if (judge_hanghao(p->next->data, x) == 0)   //判断输入的行号是否正确
    {
        printf("输入的行号错误\n");
        return;
    }

    char temp3[100];    //存放要修改的代码
    printf("请输入你想修改成的一行代码:");
    gets(temp3);

    FILE *fp1, *fp2;                //把一个文件的东西复制到另一个文件中
    copy_file(p->next->data, "temp_file");

    if((fp1=fopen(p->next->data,"w"))==NULL)
    {
        printf("file cannot be opened\n");
        return;
    }
    if((fp2=fopen("temp_file","r"))==NULL)
    {
        printf("file cannot be opened\n");
        return;
    }

    char str[256] = {0};
    int t = 0;          //用来计算行号
    while(t < x - 1)        //复制x行前面的部分
    {
        fgets(str, 256, fp2);
        fputs(str, fp1);
        t++;
    }

    fputs(temp3, fp1);      //输入修改的一行
    fputs("\n", fp1);

    fgets(str, 256, fp2);       //取出原来的这一行

    while (fgets(str, 256, fp2) != NULL)      //复制剩下的部分
    {
        fputs(str, fp1);
    }
    fclose(fp1);
    fclose(fp2);
    remove("temp_file");
}

void search_code()        //按代码查找
{
    char temp1[20], temp2[20];     // 分别为文件夹名称  文件名称
    printf("请输入你要操作的文件所在的文件夹名称：");
    gets(temp1);

    int i = search_wenjianjia(temp1);       //搜索并判断文件夹是否存在
    if (i == -1)
    {
        printf("输入的文件夹不存在\n");
        return;
    }

    printf("请输入你要操作的文件名：");
    gets(temp2);

    Node *p = search_wenjian(i, temp2);     //p为文件的上一结点
    if (p == NULL)        //判断要读取的文件是否存在
    {
        printf("要读取的文件不存在\n");
        return;
    }

    char temp3[100];    //存放要查找的代码
    printf("请输入你要查找的一行代码:");
    gets(temp3);

    FILE *fp1;
    if((fp1=fopen(p->next->data,"r"))==NULL)
    {
        printf("file cannot be opened\n");
        return;
    }

    int j = 0,len1, len2;
    len1 = strlen(temp3);       //  len1为要查找的代码的长度
    char str[256] = {0};
    printf("查找到的结果为：\n");
    int s = 0, t = 1;           //s用来判断是否查找到该代码，t用来计录行数
    while(fgets(str, 256, fp1))         //依次取出一行搜索
    {
        i = 0; j = 0;
        len2 = strlen(str);         //len2为取出的一行代码的长度
        for (; i < len2; )
        {
            if (str[i] == temp3[j])
            {
                i++;
                j++;
            }
            if (j == len1)
            {
                s = 1;
                printf("第%d行：%s", t, str);
                break;
            }
            if (str[i] != temp3[j])
            {
                i++;
                j = 0;
            }
        }
        t++;
    }
    if (s == 0)
        printf("未查找到该代码\n");
    fclose(fp1);
}

void search_biaohao()      //按标号查找
{
    char temp1[20], temp2[20];     // 分别为文件夹名称  文件名称
    printf("请输入你要操作的文件所在的文件夹名称：");
    gets(temp1);

    int i = search_wenjianjia(temp1);       //搜索并判断文件夹是否存在
    if (i == -1)
    {
        printf("输入的文件夹不存在\n");
        return;
    }

    printf("请输入你要操作的文件名：");
    gets(temp2);

    Node *p = search_wenjian(i, temp2);     //p为文件的上一结点
    if (p == NULL)        //判断要读取的文件是否存在
    {
        printf("要读取的文件不存在\n");
        return;
    }

    printf("请输入你要查找的标号：");      //即查找第几行
    int x;
    scanf("%d", &x);
    getchar();

    FILE *fp1;
    if((fp1=fopen(p->next->data,"r"))==NULL)
    {
        printf("file cannot be opened\n");
        return;
    }

    int t = 1, s = 0;           //s用来判断是否查找到该代码，t用来计录行数
    char str[256] = {0};
    printf("查找结果为：\n");
    while (fgets(str, 256, fp1) != NULL)        //按标号查找
    {
        if (x == t)
        {
            s = 1;
            printf("第%d行：%s", t, str);
            break;
        }
        t++;
    }
    if (s == 0)
        printf("输入的标号错误，未查到结果\n");
    fclose(fp1);
}

void neirongcaozuo()     //对文件内容操作选择
{
    while (1)
    {
        printf("\n请输入你要进行的操作：");
        int ch;
        scanf("%d",&ch);
        getchar();
        switch (ch)
        {
            case 1:         //读取代码信息
            {
                read_file();
                break;
            }
            case 2:         //增加一行代码
            {
                add_a_line_code();
                break;
            }
            case 3:         //删除一行代码
            {
                delete_a_line_code();
                break;
            }
            case 4:         //修改一行代码
            {
                change_a_line_code();
                break;
            }
            case 5:         //按代码查找
            {
                search_code();
                break;
            }
            case 6:         //按标号查找
            {
                search_biaohao();
                break;
            }
            case 0:         //返回上层操作
            {
                printf("\n");
                caidan2();
                return;
            }
            default:
            {
                printf("输入有误，请重新输入\n");
                break;
            }
        }
    }
}

int wenjiancaozuo()      //对文件操作选择
{
    while (1)
    {
        printf("\n请输入你要进行的操作:");
        int ch;
        scanf("%d",&ch);
        getchar();
        switch (ch)
        {
            case 1:     //创建文件
            {
                create_file();
                break;
            }
            case 2:     //删除文件
            {
                delete_file();
                break;
            }
            case 3:     //显示某文件夹中的文件
            {
                show_file();
                break;
            }
            case 4:     //对文件内容进行操作
            {
                caidan3();
                neirongcaozuo();
                break;
            }
            case 0:     //返回上层操作
            {
                printf("\n");
                caidan1();
                return ;
            }
            default:
            {
                printf("输入有误，请重新输入\n");
                break;
            }
        }
    }
}

void wenjianjiacaozuo()         //对文件夹操作
{
    caidan1();   //输出选择菜单
    int ch;
    while (1)
    {
        printf("\n请输入你要进行的操作:");
        scanf("%d",&ch);
        getchar();
        switch (ch)
        {
            case 1:             //建立文件夹
            {
                create_folio();
                break;
            }
            case 2:             //查看文件夹
            {
                look_folio();
                break;
            }
            case 3:             //删除文件夹
            {
                delete_folio();
                break;
            }
            case 4:             //对文件操作
            {
                caidan2();
                wenjiancaozuo();
                break;
            }
            case 0:             //退出程序
                return;
            default:
            {
                printf("输入有误，请重新输入\n");
                break;
            }
        }
    }
}

int main()
{
    wenjianjiacaozuo();
    return 0;
}