#pragma once
typedef struct Huff_node
{
    long w;
    int lchild;
    int rchild;
    int parent;
}Huff_node;
void huff_encode(long weight[],int count,char *map[]);
void getmin(Huff_node*Huff_tree,int i ,int &min1,int &min2);
void get_huffcode(Huff_node*,int count,char *huffcode[]);

void print_map(char *map[],int count);
// void huff_decode()