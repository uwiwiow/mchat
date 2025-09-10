#ifndef MORSEBINARYTREE_H
#define MORSEBINARYTREE_H


typedef struct morseNode {
    char symbol;
    struct morseNode* left;
    struct morseNode* right;
} morseNode;

morseNode* createNode();

char searchMorse(morseNode* root, const int code, const int index);

void buildMorseTree(morseNode* root);

void freeTree(morseNode* node);

#endif //MORSEBINARYTREE_H
