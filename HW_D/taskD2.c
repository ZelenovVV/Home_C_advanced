
tree* findBrother(tree* root, int key) {

    if (root == NULL) {
        return 0;
    }

    tree* q[100];
    int front = 0, rear = 0;
    q[rear++] = root;

    while (front < rear) {
        tree* current = q[front++];

        if (current->key == key) {
            if (current->parent != NULL) {
                tree* parent = current->parent;
                if (parent->left == current && parent->right != NULL) {
                    return parent->right;
                }
                if (parent->right == current && parent->left != NULL) {
                    return parent->left;
                }
            }
            return 0;
        }

        if (current->left != NULL) {
            q[rear++] = current->left;
        }

        if (current->right != NULL) {
            q[rear++] = current->right;
        }
    }

    return 0;
}
