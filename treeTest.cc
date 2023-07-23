#include "Tree.h"

using namespace std;

int main() {
    BinaryTree<char>* myTree = new BinaryTree<char>('#');
    myTree->createBinTree();
    myTree->preOrder();
    cout << endl;
    myTree->preOrderNonRecur();
    cout << endl;
    myTree->midOrder();
    cout << endl;
    myTree->midOrderNonRecur();
    cout << endl;
    myTree->postOrder();
    cout << endl;
    myTree->postOrderNonRecur();
    cout << endl;
    myTree->levelOrder();
    cout << endl;
    return 0;
}