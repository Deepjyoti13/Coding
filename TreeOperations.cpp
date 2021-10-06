#include "io.h"
#include "Tree.h"

void printTree(TreeNode<int>* root) {
    if(root==NULL) return;
    cout<<root->data<<": ";
    for(int i=0; i<root->children.size(); i++)
        cout<<root->children[i]->data<<" ";
    cout<<endl;
    for(int i=0; i<root->children.size(); i++)
        printTree(root->children[i]);
}

int sum=0;
int sumNodes(TreeNode<int>* root) {
    if(root==NULL) return 0;
    sum += root->data;
    for(int i=0; i<root->children.size(); i++)
        sumNodes(root->children[i]);
    return sum;
}

int maxNode = INT_MIN;
int largestNode(TreeNode<int>* root) {
    if(root==NULL) return maxNode;
    maxNode = max(maxNode, root->data);
    for(int i=0; i<root->children.size(); i++)
        largestNode(root->children[i]);
    return maxNode;
}

int countItems=0;
int countNodes(TreeNode<int>* root) {
    if(root==NULL) return countItems;
    countItems++;
    for(int i=0; i<root->children.size(); i++)
        countNodes(root->children[i]);
    return countItems;
}

int heightNode(TreeNode<int>* root) {
    if(root==NULL) return 0;
    int height=0;
    for(TreeNode<int>* n : root->children) {
        height = max(height, heightNode(n));
    }
    return height+1;
}

int height=0;
TreeNode<int>* replaceNodesWithDepth(TreeNode<int>* root, int height) {
    if(root==NULL) return NULL;
    root->data = height;
    for(int i=0; i<root->children.size(); i++) {
        replaceNodesWithDepth(root->children[i], height+1);
    }
    return root;
}

int res=0;
pair<int, int> answer;
pair<int, int> maxSumNode(TreeNode<int>* root) {
    if(root==NULL) return answer;
    int sum = root->data;
    for(int i=0; i<root->children.size(); i++) {
        sum+=root->children[i]->data;
        maxSumNode(root->children[i]);
    }
    if(res<sum) {
        res = sum;
        answer.first = root->data;
        answer.second = res;
    }
    return answer;
}

int ans = INT_MAX;
int valueJustGreaterThanK(TreeNode<int>* root, int K) {
    if(root == NULL) return 0;
    int tmp = INT_MAX;
    if(root->data > K) tmp = root->data;
    ans = min(ans, tmp);
    for(int i=0; i<root->children.size(); i++)
        valueJustGreaterThanK(root->children[i], K);
    return ans;
}

int tmpMax = INT_MIN;
int tmpSecondMax = INT_MIN;
int secondMaximum(TreeNode<int>* root) {
    if(root==NULL) return tmpSecondMax;
    cout<<tmpSecondMax<<" ";
    if(tmpMax>root->data) if(root->data>tmpSecondMax) tmpSecondMax = root->data;
    if(tmpMax<root->data) {
        tmpSecondMax = tmpMax;
        tmpMax = root->data;
    }
    for(int i=0; i<root->children.size(); i++) {
        secondMaximum(root->children[i]);
    }
    return tmpSecondMax;
}

void printTreeLevel(TreeNode<int>* root) {
    if(root==NULL) return;
    cout<<root->data<<": ";
    for(int i=0; i<root->children.size(); i++)
        cout<<root->children[i]->data<<" ";
    cout<<endl;
    queue<TreeNode<int>*> childrenQueue;
    childrenQueue.push(root);
    while (childrenQueue.size()!=0)
    {
        TreeNode<int>* front = childrenQueue.front();
        childrenQueue.pop();

        for(int i=0; i<front->children.size(); i++) {
            childrenQueue.push(front->children[i]);
            cout<<front->children[i]->data<<": ";
            for(int j=0; j<front->children[i]->children.size(); j++)
                cout<<front->children[i]->children[j]->data<<" ";
            cout<<endl;
        }
    }
}

TreeNode<int>* takeInput() {
    int data; cin>>data;
    TreeNode<int>* root = new TreeNode<int>(data);
    int n;
    cout<<"Number of children of "<<data<<": "<<endl;
    cin>>n;
    for(int i=0; i<n; i++)
        root->children.push_back(takeInput());
    return root;
}

TreeNode<int>* takeInputLevel() {
    int data; cin>>data;
    TreeNode<int>* root = new TreeNode<int>(data);
    queue<TreeNode<int>*> childrenQueue;
    childrenQueue.push(root);
    while (childrenQueue.size()!=0) {
        TreeNode<int>* frontNode = childrenQueue.front();
        childrenQueue.pop();
        // cout<<"Number of children of "<<frontNode->data<<endl;
        int childCount; cin>>childCount;
        for(int i=0; i<childCount; i++) {
            int childData; cin>>childData;
            TreeNode<int>* childNode = new TreeNode<int>(childData);
            childrenQueue.push(childNode);
            frontNode->children.push_back(childNode);
        }
    }
    return root;
}

int main() {
    inputOutput();
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* node1 = new TreeNode<int>(2);
    // TreeNode<int>* node2 = new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    TreeNode<int>* root = takeInputLevel();
    printTreeLevel(root);
    cout<<"\nSum: "<<sumNodes(root);
    cout<<"\nLargest: "<<largestNode(root);
    cout<<"\nCount: "<<countNodes(root);
    cout<<"\nHeight: "<<heightNode(root);
    answer.first = 0;
    answer.second = 0;
    pair<int, int> result = maxSumNode(root);
    cout<<"\nNode with largest sum: "<<result.first<<"\nSum is: "<<result.second;
    int K=5;
    cout<<"\nJust larger than "<<K<<": "<<valueJustGreaterThanK(root, K);
    cout<<"\nSecond largest node: "<<secondMaximum(root);
    TreeNode<int>* ans = replaceNodesWithDepth(root, height); cout<<endl;
    printTreeLevel(ans);
}


// 10 3 20 30 40 2 40 50 0 0 0 0

//             10
//     20      30      40
//   40  50