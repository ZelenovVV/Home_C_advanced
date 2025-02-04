uint64_t findMaxBlock(list *head) {
    if (head == NULL) return 0;
    list *current = head;
    size_t max_size = current->size;
    uint64_t max_address = current->address;

    while (current != NULL) {
        if (current->size > max_size) {
            max_size = current->size;
            max_address = current->address;
        }
        current = current->next;
    }
    return max_address;
}
