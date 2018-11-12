 bool checkBST(Node *root, int minVal, int maxVal) {
        if (root == NULL) return true;
        
        bool isBstLeft = checkBST(root->left, minVal, root->data - 1); 
        bool isBstRight = checkBST(root->right, root->data + 1, maxVal);
        
        if (isBstLeft && isBstRight && 
            minVal <= root->data && maxVal >= root->data) {
            return true;
        }
        return false;
    }

	bool checkBST(Node* root) {
        return checkBST(root, -32767, 32767);
	}