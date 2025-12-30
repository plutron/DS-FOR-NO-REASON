#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

struct node {
    int end_of_word;
    struct node *childs[ALPHABET_SIZE];
};

struct node *create_node() {
    struct node *t = (struct node *)malloc(sizeof(struct node));
    if (t) {
        t->end_of_word = 0;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            t->childs[i] = 0;
    } else {
        printf("something went wrong!!!!\n");
    }
    return t;
}

int insert(struct node *trie, char word[], int n) {
    if (!trie) {
        printf("Trie pointer is NULL!\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int index = word[i] - 'a';
        if (index < 0 || index >= ALPHABET_SIZE) {
            printf("word!!! out of range!\n");
            return 0;
        }
        if (trie->childs[index])
            trie = trie->childs[index];
        else {
            trie->childs[index] = create_node();
            if (!trie->childs[index])
                return 0;
            trie = trie->childs[index];
        }
    }
    trie->end_of_word = 1;
    return 1;
}

int is_node_empty(struct node *trie) {
    if (!trie) return 1;
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (trie->childs[i]) {
            return 0;
        }
    }
    return 1;
}

int delete_word_helper(struct node *trie, char word[], int n, int depth) {
    if (!trie) {
        return 0;
    }
    
    if (depth == n) {
        if (!trie->end_of_word) {
            return 0;
        }
        
        trie->end_of_word = 0;
        
        return is_node_empty(trie);
    }
    
    int index = word[depth] - 'a';
    if (index < 0 || index >= ALPHABET_SIZE) {
        return 0;
    }
    
    if (!trie->childs[index]) {
        return 0;
    }
    
    int should_delete_child = delete_word_helper(trie->childs[index], word, n, depth + 1);
    
    if (should_delete_child) {
        free(trie->childs[index]);
        trie->childs[index] = NULL;
        
        return (!trie->end_of_word && is_node_empty(trie));
    }
    
    return 0;
}

void delete_word(struct node *trie, char word[], int n) {
    if (!trie) {
        printf("root is NULL!\n");
        return ;
    }
    
    delete_word_helper(trie, word, n, 0);
    return ;
}

void free_trie(struct node *trie) {
    if (!trie) return;
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (trie->childs[i]) {
            free_trie(trie->childs[i]);
        }
    }
    free(trie);
}

int search(struct node * trie,char word[]){
    if(!trie)return 0;
    int c=0;
    int index;
    while(word[c]!=0){
        index = word[c]- 'a';
        if(trie->childs[index]){
            trie=trie->childs[index];
            if(word[c+1] == 0)
                if(trie->end_of_word)
                    return 1;}
        else{
            return 0;
        }
        c++;
    }
    return 0;

}

int main() {
    struct node *trie = create_node();
    
    insert(trie, "ab", 2);
    insert(trie, "a", 1);

        printf("%d",search(trie,"ab"));
    delete_word(trie,"ab",2);

    printf("%d",search(trie,"ab"));
    
    return 0;
}