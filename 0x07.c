#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    char data[20];          //ָ����
    struct Node *next;
}Node;

//��ÿһ���ļ��п���һ��ͷ��㣬�����ָ��������
int v = 0;                   //����ȫ�ֱ���v���ڴ����ļ���
Node *a[100] = {NULL};       //����һ��ָ������ָ������ļ���

void caidan1()      //����˵�
{
    printf("\n\n\t              ѡ��ʽ�˵�\n");
    printf("\t+====================================+\n");
    printf("\t+                                    +\n");
    printf("\t+        1�������ļ���               +\n");
    printf("\t+                                    +\n");
    printf("\t+        2���鿴�ļ���               +\n");
    printf("\t+                                    +\n");
    printf("\t+        3��ɾ���ļ���               +\n");
    printf("\t+                                    +\n");
    printf("\t+        4�����ļ�����               +\n");
    printf("\t+                                    +\n");
    printf("\t+        0���˳�����                 +\n");
    printf("\t+                                    +\n");
    printf("\t+====================================+\n");
}

void caidan2()      //������ļ������˵�
{
    printf("\n\n\t+====================================+\n");
    printf("\t+                                    +\n");
    printf("\t+         1�������ļ�                +\n");
    printf("\t+                                    +\n");
    printf("\t+         2��ɾ���ļ�                +\n");
    printf("\t+                                    +\n");
    printf("\t+         3����ʾĳ�ļ����е��ļ�    +\n");
    printf("\t+                                    +\n");
    printf("\t+         4�����ļ����ݲ���          +\n");
    printf("\t+                                    +\n");
    printf("\t+         0�������ϲ����            +\n");
    printf("\t+                                    +\n");
    printf("\t+====================================+\n");
}

void caidan3()
{
    printf("\n\n\t===============================================================\n");
    printf("\t 1-��ȡ������Ϣ  2-����һ�д���  3-ɾ��һ�д���  4-�޸�һ�д���\n");
    printf("\t 5-���������    6-����Ų�      0-�����ϲ����\n");
    printf("\t===============================================================\n");
}

int search_wenjianjia(char temp1[])        //�����ļ������������ļ���
{
    int i;                     //Ѱ�����ڵ��ļ���,��ͷ���
    for (i = 0; i < v; i++)
    {
        if (a[i] != NULL && strcmp(a[i]->data, temp1) == 0)
            return i;       //�����ɹ������ļ��е�λ��
    }
    if (i == v)
    {
        return -1;   //����ʧ�ܷ���-1
    }
}

Node *search_wenjian(int i, char temp2[])    //�����ļ���λ�ú��ļ����������ļ�
{
    Node *q = a[i];
    while (q->next != NULL)
    {
        if (strcmp(q->next->data, temp2) == 0)
            return q;                           //�ļ����ڷ�����һ���
        else
            q = q->next;
    }
    return NULL;                       //�ļ������ڷ���NULL

}

void create_folio()   //�����ļ���
{
    printf("��������Ҫ�������ļ��е�����:");
    Node *head  = (Node*)malloc(sizeof(Node));
    gets(head->data);
    if (search_wenjianjia(head->data) != -1)    //�ж��Ƿ��Ѿ�����ͬ���ļ���
    {
        printf("���ļ����Ѵ���\n");
        return;
    }
    a[v] = head;
    a[v]->next = NULL;
    v++;
}

void look_folio()     //�鿴�ļ���
{
    printf("�ļ���������ʾ��\n");
    int i, s = 1;           //s�����ж��Ƿ����ļ���
    for (i = 0; i < v; i++)
    {
            if (a[i]->data != NULL)
            {
                printf("%s  ",a[i]->data);
                s = 0;
            }
    }
    if ( s == 1)
        printf("���ļ���\n");
    printf("\n");
}

void delete_folio()     //ɾ���ļ���
{
    printf("��������Ҫɾ�����ļ�������:");
    char temp1[20];
    gets(temp1);
    int i = search_wenjianjia(temp1);   //�����ļ���λ��
    if (i == -1)
        printf("���ļ��в�����\n");
    else
    {
        free(a[i]);
        a[i] = NULL;
    }
}

void create_file()         //�����ļ�
{
    char  ch, temp1[20], temp2[20];  // temp1Ϊ�ļ������֣�temp2Ϊ�ļ����֡�
    printf("��������Ҫ�������ļ������ļ��е����֣�");
    gets(temp1);

    int i = search_wenjianjia(temp1);       //�ж�������ļ����Ƿ����
    if (i == -1)
    {
        printf("������ļ��в�����\n");
        return;
    }

    printf("��������Ҫ�������ļ������֣�");
    gets(temp2);

    if (search_wenjian(i, temp2) != NULL)     //�ж�������ļ����Ƿ��Ѿ�����
    {
        printf("������ļ����Ѵ���\n");
        return;
    }

    FILE *t;
    if ((t = fopen(temp2, "w")) == NULL)    //������ļ���ʹtָ����ļ�
    {
        printf("�޷��򿪴��ļ�\n");
        return ;
    }

    printf("�������ļ����ݣ���$������\n");
    ch = getchar();
    while (ch != '$')
    {
        fputc(ch,t);
        ch = getchar();
    }

    Node *p = (Node *)malloc(sizeof(Node));
    Node *q;
    q = a[i];
    strcpy(p->data, temp2);     //�����ļ�����
    p->next = NULL;
    while (q->next != NULL)  //�Ѹ��ļ���������ĺ���
    {
        q = q->next;
    }
    q->next = p;
    fclose(t);          //�ر��ļ�
}

void delete_file()          //ɾ���ļ�
{
    char temp1[20], temp2[20];      // �ֱ����ļ��������ļ���
    printf("��������Ҫɾ�����ļ������ļ��е����֣�");
    gets(temp1);

    int i = search_wenjianjia(temp1);   //�����ļ���λ�ò��ж��ļ����Ƿ����
    if (i == -1)
    {
        printf("������ļ��в�����\n");
        return;
    }

    printf("��������Ҫɾ�����ļ������֣�");
    gets(temp2);

    Node *p = search_wenjian(i, temp2);        //�����ļ�λ��ͬʱ�ж�Ҫɾ�����ļ��Ƿ����
    if(p == NULL)
    {
        printf("������ļ��������ڣ��޷�ɾ��\n");
        return;
    }

    Node *q;
    q = p->next;
    p->next = p->next->next;
    if (remove(q->data) == 0)      //�ж��Ƿ�ɾ���ɹ�
        printf("ɾ���ɹ�\n");
    else
        printf("ɾ��ʧ��\n");
    free(q);
    q = NULL;
}

void show_file()         //��ʾĳ�ļ����е��ļ�
{
    char temp1[20];
    printf("��������Ҫ��ʾ���ļ��е����֣�");
    gets(temp1);

    int i = search_wenjianjia(temp1);       //�������ж��ļ����Ƿ����
    if (i == -1)
    {
        printf("������ļ��в�����\n");
        return;
    }

    Node *p = a[i];
    if (p->next == NULL)        //�жϸ��ļ����Ƿ�Ϊ��
    {
        printf("���ļ����²������ļ�\n");
        return;
    }

    printf("���ļ����µ��ļ��ֱ�Ϊ��\n");   //������ļ����������ļ�
    while (p->next != NULL)
    {
        printf("%s  ",p->next->data);
        p = p->next;
    }
    printf("\n");
}

void read_file()    //��ȡ������Ϣ����һ���ļ�����Ϣ�������
{
    char temp1[20], temp2[20];
    printf("��������Ҫ��ȡ�ļ����ڵ��ļ�������");
    gets(temp1);

    int i = search_wenjianjia(temp1);       //�������ж��ļ����Ƿ����
    if (i == -1)
    {
        printf("������ļ��в�����\n");
        return;
    }

    printf("��������Ҫ��ȡ���ļ�����");
    gets(temp2);

    Node *p = search_wenjian(i, temp2);
    if (p == NULL)     //�ж�Ҫ��ȡ���ļ��Ƿ����
    {
        printf("Ҫ��ȡ���ļ�������\n");
        return;
    }

    char ch;        //��ȡ�ļ�
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

void copy_file(char temp1[], char temp2[])            //��һ���ļ��Ķ������Ƶ���һ���ļ���
{
    FILE *in, *out;
    char ch;
    if ((in = fopen(temp1,"r")) == NULL)
    {
        printf("�޷��򿪴��ļ�\n");
        return;
    }
    if ((out = fopen(temp2,"w")) == NULL)
    {
        printf("�޷��򿪴��ļ�\n");
        return;
    }
    while (!feof(in))         //���δ���������ļ��Ľ�����־
    {
        ch=fgetc(in);         //�������ļ��ж���һ���ַ�����ʱ���ڱ���ch��
        fputc(ch,out);        //��chд������ļ���
    }
    fclose(in);
    fclose(out);
}

int judge_hanghao(char temp[], int x)        //���в���ʱ�ж�������к��Ƿ���ȷ
{
    FILE *fp;
    if ((fp = fopen(temp, "r")) == NULL)
    {
        printf("�޷��򿪴��ļ�\n");
        return;
    }
    char buf[1000];
    int linecnt = 0;                   //������¼�к�
    while (fgets(buf, 1000, fp)) // fgetsѭ����ȡ��ֱ���ļ���󣬲Ż᷵��NULL
        linecnt++; // �ۼ�����
    fclose(fp);
    if (x > linecnt)
        return 0;
    return 1;
}

void add_a_line_code()        //����һ�д���
{
    char temp1[20], temp2[20];     // �ֱ�Ϊ�ļ�������  �ļ�����
    printf("��������Ҫ�������ļ����ڵ��ļ������ƣ�");
    gets(temp1);

    int i = search_wenjianjia(temp1);       //�������ж��ļ����Ƿ����
    if (i == -1)
    {
        printf("������ļ��в�����\n");
        return;
    }

    printf("��������Ҫ�������ļ�����");
    gets(temp2);

    Node *p = search_wenjian(i, temp2);     //pΪ�ļ�����һ���
    if (p == NULL)        //�ж�Ҫ��ȡ���ļ��Ƿ����
    {
        printf("Ҫ��ȡ���ļ�������\n");
        return;
    }

    int x;              //  ��ʾ�ڵڼ������Ӵ���
    printf("��Ҫ�ڵڼ������Ӵ��룺");
    scanf("%d", &x);
    getchar();

    if (judge_hanghao(p->next->data, x - 1) == 0)   //�ж�������к��Ƿ���ȷ
    {
        printf("������кŴ���\n");
        return;
    }

    char temp3[100];    //���Ҫ���ӵĴ���
    printf("��������Ҫ���ӵ�һ�д���:");
    gets(temp3);

    FILE *fp1, *fp2;                //��һ���ļ��Ķ������Ƶ���һ���ļ���
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
    int t = 0;          //���������к�
    while(t < x - 1)        //����x��ǰ��Ĳ���
    {
        fgets(str, 256, fp2);
        fputs(str, fp1);
        t++;
    }

    fputs(temp3, fp1);      //�������ӵ�һ��
    fputs("\n", fp1);

    while (fgets(str, 256, fp2) != NULL)      //����ʣ�µĲ���
    {
        fputs(str, fp1);
    }
    fclose(fp1);
    fclose(fp2);
    remove("temp_file");
}

void delete_a_line_code()      //ɾ��һ�д���
{
    char temp1[20], temp2[20];     // �ֱ�Ϊ�ļ�������  �ļ�����
    printf("��������Ҫ�������ļ����ڵ��ļ������ƣ�");
    gets(temp1);

    int i = search_wenjianjia(temp1);       //�������ж��ļ����Ƿ����
    if (i == -1)
    {
        printf("������ļ��в�����\n");
        return;
    }

    printf("��������Ҫ�������ļ�����");
    gets(temp2);

    Node *p = search_wenjian(i, temp2);     //pΪ�ļ�����һ���
    if (p == NULL)        //�ж�Ҫ��ȡ���ļ��Ƿ����
    {
        printf("Ҫ��ȡ���ļ�������\n");
        return;
    }

    int x;              //  ��ʾ�ڵڼ���ɾ������
    printf("��Ҫ�ڵڼ���ɾ������:");
    scanf("%d", &x);
    getchar();

    if (judge_hanghao(p->next->data, x) == 0)   //�ж�������к��Ƿ���ȷ
    {
        printf("������кŴ���\n");
        return;
    }

    FILE *fp1, *fp2;                //��һ���ļ��Ķ������Ƶ���һ���ļ���
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
    int t = 0;          //���������к�
    while(t < x - 1)        //����x��ǰ��Ĳ���
    {
        fgets(str, 256, fp2);
        fputs(str, fp1);
        t++;
    }

    fgets(str, 256, fp2);       //ȡ��Ҫɾ����һ��

    while (fgets(str, 256, fp2) != NULL)      //����ʣ�µĲ���
    {
        fputs(str, fp1);
    }
    fclose(fp1);
    fclose(fp2);
    remove("temp_file");
}

void change_a_line_code()   //�޸�һ�д���
{
    char temp1[20], temp2[20];     // �ֱ�Ϊ�ļ�������  �ļ�����
    printf("��������Ҫ�������ļ����ڵ��ļ������ƣ�");
    gets(temp1);

    int i = search_wenjianjia(temp1);       //�������ж��ļ����Ƿ����
    if (i == -1)
    {
        printf("������ļ��в�����\n");
        return;
    }

    printf("��������Ҫ�������ļ�����");
    gets(temp2);

    Node *p = search_wenjian(i, temp2);     //pΪ�ļ�����һ���
    if (p == NULL)        //�ж�Ҫ��ȡ���ļ��Ƿ����
    {
        printf("Ҫ��ȡ���ļ�������\n");
        return;
    }

    int x;              //  ��ʾ�ڵڼ����޸Ĵ���
    printf("��Ҫ�ڵڼ����޸Ĵ��룺");
    scanf("%d", &x);
    getchar();

    if (judge_hanghao(p->next->data, x) == 0)   //�ж�������к��Ƿ���ȷ
    {
        printf("������кŴ���\n");
        return;
    }

    char temp3[100];    //���Ҫ�޸ĵĴ���
    printf("�����������޸ĳɵ�һ�д���:");
    gets(temp3);

    FILE *fp1, *fp2;                //��һ���ļ��Ķ������Ƶ���һ���ļ���
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
    int t = 0;          //���������к�
    while(t < x - 1)        //����x��ǰ��Ĳ���
    {
        fgets(str, 256, fp2);
        fputs(str, fp1);
        t++;
    }

    fputs(temp3, fp1);      //�����޸ĵ�һ��
    fputs("\n", fp1);

    fgets(str, 256, fp2);       //ȡ��ԭ������һ��

    while (fgets(str, 256, fp2) != NULL)      //����ʣ�µĲ���
    {
        fputs(str, fp1);
    }
    fclose(fp1);
    fclose(fp2);
    remove("temp_file");
}

void search_code()        //���������
{
    char temp1[20], temp2[20];     // �ֱ�Ϊ�ļ�������  �ļ�����
    printf("��������Ҫ�������ļ����ڵ��ļ������ƣ�");
    gets(temp1);

    int i = search_wenjianjia(temp1);       //�������ж��ļ����Ƿ����
    if (i == -1)
    {
        printf("������ļ��в�����\n");
        return;
    }

    printf("��������Ҫ�������ļ�����");
    gets(temp2);

    Node *p = search_wenjian(i, temp2);     //pΪ�ļ�����һ���
    if (p == NULL)        //�ж�Ҫ��ȡ���ļ��Ƿ����
    {
        printf("Ҫ��ȡ���ļ�������\n");
        return;
    }

    char temp3[100];    //���Ҫ���ҵĴ���
    printf("��������Ҫ���ҵ�һ�д���:");
    gets(temp3);

    FILE *fp1;
    if((fp1=fopen(p->next->data,"r"))==NULL)
    {
        printf("file cannot be opened\n");
        return;
    }

    int j = 0,len1, len2;
    len1 = strlen(temp3);       //  len1ΪҪ���ҵĴ���ĳ���
    char str[256] = {0};
    printf("���ҵ��Ľ��Ϊ��\n");
    int s = 0, t = 1;           //s�����ж��Ƿ���ҵ��ô��룬t������¼����
    while(fgets(str, 256, fp1))         //����ȡ��һ������
    {
        i = 0; j = 0;
        len2 = strlen(str);         //len2Ϊȡ����һ�д���ĳ���
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
                printf("��%d�У�%s", t, str);
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
        printf("δ���ҵ��ô���\n");
    fclose(fp1);
}

void search_biaohao()      //����Ų���
{
    char temp1[20], temp2[20];     // �ֱ�Ϊ�ļ�������  �ļ�����
    printf("��������Ҫ�������ļ����ڵ��ļ������ƣ�");
    gets(temp1);

    int i = search_wenjianjia(temp1);       //�������ж��ļ����Ƿ����
    if (i == -1)
    {
        printf("������ļ��в�����\n");
        return;
    }

    printf("��������Ҫ�������ļ�����");
    gets(temp2);

    Node *p = search_wenjian(i, temp2);     //pΪ�ļ�����һ���
    if (p == NULL)        //�ж�Ҫ��ȡ���ļ��Ƿ����
    {
        printf("Ҫ��ȡ���ļ�������\n");
        return;
    }

    printf("��������Ҫ���ҵı�ţ�");      //�����ҵڼ���
    int x;
    scanf("%d", &x);
    getchar();

    FILE *fp1;
    if((fp1=fopen(p->next->data,"r"))==NULL)
    {
        printf("file cannot be opened\n");
        return;
    }

    int t = 1, s = 0;           //s�����ж��Ƿ���ҵ��ô��룬t������¼����
    char str[256] = {0};
    printf("���ҽ��Ϊ��\n");
    while (fgets(str, 256, fp1) != NULL)        //����Ų���
    {
        if (x == t)
        {
            s = 1;
            printf("��%d�У�%s", t, str);
            break;
        }
        t++;
    }
    if (s == 0)
        printf("����ı�Ŵ���δ�鵽���\n");
    fclose(fp1);
}

void neirongcaozuo()     //���ļ����ݲ���ѡ��
{
    while (1)
    {
        printf("\n��������Ҫ���еĲ�����");
        int ch;
        scanf("%d",&ch);
        getchar();
        switch (ch)
        {
            case 1:         //��ȡ������Ϣ
            {
                read_file();
                break;
            }
            case 2:         //����һ�д���
            {
                add_a_line_code();
                break;
            }
            case 3:         //ɾ��һ�д���
            {
                delete_a_line_code();
                break;
            }
            case 4:         //�޸�һ�д���
            {
                change_a_line_code();
                break;
            }
            case 5:         //���������
            {
                search_code();
                break;
            }
            case 6:         //����Ų���
            {
                search_biaohao();
                break;
            }
            case 0:         //�����ϲ����
            {
                printf("\n");
                caidan2();
                return;
            }
            default:
            {
                printf("������������������\n");
                break;
            }
        }
    }
}

int wenjiancaozuo()      //���ļ�����ѡ��
{
    while (1)
    {
        printf("\n��������Ҫ���еĲ���:");
        int ch;
        scanf("%d",&ch);
        getchar();
        switch (ch)
        {
            case 1:     //�����ļ�
            {
                create_file();
                break;
            }
            case 2:     //ɾ���ļ�
            {
                delete_file();
                break;
            }
            case 3:     //��ʾĳ�ļ����е��ļ�
            {
                show_file();
                break;
            }
            case 4:     //���ļ����ݽ��в���
            {
                caidan3();
                neirongcaozuo();
                break;
            }
            case 0:     //�����ϲ����
            {
                printf("\n");
                caidan1();
                return ;
            }
            default:
            {
                printf("������������������\n");
                break;
            }
        }
    }
}

void wenjianjiacaozuo()         //���ļ��в���
{
    caidan1();   //���ѡ��˵�
    int ch;
    while (1)
    {
        printf("\n��������Ҫ���еĲ���:");
        scanf("%d",&ch);
        getchar();
        switch (ch)
        {
            case 1:             //�����ļ���
            {
                create_folio();
                break;
            }
            case 2:             //�鿴�ļ���
            {
                look_folio();
                break;
            }
            case 3:             //ɾ���ļ���
            {
                delete_folio();
                break;
            }
            case 4:             //���ļ�����
            {
                caidan2();
                wenjiancaozuo();
                break;
            }
            case 0:             //�˳�����
                return;
            default:
            {
                printf("������������������\n");
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