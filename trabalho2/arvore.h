typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int data);
TreeNode* insert(TreeNode* root, int data);
void inorder(TreeNode* root);
void preorder(TreeNode* root);
void postorder(TreeNode* root);
TreeNode* search(TreeNode* root, int data);
TreeNode* minValueNode(TreeNode* node);
TreeNode* deleteNode(TreeNode* root, int data);