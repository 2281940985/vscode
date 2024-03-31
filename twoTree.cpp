#include<iostream>

using namespace std;
template<typename T>
class TreeNode
{
public:
    T Val;
    TreeNode* Left;
    TreeNode* Right;
    TreeNode() : Val(0), Left(nullptr), Right(nullptr) {}
    TreeNode(T x) : Val(x), Left(nullptr), Right(nullptr) {}
};
template<typename T>
class Tree
{
private:
    TreeNode<T>* Nodes;
    TreeNode<T>* Root;
    int NodeSize;
    TreeNode<T>* Create(T a[], int size, int NodeId, T nullnode);
    void Visit(TreeNode<T>* node);//访问节点的内容
    void PreOrder(TreeNode<T>* node);//前序遍历
    void InOrder(TreeNode<T>* node);//中序遍历
    void PostOrder(TreeNode<T>* node);//后序遍历

public:
    Tree() : Nodes(nullptr), Root(nullptr), NodeSize(0) {}
    Tree(int MaxNodes);
    ~Tree();
    TreeNode<T>* GetTreeNode(int id);
    void CreateTree(T a[], int size, T nullnode);
    void VisitTree(TreeNode<T>* node);
    void PreOrderTraversal();
    void InOrderTraversal();
    void PostOrderTraversal();
};
template<typename T>
Tree<T>::Tree(int MaxNodes)
{
    Nodes = new TreeNode<T>[MaxNodes];
    NodeSize = MaxNodes;
}
template<typename T>
Tree<T>::~Tree()
{
    delete[] Nodes;
}
template<typename T>
TreeNode<T>* Tree<T> ::GetTreeNode(int id)
{
    return &Nodes[id];
}
template<typename T>
void Tree<T> ::Visit(TreeNode<T>* node)
{
    cout << node->Val;
}
template<typename T>
void Tree<T> ::PreOrder(TreeNode<T>* node)
{
    if(node)
    {
        Visit(node);
        PreOrder(node->Left);
        PreOrder(node->Right);
    }
}
template<typename T>  
void Tree<T> ::InOrder(TreeNode<T>* node)
{
    if(node)
    {
        InOrder(node->Left);
        Visit(node);
        InOrder(node->Right);
    }
}
template<typename T>
void Tree<T> ::PostOrder(TreeNode<T>* node)
{
    if(node)
    {
        PostOrder(node->Left);
        PostOrder(node->Right);
        Visit(node);
    }
}
template<typename T>
TreeNode<T>* Tree<T> ::Create(T a[], int size, int NodeId, T nullnode)
{
    if(NodeId >= NodeSize || a[NodeId] == nullnode)
    {
        return NULL;
    }
    TreeNode<T>* NowNode =  GetTreeNode(NodeId);//浅拷贝，两个指针指向同一块区域
    NowNode->Val = a[NodeId];
    NowNode->Left = Create(a, size, 2 * NodeId, nullnode);//相当于每次只传进去一个节点,然后在根据数学关系传入左节点和右节点
    NowNode->Right = Create(a, size, 2 * NodeId + 1, nullnode);
    return NowNode;
}
template<typename T>
void Tree<T> ::CreateTree(T a[], int size, T nullnode)
{
    Root = Create(a, size, 1, nullnode);//如果传入0，则为空树，不满足数学关系，树中左节点代号一定是父节点的2倍。
}
template <typename T>
void Tree<T> ::InOrderTraversal()
{
    InOrder(Root);
}
template <typename T>
void Tree<T> ::PreOrderTraversal()
{
    PreOrder(Root);
}
template <typename T>
void Tree<T> ::PostOrderTraversal()
{
    PostOrder(Root);
}

int main()
{
    const char nullnode = '-';
    char a[15] = {nullnode, 'a', 'b', 'c', 'd', nullnode, 'e', 'f', 'g',
    'h', nullnode, nullnode, nullnode, nullnode, 'i'};//数组索引为0一定为空，不为树中的节点，下标为1才为根节点

    Tree<char> T(15);
    T.CreateTree(a, 15, nullnode);
    T.PreOrderTraversal();
    cout << endl;
    T.InOrderTraversal();
    cout << endl;
    T.PostOrderTraversal();
    cout << endl;
    system("pause");
    return 0;
}


