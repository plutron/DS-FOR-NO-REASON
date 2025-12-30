#include <stdio.h>

#define MAXHEAP_SIZE 1000

struct maxheap{
    int data[MAXHEAP_SIZE];
    int counter;
};

void init_maxheap(struct maxheap *m) {
    m->counter = 0;
}


int insert(struct maxheap *m,int data){
    if(m->counter == MAXHEAP_SIZE)
        {printf("Heap is full!\n");return 0;}

    m->data[m->counter] = data;
    int t = m->counter;
    m->counter++;

    while(t>0){
        int p = (t-1)/2;
        if(m->data[t] > m->data[p]){
            int a = m->data[t];
            m->data[t] = m->data[p];
            m->data[p] = a;
            t = p;
        }
        else{
            break;
        }
    }
    return 1;
}

int extract_max(struct maxheap *m){
    if(!m->counter){
        printf("Heap is empty\n");
        return -1;
    }

    int data = m->data[0];
    m->counter --;
    m->data[0] = m->data[m->counter];
    int t = 0;
    while(2*t < m->counter - 1 ){
        int left = 2 * t + 1;
        int right = 2 * t + 2;

        if(right >= m->counter){
            if(m->data[left] > m->data[t]){
                int temp = m->data[t];
                m->data[t] = m->data[left];
                m->data[left] = temp;
                t = left;
            }
            else break;
        }
        else{
            if(m->data[left] < m->data[t] && m->data[right] < m->data[t])
                break;
            else if(m->data[left] < m->data[right]){
                int temp = m->data[t];
                m->data[t] = m->data[right];
                m->data[right] = temp;
                t = right;
            }
            else{
                int temp = m->data[t];
                m->data[t] = m->data[left];
                m->data[left] = temp; 
                t = left;
            }

        }
    }

    return data;

}

int search_heap(struct maxheap *m, int data) {
    for (int i = 0; i < m->counter; i++) 
        if (m->data[i] == data) 
            return i; 
    return -1; 
}

//------------------------------

int main() {
}