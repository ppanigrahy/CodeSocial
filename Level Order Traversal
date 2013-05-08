//Level order traversal + printing according to levels

#include<iostream>
#include<queue>
using namespace std;
struct Node{
int Val;
Node *left;
Node *right;};

Node* CreateTree()
{
Node *N1 = new Node(); N1->Val = 1;
Node *N2 = new Node(); N2->Val = 2;
Node *N3 = new Node(); N3->Val = 3;
Node *N4 = new Node(); N4->Val = 4;
Node *N5 = new Node(); N5->Val = 5;
Node *N6 = new Node(); N6->Val = 6;
Node *N7 = new Node(); N7->Val = 7;

N1->left = N2; N1->right=N3;
N2->left = N4; N2->right=N5;
N3->left = N6; N3->right=N7;
N4->left=N4->right=N5->left=N5->right=N6->left=N6->right=N7->left=N7->right=NULL;

return N1;
}

void LevelOrderTraversal(Node *root)
{
if (root==NULL) return;
Node *temp = root;
int parent(1), children(0);
queue<Node*> levelOrderQ;
levelOrderQ.push(temp);
while(levelOrderQ.size()){
    if(!parent) {parent=children; cout<<endl;}
Node *t = levelOrderQ.front();
std::cout<<t->Val<<'\t';
levelOrderQ.pop();
parent--;
if(t->left){
levelOrderQ.push(t->left); children++;
}
if(t->right){
levelOrderQ.push(t->right); children++;
}
}
}

int main()
{
    Node *root = CreateTree();
    LevelOrderTraversal(root);
}
