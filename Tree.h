#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template <typename T>
struct BinTreeNode {
    T data;
    BinTreeNode *left;
    BinTreeNode *right;
    BinTreeNode() = default;
    BinTreeNode(int x, BinTreeNode<T> *left = nullptr,
                BinTreeNode<T> *right = nullptr)
        : data(x), left(left), right(right) {}
};

template <typename T>
class BinaryTree {
public:
    // 构造函数
    BinaryTree() : root(nullptr) {}
    // 带结束标志的构造函数
    BinaryTree(T value) : refValue(value), root(nullptr) {}
    // 析构函数
    ~BinaryTree() { destroy(root); }

    // 使用广义表创建二叉树
    // A(B(D,E(G,)),C(,F))#
    void createBinTree() { createBinTree(root); }
    // 递归先序遍历
    void preOrder() { preOrder(root); }
    // 递归中序遍历
    void midOrder() { midOrder(root); }
    // 递归后序遍历
    void postOrder() { postOrder(root); }

    // 非递归先序遍历
    void preOrderNonRecur() { preOrderNonRecur(root); }

    // 非递归中序遍历
    void midOrderNonRecur() { midOrderNonRecur(root); }

    // 非递归后序遍历
    void postOrderNonRecur() { postOrderNonRecur(root); }

    // 层序遍历
    void levelOrder() { levelOrder(root); }

protected:
    // 创建二叉树
    void createBinTree(BinTreeNode<T> *&root) {
        std::stack<BinTreeNode<T> *> stk;
        root = nullptr;
        BinTreeNode<T> *curNode, *stkTop;
        int leftOrRight;
        T temp;
        std::cin >> temp;
        while (temp != refValue) {
            switch (temp) {
            case '(':
                stk.push(curNode);
                leftOrRight = 1;
                break;
            case ')':
                stk.pop();
                break;
            case ',':
                leftOrRight = 2;
                break;
            default:
                curNode = new BinTreeNode<T>(temp);
                if (root == nullptr) {
                    root = curNode;
                } else if (leftOrRight == 1) {
                    stkTop = stk.top();
                    stkTop->left = curNode;
                } else {
                    stkTop = stk.top();
                    stkTop->right = curNode;
                }
            }
            std::cin >> temp;
        }
    }

    // 递归先序遍历
    void preOrder(BinTreeNode<T> *node) {
        if (node) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // 递归中序遍历
    void midOrder(BinTreeNode<T> *node) {
        if (node) {
            midOrder(node->left);
            cout << node->data << " ";
            midOrder(node->right);
        }
    }

    // 递归后序遍历
    void postOrder(BinTreeNode<T> *node) {
        if (node) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }

    // 非递归先序遍历
    void preOrderNonRecur(BinTreeNode<T> *node) {
        if (node == nullptr) {
            return;
        }
        stack<BinTreeNode<T> *> stk;

        stk.push(node);
        while (!stk.empty()) {
            BinTreeNode<T> *temp = stk.top();
            stk.pop();
            cout << temp->data << " ";
            if (temp->right)
                stk.push(temp->right);
            if (temp->left)
                stk.push(temp->left);
        }
    }

    // 非递归中序遍历
    void midOrderNonRecur(BinTreeNode<T> *node) {
        stack<BinTreeNode<T> *> stk;
        BinTreeNode<T> *temp = node;
        while (temp || !stk.empty()) {
            if (temp) {
                stk.push(temp);
                temp = temp->left;
            } else {
                temp = stk.top();
                stk.pop();
                cout << temp->data << " ";
                temp = temp->right;
            }
        }
    }

    // 非递归后序遍历
    void postOrderNonRecur(BinTreeNode<T> *node) {
        if (node == nullptr) {
            return;
        }
        stack<BinTreeNode<T> *> stk;
        BinTreeNode<T> *temp = nullptr;
        while (node != nullptr || !stk.empty()) {
            while (node != nullptr) {
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            if (node->right == nullptr || node->right == temp) {
                cout << node->data << " ";
                temp = node;
                node = nullptr;
            } else {
                stk.push(node);
                node = node->right;
            }
        }
    }

    // 层序遍历
    void levelOrder(BinTreeNode<T> *node) {
        if (node == nullptr) {
            return;
        }
        queue<BinTreeNode<T> *> que;
        BinTreeNode<T> *temp;
        que.push(node);
        while (!que.empty()) {
            temp = que.front();
            que.pop();
            cout << temp->data << " ";
            if (temp->left) {
                que.push(temp->left);
            }
            if (temp->right) {
                que.push(temp->right);
            }
        }
    }

private:
    BinTreeNode<T> *root;
    T refValue;
};
