#include <iostream>

using namespace std;
template<typename T>
struct Listnode
{
    T Data;
    Listnode* next;
    Listnode( T d) : Data(d), next(nullptr){}
    ~Listnode(){}
};
template<typename T>
struct TreeNode
{
    T Data;
    Listnode< TreeNode<T>* >* ChildenHead;//the type of Data in the Listnode is TreeNode<T>*--the pointer to class TreeNode
    TreeNode()
    {
        ChildenHead =NULL;
    }
    void AddChild(TreeNode<T>* node)
    {
        Listnode< TreeNode<T>* >* ChildNode = new Listnode< TreeNode<T>* >(node);//node ��ʼ��new����ָ���ָ������
        if(ChildenHead == NULL)
        {
            ChildenHead = ChildNode;
        }else
        {
            ChildNode ->next = ChildenHead;//ChildNode������ӵ�Ҷ�ӽڵ㣬ChildNode ->nextָ�򸸽ڵ�
            ChildenHead = ChildNode;//ChildenHead�൱�ڰ�����ӵ����ڵ���ӽ�TreeNode���С�TreeNode����ֻ��ChildenHead��ָ��
        }

    }
};
template<typename T>
class Tree
{
private:
    TreeNode<T>* Nodes;
    TreeNode<T>* root;
public:
    Tree();
    Tree(int MaxNodes);
    ~Tree();
    TreeNode<T>* GetTreeNode(int id);
    void SetRoot(int RootId);
    void AddChild(int ParentId, int SonId);
    void AssignData(int NodeId, T data);
    void Print(TreeNode<T>* node = NULL);  
};
template<typename T>
Tree<T> ::Tree(int MaxNodes)
{
    Nodes = new TreeNode<T>[MaxNodes];//new ����Ŀռ�������������ʽ���ʲ������߽�ı���
}
template<typename T>//ģ�����������
Tree<T> ::~Tree()
{
    delete[] Nodes;
}
template<typename T>
TreeNode<T>* Tree<T> ::GetTreeNode(int id)
{
    return &Nodes[id];
}
template<typename T>
void Tree<T> ::SetRoot(int RootId)
{
    root = GetTreeNode(RootId);
}
template<typename T>
void Tree<T> ::AddChild(int ParentId, int SonId)
{
    TreeNode<T>* ParaentNode = GetTreeNode(ParentId);
    TreeNode<T>* SontNode = GetTreeNode(SonId);
    ParaentNode ->AddChild(SontNode);
}
template<typename T>
void Tree<T> ::AssignData(int NodeId, T data)
{
    GetTreeNode(NodeId)->Data = data;
}
template<typename T>
void Tree<T> ::Print(TreeNode<T>* node)
{
    if(node == NULL)
    {
        node = root;
    }
    cout << node ->Data;
    Listnode< TreeNode<T>* > *tmp = node ->ChildenHead;
    while (tmp)
    {
        Print(tmp ->Data);
        tmp = tmp ->next;
    }
    
}
int main()
{
    Tree<char> T(9);
    T.SetRoot(0);
    T.AssignData(0,'a');
    T.AssignData(1,'b');
    T.AssignData(2,'c');
    T.AssignData(3,'d');
    T.AssignData(4,'e');
    T.AssignData(5,'f');
    T.AssignData(6,'g');
    T.AssignData(7,'h');
    T.AssignData(8,'i');

    T.AddChild(0,2);
    T.AddChild(0,1);
    T.AddChild(1,3);
    T.AddChild(2,5);
    T.AddChild(2,4);
    T.AddChild(3,8);
    T.AddChild(3,7);
    T.AddChild(3,6);
    T.Print();
    system("pause");
    return 0;

}