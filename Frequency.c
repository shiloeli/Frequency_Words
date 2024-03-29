#define NULL 0
#include "Frequency.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Node *crateRoot(){
 Node *n =(Node*)malloc(sizeof(Node));
 if(n == NULL){
     exit(1);
 }
        n->count = 0;
        n->letter = 0;
        n->isWord = FALSE;
        n->word = (char*)malloc(1);
        n->word[0] = 0;
          for(int i=0 ; i < NUM_LETTERS ; i++){
            n -> children[i] = NULL;
        }
    return n;
}

Node *newNode(Node *root, char c){
    Node *n =(Node*)malloc(sizeof(Node));
    if(n == NULL){
        exit(1);
    }
        n->count = 0;
        n->letter = c;
        n->isWord = FALSE;
        n -> word = (char*)malloc(strlen(root->word)+2);
        if(!(n->word)) exit(1);
        for(int i = 0; i<strlen(root->word); i++){
          n->word[i] =root->word[i]; 
        }
         n->word[strlen(root->word)]=c;
         n->word[strlen(root->word)+1]='\0';
        for(int i=0 ; i < NUM_LETTERS ; i++){
            n -> children[i] = NULL;
        }
    return n;
}

int charToIndex(char c){
    return (c -'a'); 
}

bool charIsCurrct(char c){
 if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
     return true;
 }else{
     return false;
 }
}

int insert(Node *root){
    Node* current = root;
    char tav;
    while(scanf("%c", &tav)!=EOF){
    if(tav != ' ' && tav != '\r' && tav != '\n'){
    if(charIsCurrct(tav)){
         if(tav>='A'&&tav<='Z'){
            tav=tav+32;
         }
        int index = charToIndex(tav);
        if(current->children[index] == NULL){
            current->children[index] = newNode(current, tav);
        }
        current = current->children[index];
        }
        }else{
            if(charIsCurrct(current->letter)){
              current->isWord = TRUE;
              current->count += 1;
            }
            current = root;
        }
        }   
        if(charIsCurrct(current->letter)){
              current->isWord = TRUE;
              current->count += 1;
        }
            return 0;    
}

void printWords(Node *root){
    if(root == NULL){
       return;
    }
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        printWords(root->children[i]);
    }
    if (root->isWord)
    {
    printf("%s %ld\n",root->word,root->count);
    }
    free(root->word);
    free(root);
}

void printWordsRevers(Node *root){
    if(root == NULL){
       return;
    }
    for (int i = 25; i >= 0; i--)
        printWordsRevers(root->children[i]);
    if (root->isWord)
    {
    printf("%s %ld\n",root->word,root->count);
    }
    free(root->word);
    free(root);
}

Node* buildTrie(){
    Node *root = crateRoot();
    insert(root);
    return root;
}