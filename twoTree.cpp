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
    void Visit(TreeNode<T>* node);
    void PreOrder(TreeNode<T>* node);
    void InOrder(TreeNode<T>* node);
    void PostOrder(TreeNode<T>* node);

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
    TreeNode<T>* NowNode =  GetTreeNode(NodeId);
    NowNode->Val = a[NodeId];
    NowNode->Left = Create(a, size, 2 * NodeId, nullnode);
    NowNode->Right = Create(a, size, 2 * NodeId + 1, nullnode);
    return NowNode;
}
template<typename T>
void Tree<T> ::CreateTree(T a[], int size, T nullnode)
{
    Root = Create(a, size, 1, nullnode);
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
    'h', nullnode, nullnode, nullnode, nullnode, 'i'};

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


