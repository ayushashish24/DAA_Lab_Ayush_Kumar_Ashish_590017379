#include <stdio.h>
#include <stdlib.h>
struct node{
    char ch;
    int freq;
    struct node *left,*right;
};
struct node* create_node(char ch,int freq){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->ch=ch;
    n->freq=freq;
    n->left=n->right=NULL;
    return n;
}
struct node* find_min(struct node* arr[],int *size){
    int min_index=0;
    for (int i=1;i<*size;i++) {
        if (arr[i]->freq<arr[min_index]->freq){
            min_index=i;
        }
    }
    struct node* min_node=arr[min_index];
    for (int i=min_index;i<*size-1;i++){
        arr[i]=arr[i+1];
    }
    (*size)--;
    return min_node;
}
struct node* build_huffman(char characters[],int freq[],int n){
    struct node* arr[100];
    for (int i=0;i<n;i++){
        arr[i]=create_node(characters[i],freq[i]);
    }
    int size=n;
    while (size>1){
        struct node* left=find_min(arr,&size);
        struct node* right=find_min(arr,&size);
        struct node* top=create_node('$',left->freq+right->freq);
        top->left=left;
        top->right=right;
        arr[size++]=top;
    }
    return arr[0];
}
void print_codes(struct node* root,int code[],int top){
    if (root->left){
        code[top]=0;
        print_codes(root->left,code,top+1);
    }
    if (root->right){
        code[top]=1;
        print_codes(root->right,code,top+1);
    }
    if (!root->left&&!root->right){
        printf("%c:",root->ch);
        for (int i=0;i<top;i++){
            printf("%d",code[i]);
        }
        printf("\n");
    }
}
int main(){
    char characters[]={'a','b','c','d','e','f'};
    int freq[]={5,9,12,13,16,45};
    int n=sizeof(characters)/sizeof(characters[0]);
    struct node* root=build_huffman(characters,freq,n);
    int code[100],top=0;
    printf("Huffman Codes:\n");
    print_codes(root,code,top);
    return 0;
}