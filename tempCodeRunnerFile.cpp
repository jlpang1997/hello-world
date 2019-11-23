
        Huff_tree[i]={ Huff_tree[min1].w+Huff_tree[min2].w ,min1,min2,0};
        Huff_tree[min1].parent=i;
        Huff_tree[min2].parent=i;
    }
    get_huffcode(Huff_tree,count,map);
}