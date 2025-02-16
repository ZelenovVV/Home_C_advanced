
void btUpView(tree *root) {
    if (root == NULL) {
        return;
    }

    struct tree* q[100];
    int hd[100];
    int front = 0, rear = 0;

    q[rear] = root;
    hd[rear] = 0;
    rear++;

    int min = 0, max = 0;
    int result[100];
    for (int i = 0; i < 100; i++){
         result[i] = -1;
    }

    while (front < rear) {
        struct tree* current = q[front];
        int horizD = hd[front];
        front++;

        if (horizD < min) {
            min = horizD;
        }
        if (horizD > max) {
            max = horizD;
        }

        if (result[horizD + 50] == -1) {
            result[horizD + 50] = current->key;
        }

        if (current->left != NULL) {
            q[rear] = current->left;
            hd[rear] = horizD - 1;
            rear++;
        }

        if (current->right != NULL) {
            q[rear] = current->right;
            hd[rear] = horizD + 1;
            rear++;
        }
    }

    for (int i = min + 50; i <= max + 50; i++) {
        if (result[i] != -1) {
            printf("%d ", result[i]);
        }
    }
    printf("\n");
}


