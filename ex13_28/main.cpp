#include <iostream>

using namespace std;

class TreeNode {
public:
    TreeNode();
    TreeNode(const TreeNode &tn);
    TreeNode(const string &s = string(), TreeNode *lchild = nullptr, TreeNode *rchild = nullptr)
        :value(s), count(1), left(lchild), right(rchild) { }
    ~TreeNode();
    void CopyTree(void);
    int ReleaseTree(void);


private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree {
public:
    BinStrTree();

    BinStrTree(const BinStrTree &bst):root(bst.root) { root->CopyTree(); }
    BinStrTree(TreeNode *t = nullptr) : root(t) { }
    ~BinStrTree();

private:
    TreeNode *root;
};

TreeNode::TreeNode():value(""), count(0), left(nullptr), right(nullptr) { }

void TreeNode::CopyTree()
{
    if(left)
        left->CopyTree();
    if(right)
        right->CopyTree();
    count++;
}

int TreeNode::ReleaseTree()
{
    if(left) {
        if(!left->CopyTree())
            delete left;
    }
    if(right) {
        if(!right->CopyTree())
            delete right;
    }
    count--;
    return count;
}

TreeNode::TreeNode(const TreeNode &tn):
    value(tn.value), count(1), left(tn.left), right(tn.right)
{
    if(left)
        left->CopyTree();
    if(right)
        right->CopyTree();
}

TreeNode::~TreeNode()
{
    if(count)
        ReleaseTree();
}

BinStrTree::BinStrTree():root(nullptr) { }

BinStrTree::~BinStrTree()
{
    if(!root->ReleaseTree())
        delete root;
}



int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

