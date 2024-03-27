#include<iostream>
#include<string>
using namespace std;

template<typename T>
class ListNode
{
public:
    T Data;
    ListNode* Next;
    ListNode(T data) : Data(data), Next(nullptr){}
    ~ListNode(){}
};
template<typename T>
class TreeNode
{
public:
    T TreeData;
    ListNode<TreeNode<T>*>* ChildHead;
    TreeNode() : ChildHead(nullptr){}
    ~TreeNode(){}
    void AddChild(TreeNode<T>* Node)
    {
        ListNode<TreeNode<T>*>* ChildNode = new ListNode<TreeNode<T>*>(Node);
        if(ChildHead == NULL)
        {
            ChildHead = ChildNode;//每个节点的ChildHead初始化均为null，当添加子节点后，才不为空
        }else
        {
            ChildNode ->Next = ChildHead;//当父节点有了子节点后在继续添加子节点时，新的子节点的next指向旧的子节点即ChildHead，
                                        //然后再把新的子节点赋为ChildHead,以此类推继续添加新的子节点。
            ChildHead = ChildNode;
            //delete ChildNode;千万不能回收指针ChildNode，因为ChildNode还在，就是新添进来的树节点，它还指向同一层的兄弟节点
        } 
    }

};
template<typename T>
class Tree
{
private:
    TreeNode<T>* Root;
    TreeNode<T>* Nodes;
public:
    Tree(int MaxNodes)
    {
        Nodes = new TreeNode<T>[MaxNodes]; 
    }
    ~Tree()
    {
        delete[] Nodes;
    }
    TreeNode<T>* GetTreeNode(int id)
    {
        return &Nodes[id];
    }
    void SetRoot(int id)
    {
        Root = &Nodes[id];
    }
    void AddChild(int ParaNodeId, int SonNodeId)
    {
        TreeNode<T>* ParaNode = GetTreeNode(ParaNodeId);
        TreeNode<T>* SonNode = GetTreeNode(SonNodeId);
        ParaNode ->AddChild(SonNode);
        //SonNode ->ChildHead ->Next = ParaNode ->ChildHead
    }
    void AssignData(int id, T data)
    {
        
        (&Nodes[id]) ->TreeData = data;//GetTreeNode(id) ->TreeData = data
    }
    void Print(TreeNode<T>* node)
    {
        if(node == NULL)
        {
            node = Root;
        }
        cout << node ->TreeData;
        ListNode<TreeNode<T>*>* tmp = node ->ChildHead;//ChildHead指针指向树的下一层节点！！！
        while (tmp)
        {
            Print(tmp ->Data);
            tmp = tmp ->Next;//Next指针是指向同一层的树节点！！！不是下一层，也不是上一层
            //这里靠while的迭代循环返回上一层树节点，最底层迭代完后返回上一层Next不为空的继续迭代
        }
        
    }
    
};
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
    T.Print(NULL);

    system("pause");
    return 0;
}