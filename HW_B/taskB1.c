size_t totalMemoryUsage(list *head) {
    if (head == NULL) return 0;
    size_t sizeAll = 0;
    list *current = head;
    while (current != NULL) {
        sizeAll += current->size;
        current = current->next;
        }
    return sizeAll;
}

