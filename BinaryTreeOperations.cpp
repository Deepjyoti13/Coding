#include "io.h"
#include "BinaryTree.h"

BinaryTreeNode<int>* takeInputLevel() {
    int data;
    cout<<"Enter data: \n"; cin>>data;
    if(data==-1) return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int>*> childrenQueue;
    childrenQueue.push(root);
    while(!childrenQueue.empty()) {
        BinaryTreeNode<int>* front = childrenQueue.front();
        childrenQueue.pop();
        int childData;
        cout<<"Enter left child: \n";
        cin>>childData;
        if(childData!=-1) {
            front->left = new BinaryTreeNode<int>(childData);
            childrenQueue.push(front->left);
        }
        cout<<"Enter right child: \n";
        cin>>childData;
        if(childData!=-1) {
            front->right = new BinaryTreeNode<int>(childData);
            childrenQueue.push(front->right);
        }
    }
    return root;
}

void printTreeLevel(BinaryTreeNode<int>* root) {
    if(root==NULL) return;
    cout<<root->data<<": ";
    if(root->left) cout<<"L:"<<root->left->data<<" ";
    if(root->right) cout<<"R:"<<root->right->data<<endl;
    queue<BinaryTreeNode<int>*> childrenQueue;
    childrenQueue.push(root);
    while(!childrenQueue.empty()) {
        BinaryTreeNode<int>* front = childrenQueue.front();
        childrenQueue.pop();
        if(front->left) {
            cout<<front->left->data<<": ";
            childrenQueue.push(front->left);
            if(front->left->left) cout<<"L:"<<front->left->left->data<<" ";
            if(front->left->right) cout<<"R:"<<front->left->right->data<<" ";
            cout<<endl;
        }
        if(front->right) {
            cout<<front->right->data<<": ";
            childrenQueue.push(front->right);
            if(front->right->left) cout<<"L:"<<front->right->left->data<<" ";
            if(front->right->right) cout<<"R:"<<front->right->right->data<<" ";
            cout<<endl;
        }
    }
}

bool nodePresent(BinaryTreeNode<int>* root, int data) {
    if(root==NULL) return false;
    if(root->data==data) return true;
    bool opt1 = nodePresent(root->left, data);
    bool opt2 = nodePresent(root->right, data);
    return opt1 || opt2;
}

int counter=0;
int countNodes(BinaryTreeNode<int>* root) {
    if(root==NULL) return 0;
    counter++;
    if(root->left) countNodes(root->left);
    if(root->right) countNodes(root->right);
    return counter;
}
int countNodes2(BinaryTreeNode<int>* root) {
    if(root==NULL) return 0;
    int counter=1; int opt1=0; int opt2=0;
    if(root->left) opt1 = countNodes2(root->left);
    if(root->right) opt2 = countNodes2(root->right);
    return counter += opt1+opt2;
}

int heightNodes(BinaryTreeNode<int>* root) {
    if(root==NULL) return 0;
    int height = 1; int opt1=0, opt2=0;
    if(root->left) opt1 = heightNodes(root->left);
    if(root->right) opt2 = heightNodes(root->right);
    return height+=max(opt1, opt2);
}

int heightNodes2(BinaryTreeNode<int>* root) {
    if(root==NULL) return 0;
    return max(heightNodes2(root->left), heightNodes2(root->right))+1;
}

BinaryTreeNode<int>* takeInput() {
    int data;
    cout<<"Enter data: \n"; cin>>data;
    if(data==-1) return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

void printTree(BinaryTreeNode<int>* root) {
    if (root==NULL) return;
    cout<<root->data<<": ";
    if(root->left) cout<<"L:"<<root->left->data<<" ";
    if(root->right) cout<<"R:"<<root->right->data;
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

void printMirror(BinaryTreeNode<int>* root) {
    if(root==NULL) return;
    cout<<root->data;
    if(root->right) printMirror(root->right);
    if(root->left) printMirror(root->left);
}

void printMirrorLevel(BinaryTreeNode<int>* root) {
    if(root==NULL) return;
    cout<<root->data;
    queue<BinaryTreeNode<int>*> childrenQueue;
    childrenQueue.push(root);
    while(!childrenQueue.empty()) {
        cout<<endl;
        BinaryTreeNode<int>* front = childrenQueue.front();
        childrenQueue.pop();
        if(front->right) {
            cout<<front->right->data;
            childrenQueue.push(front->right);
        }
        if(front->left) {
            cout<<front->left->data;
            childrenQueue.push(front->left);
        }
    }
}

BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int InS, int InE, int PreS, int PreE) {
    if(InS>InE || PreS>PreE) return NULL;
    int data=pre[PreS];
    int rootIndex = -1;
    for(int i=InS; i<=InE; i++) {
        if(in[i]==data) {
            rootIndex=i; 
            break;
        }
    }
    int LInS = InS;
    int LInE = rootIndex-1;
    int LPreS = PreS+1;
    int LPreE = LPreS+LInE-LInS;
    int RInS = rootIndex+1;
    int RInE = InE;
    int RPreS = LPreE+1;
    int RPreE = PreE;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
    root->left = buildTreeHelper(in, pre, LInS, LInE, LPreS, LPreE);
    root->right = buildTreeHelper(in, pre, RInS, RInE, RPreS, RPreE);
    return root;
}
BinaryTreeNode<int>* buildTree(int* in, int* pre, int size) {
    return buildTreeHelper(in, pre, 0, size-1, 0, size-1);
}

pair<int, int> diameter;
pair<int, int> diameterOfTree(BinaryTreeNode<int>* root) {
    if(root==NULL) return diameter;
    
}

int main() {
    inputOutput();
    // BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* left1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* right1 = new BinaryTreeNode<int>(3);
    // root->left=left1;
    // root->right=right1;
    BinaryTreeNode<int>* root = takeInputLevel();
    printTreeLevel(root);
    int K=1;
    cout<<"Is "<<K<<" present? "<<nodePresent(root, 1)<<endl;
    cout<<"Count: "<<countNodes(root)<<endl;
    cout<<"Count: "<<countNodes2(root)<<endl;
    cout<<"Height: "<<heightNodes(root)<<endl;
    cout<<"Height: "<<heightNodes2(root)<<endl;
    printMirrorLevel(root);
    int pre[] = {1, 2, 4, 5, 3, 6, 7};
    int in[] = {4, 2, 5, 1, 6, 3, 7};
    BinaryTreeNode<int>* root2 = buildTree(in, pre, 7);
    printTreeLevel(root2);
    diameter.first = 0;
    diameter.second = 0;
}


// 1 2 3 4 -1 6 -1 5 -1 -1 -1 -1 -1
//             1
//         2        3
//       4        6
//     5
// 1/ 2 3 