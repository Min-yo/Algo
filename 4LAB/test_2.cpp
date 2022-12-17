Node* _remove(Node* cur, int target) {
    if (!cur) return nullptr;
    if (cur->val == target) {
        if (!cur->right && !cur->left) {
            delete cur;
            return nullptr;
        } else if (cur->left && !cur->right) {
            Node* temp = cur->left;
            delete cur;
            return temp;
        } else if (cur->right && !cur->left) {
            Node* temp = cur->right;
            delete cur;
            return temp;
        } else if (cur->right && cur->left) {
            cur->val = _rightmost(cur->left);
            cur->left = _remove(cur->left, cur->val);
            // cur->val = _leftmost(cur->right);
            // cur->right = _remove(cur->right, cur->val);
        }
    } else if (cur->val < target) {
        cur->right = _remove(cur->right, target);
        return cur;
    } else if (cur->val > target) {
        cur->left = _remove(cur->left, target);
        return cur;
    }
    return cur;
}


int getHeight(Node *node) {
		if (!node) return 0;
		int left = getHeight(node->left);
		int right = getHeight(node->right);
		return max(left, right) + 1;


int _rightmost(Node* cur) {
		if (!cur) return -1;
		if (!cur->right) return cur->val;
		return _rightmost(cur->right);
	}

	int _leftmost(Node* cur) {
		if (!cur) return -1;
		if (!cur->left) return cur->val;
		return _leftmost(cur->left);
	}
 void _inorder(Node* node) {
		if (!node) return;
		_inorder(node->left);
		cout << node->val << " ";
		_inorder(node->right);
	}

