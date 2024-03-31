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
        return new TreNode<T>(val);//�����Ҷ�ӽڵ㣬��ֱ�Ӵ���һ���µĽڵ㣬�ڻص���һ��ڵ�
    }
    if(val < node->Val)
    {
        node->Left = InsertNode(node->Left,val);//��ֵ��������������Root��ʼ����
    }
    else if(val > node->Val)
    {
        node->Right = InsertNode(node->Right,val);//��ֵ��������������Root��ʼ����
    }
    return node;//���ظ��ڵ�Root
}
template<typename T>
TreNode<T> *BinarySearchTree<T>::RemoveNode(TreNode<T> *node,T val)
{
    if(node == nullptr)//����ǿսڵ㣬��ֱ�ӷ��ؿսڵ�,node = root
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
        if(node ->Left == nullptr && node->Right == nullptr)//�����Ҷ�ӽڵ㣬��ֱ��ɾ��
        {
            delete node;
            return nullptr;
        }
        else if(node->Left == nullptr)//���ֻ�������������������ĸ��ڵ㸳ֵ���½ڵ㣬Ȼ��ɾ��������
        {
            TreNode<T> *temp = node->Right;
            delete node;
            return temp;
        }
        else if(node->Right == nullptr)//���ֻ�������������������ĸ��ڵ㸳ֵ���½ڵ㣬Ȼ��ɾ��������
        {
            TreNode<T> *temp = node->Left;
            delete node;
            return temp;
        }
        else//�������������������ɾ��Ŀ��ڵ㣬ֻ��Ҫ������������Сֵ��ֵ����ǰ���Ľڵ�(Ŀ��ڵ�)��Ȼ��ɾ������������Сֵ����Ϊ�ýڵ��Ѿ���Ϊ���ڵ���
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
    return node;//���ظ��ڵ�Root,��ʹ�ڵ�ǰ������˲�����ҲҪ���ص���һ�㣬ֱ�����ڵ㡣
}


template<typename T>
bool BinarySearchTree<T>::SearchNode(TreNode<T> *node,T val)
{
    if(node == nullptr)//����д�ڵ�һ������ֹ���ÿ�ָ��
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
    InOrder(node->Right);//����������õ��Ľ���ǵ�������
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