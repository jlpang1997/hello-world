#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"huff.h"

int main()
{
    long weight[2]={ 2,3};
    int count=2;
    char *map[2];
    huff_encode(weight,count,map);
    printf(" fdsaf ");
    print_map(map,count);
    return 0;
}

void huff_encode(long weight[],int count,char *map[])//weight[10]=20 表示第11种类型有20个,weight . map 下标都从0开始
{
    Huff_node *Huff_tree=(Huff_node*)malloc(sizeof(Huff_node)*(2*count));
    for(int i=1;i<=count;i++)
    {
        Huff_tree[i].w=weight[i-1];
        Huff_tree[i].lchild=0;
        Huff_tree[i].rchild=0;
        Huff_tree[i].parent=0;
    }
    for(int i=count+1;i<2*count;i++) 
    {
        Huff_tree[i].w=0;
        Huff_tree[i].lchild=0;
        Huff_tree[i].rchild=0;
        Huff_tree[i].parent=0;
    }
    
    for(int i=count+1;i<count*2;i++)
    {
        int min1,min2;
        getmin(Huff_tree,i,min1,min2);

        Huff_tree[i].w=Huff_tree[min1].w+Huff_tree[min2].w;
        Huff_tree[i].lchild=min1;
        Huff_tree[i].rchild=min2;


        Huff_tree[min1].parent=i;
        Huff_tree[min2].parent=i;
    }
    get_huffcode(Huff_tree,count,map);
}
void get_huffcode(Huff_node*Huff_tree,int count,char *map[])
{
    for(int i=0;i<count;i++)
    {
        int total_len=2*count;
        char *code=(char *)malloc(sizeof(char)*total_len);
        code[--total_len]='\0';
        for(int k=i+1;Huff_tree[k].parent;k=Huff_tree[k].parent)
        {
            if(k==Huff_tree[Huff_tree[k].parent].lchild)
                code[--total_len]='0';
            else
                code[--total_len]='1';
        }
        int map_code_len=2*count-total_len;
        map[i]=(char *)malloc(sizeof(char)*(map_code_len));
        map[i][map_code_len-1]='\0';
        strcpy(map[i],&code[total_len]);

    }
}
void getmin(Huff_node*Huff_tree,int i ,int &min1,int &min2)
{
    min1=min2=0;
    for(int j=1;j<i;j++)
    {
        if(!Huff_tree[i].parent)
        {
            if(!min1)
                min1=i;
            else if(min1&&!min2)
            {
                if(Huff_tree[i].w<Huff_tree[min1].w)
                {
                    min2=min1;
                    min1=i;
                }
                else
                {
                    min2=i;
                }
            }
            else
            {
                if(Huff_tree[i].w<Huff_tree[min1].w)
                {
                    min2=min1;
                    min1=i;
                }
                else if(Huff_tree[i].w<Huff_tree[min2].w)
                {
                    min2=i;
                }
            }
        }
    }
}
void print_map(char *map[],int count)
{
    for(int i=0;i<count;i++)
        printf("%s\n",map[i]);
}
