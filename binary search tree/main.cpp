//
//  main.cpp
//  binary search
//
//  Created by 楊為守 on 2020/2/18.
//  Copyright © 2020年 Alley_Tseng. All rights reserved.
//

#include <iostream>
using namespace std;
struct Node
{
    int key;
    Node* l;
    Node* r;
};
Node* insert(Node* node,int d)
{
    if(node==NULL)
    {/*如果不是用new空間的方法，是宣告一個node a，
      讓tmp指到a的記憶體位置會出錯，因為a的生命週期只在這個scope*/
        Node *tmp=new Node;
        tmp->l=NULL;
        tmp->r=NULL;
        tmp->key=d;
        return tmp;
    }
    if(d < node->key)
        node->l=insert(node->l,d);/*關鍵*/
    else
        node->r=insert(node->r,d);/*關鍵*/
    return node;
}
void inorder(Node* node)
{
    if(node!=NULL)
    {
        inorder(node->l);
        cout<<node->key<<" ";
        delete node;//一邊印一邊delete
        inorder(node->r);
    }
}
int main(int argc, const char * argv[]) {
    Node *root=NULL;
    root=insert(root,40);/*關鍵*/
    insert(root,20);
    insert(root,60);
    insert(root,80);
    insert(root,10);
    insert(root,50);
    inorder(root);
    return 0;
}

