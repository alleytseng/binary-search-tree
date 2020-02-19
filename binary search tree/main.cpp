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
        //delete node;//一邊印一邊delete
        inorder(node->r);
    }
}
Node* minValueNode(Node* node)
{
    Node* tmp=node;
    while(tmp->l!=NULL)
        tmp=tmp->l;
    return tmp;
}
Node* delete_(Node* node, int d)
{
    if(node==NULL)
        return node;
    if(d < node->key)//去左子樹找來砍
        node->l=delete_(node->l,d);/*關鍵*/
    else if(d > node->key)//去右子樹找來砍
        node->r=delete_(node->r,d);/*關鍵*/
    else
    {
        if(node->l==NULL)
        {
            Node *tmp=node->r;
            delete node;
            node = NULL;
            return tmp;
            /*要刪除最後一個node時，即使刪除node 且將node指到NULL，main function的root還是會有一個node，
             因為node 和root是兩個指標，雖然都指到同一個地方，但不會因為對方改了指向，自己也跟著改*/
        }
        else if(node->r==NULL)
        {
            Node *tmp=node->l;
            delete node;
            node = NULL;
            return tmp;
        }
        else
        {
            Node* tmp=minValueNode(node->r);//找出右子樹最小的來取代要砍掉的
            node->key=tmp->key;
            node->r=delete_(node->r, node->key);//取代root的相當於右子樹要砍掉的
        }
    }
    return node;
    
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
    cout<<endl;
    root=delete_(root,60);
    inorder(root);
    cout<<endl;
    root=delete_(root,40);
    inorder(root);
    cout<<endl;
    root=delete_(root,20);
    inorder(root);
    cout<<endl;
    root=delete_(root,10);
    inorder(root);
    cout<<endl;
    root=delete_(root,80);
    inorder(root);
    cout<<endl;
    root=delete_(root,50);
    /*如果刪除root的最後一個node時沒寫root=收到delete_的回傳NULL，
     root會剩下一個node，為了統一，所有的delete都加上root=*/
    inorder(root);
    cout<<endl;
    return 0;
}
/*
 10 20 40 50 60 80
 10 20 40 50 80
 10 20 50 80
 10 50 80
 50 80
 50
 
 */
