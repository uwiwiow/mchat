#include "morseBinaryTree.h"

#include <stdlib.h>

morseNode* createNode() {
    morseNode* node = malloc(sizeof(morseNode));
    node->symbol = '\0';
    node->left = nullptr;
    node->right = nullptr;
}

void insertMorse(morseNode* root, const int code, const int index, const char symbol) {
    morseNode* current = root;

    for (int i = 0; i < index; i++) {
        const int bit = (code >> i) & 1;
        if (bit) {
            if (!current->right) current->right = createNode();
            current = current->right;
        } else {
            if (!current->left) current->left = createNode();
            current = current->left;
        }
    }

    current->symbol = symbol;
}

char searchMorse(morseNode* root, const int code, const int index) {
    morseNode* current = root;

    for (int i = 0; i < index; i++) {
        if (!current) return '?';
        const int bit = (code >> i) & 1;
        current = (bit) ? current->right : current->left;
    }

    return (current && current->symbol != '\0') ? current->symbol : '?';
}

void buildMorseTree(morseNode* root) {
    insertMorse(root, 0b01,    2, 'A'); // .-
    insertMorse(root, 0b1000,  4, 'B'); // -...
    insertMorse(root, 0b1010,  4, 'C'); // -.-.
    insertMorse(root, 0b110,   3, 'D'); // -..
    insertMorse(root, 0b1,     1, 'E'); // .
    insertMorse(root, 0b1011,  4, 'F'); // ..-.
    insertMorse(root, 0b100,   3, 'G'); // --.
    insertMorse(root, 0b1111,  4, 'H'); // ....
    insertMorse(root, 0b11,    2, 'I'); // ..
    insertMorse(root, 0b0001,  4, 'J'); // .---
    insertMorse(root, 0b010,   3, 'K'); // -.-
    insertMorse(root, 0b1101,  4, 'L'); // .-..
    insertMorse(root, 0b00,    2, 'M'); // --
    insertMorse(root, 0b10,    2, 'N'); // -.
    insertMorse(root, 0b000,   3, 'O'); // ---
    insertMorse(root, 0b1001, 5, 'P'); // .--.
    insertMorse(root, 0b0100, 5, 'Q'); // --.-
    insertMorse(root, 0b010,   3, 'R'); // .-.
    insertMorse(root, 0b111,   3, 'S'); // ...
    insertMorse(root, 0b0,     1, 'T'); // -
    insertMorse(root, 0b011,   3, 'U'); // ..-
    insertMorse(root, 0b0111,  4, 'V'); // ...-
    insertMorse(root, 0b001,   3, 'W'); // .--
    insertMorse(root, 0b0110,  4, 'X'); // -..-
    insertMorse(root, 0b0010,  4, 'Y'); // -.--
    insertMorse(root, 0b1100,  4, 'Z'); // --..

    insertMorse(root, 0b00000, 5, '0');
    insertMorse(root, 0b10000, 5, '9');
    insertMorse(root, 0b11000, 5, '8');
    insertMorse(root, 0b11100, 5, '7');
    insertMorse(root, 0b11110, 5, '6');
    insertMorse(root, 0b11111, 5, '5');
    insertMorse(root, 0b01111, 5, '4');
    insertMorse(root, 0b00111, 5, '3');
    insertMorse(root, 0b00011, 5, '2');
    insertMorse(root, 0b00001, 5, '1');

    insertMorse(root, 0b0011, 4, ' ');
    // insertMorse(root, 0b00001, 5, '9');

}


void freeTree(morseNode* node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}
