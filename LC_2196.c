/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* findNode(struct TreeNode* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;
    struct TreeNode* leftResult = findNode(root->left, val);
    if (leftResult != NULL) return leftResult;
    return findNode(root->right, val);
}

struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize, int* descriptionsColSize){
    struct TreeNode* root = NULL;
    struct TreeNode* nodes[100001] = {NULL}; 
    bool isChild[100001] = {false};

    for (int i = 0; i < descriptionsSize; i++) {
        int parentVal = descriptions[i][0];
        int childVal = descriptions[i][1];
        int isLeft = descriptions[i][2];

        if (nodes[parentVal] == NULL) {
            nodes[parentVal] = newNode(parentVal);
        }
        if (nodes[childVal] == NULL) {
            nodes[childVal] = newNode(childVal);
        }

        if (isLeft) {
            nodes[parentVal]->left = nodes[childVal];
        } else {
            nodes[parentVal]->right = nodes[childVal];
        }
        
        isChild[childVal] = true;
    }

    for (int i = 1; i < 100001; i++) {
        if (nodes[i] != NULL && !isChild[i]) {
            root = nodes[i];
            break;
        }
    }

    return root;
}

