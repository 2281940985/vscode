#include<iostream>
using namespace std;

template<typename T>
struct TreNode
{
    T Val;
    TreNode *Left;
    TreNode *Right;
    TreNode(T val) : Val(val), Left(nullptr), Right(nullptr) {}
    TreNode() : Val(T()), Left(nullptr), Right(nullptr) {}
};
template<typename T>
class BinarySearchTree
{
private:
    TreNode<T> *Root;
    TreNode<T> *InsertNode(TreNode<T> *node,T val);
    TreNode<T> *RemoveNode(TreNode<T> *node,T val);
    bool SearchNode(TreNode<T> *node,T val);
    void InOrder(TreNode<T> *node);
public:
    BinarySearchTree() : Root(nullptr) {}
    ~BinarySearchTree();
    void Insert(T val)
    {
        Root = InsertNode(Root,val);
    }
    void Remove(T val)
    {
        Root = RemoveNode(Root,val);
    }
    bool Search(T val)
    {
        return SearchNode(Root,val);
    }
    void InOrderTraversal()
    {
        InOrder(Root);
        cout << endl;
    }
};
template<typename T>
BinarySearchTree<T> ::~BinarySearchTree()
{
    while (Root)
    {
        Remove(Root->Val);
    }
    
}
template<typename T>
TreNode<T> *BinarySearchTree<T>::InsertNode(TreNode<T> *node,T val)
{
    if(node == nullptr)
    {
        return new TreNode<T>(val);//如果是叶子节点，则直接创建一个新的节点，在回到上一层节点
    }
    if(val < node->Val)
    {
        node->Left = InsertNode(node->Left,val);//将值插在左子树，从Root开始迭代
    }
    else if(val > node->Val)
    {
        node->Right = InsertNode(node->Right,val);//将值插在右子树，从Root开始迭代
    }
    return node;//返回根节点Root
}
template<typename T>
TreNode<T> *BinarySearchTree<T>::RemoveNode(TreNode<T> *node,T val)
{
    if(node == nullptr)//如果是空节点，则直接返回空节点,node = root
    {
        return nullptr;
    }
    if(val < node->Val)
    {
        node->Left = RemoveNode(node->Left,val);
    }
    else if(val > node->Val)
    {
        node->Right = RemoveNode(node->Right,val);
    }
    else
    {
        if(node ->Left == nullptr && node->Right == nullptr)//如果是叶子节点，则直接删除
        {
            delete node;
            return nullptr;
        }
        else if(node->Left == nullptr)//如果只有右子树，则将右子树的根节点赋值给新节点，然后删除右子树
        {
            TreNode<T> *temp = node->Right;
            delete node;
            return temp;
        }
        else if(node->Right == nullptr)//如果只有左子树，则将左子树的根节点赋值给新节点，然后删除左子树
        {
            TreNode<T> *temp = node->Left;
            delete node;
            return temp;
        }
        else//如果有左右子树，无需删除目标节点，只需要将右子树的最小值赋值给当前树的节点(目标节点)，然后删除右子树的最小值，因为该节点已经作为根节点了
        {
            TreNode<T> *temp = node->Right;
            while(temp->Left != nullptr)
            {
                temp = temp->Left;
            }
            node->Val = temp->Val;
            node->Right = RemoveNode(node->Right,temp->Val);
        }
    }
    return node;//返回根节点Root,即使在当前层完成了操作，也要返回到上一层，直到根节点。
}


template<typename T>
bool BinarySearchTree<T>::SearchNode(TreNode<T> *node,T val)
{
    if(node == nullptr)//必须写在第一个，防止调用空指针
    {
        return false;
    }
    if(val == node->Val)
    {
        return true;
    }
    if(val < node->Val)
    {
        return SearchNode(node->Left,val);
    }
    else
    {
        return SearchNode(node->Right,val);
    }
}

template<typename T>
void BinarySearchTree<T>::InOrder(TreNode<T> *node)
{
    if(node == nullptr)
    {
        return;
    }
    InOrder(node->Left);
    cout << node->Val << " ";
    InOrder(node->Right);//中序遍历，得到的结果是递增序列
}

int main()
{
    BinarySearchTree<int> bst;
    bst.Insert(50);
    bst.Insert(30);
    bst.Insert(70);
    bst.Insert(40);
    bst.Insert(80);
    bst.Insert(80);
    bst.Insert(80);
    bst.Insert(60);
    bst.Insert(100);
    bst.InOrderTraversal();
    cout << bst.Search(9090) << endl;
    cout << bst.Search(100) << endl;
    bst.Remove(100);
    bst.InOrderTraversal();
    bst.Remove(50);
    bst.Insert(65);
    bst.InOrderTraversal();

    system("pause");
    return 0;
}