#include <raylib.h>
#include <string.h>
#include "morseBinaryTree.h"

int main(void) {

    morseNode* root = createNode();
    buildMorseTree(root);

    SetTraceLogLevel(LOG_WARNING);
    InitWindow(800, 600, "morse chat");

    char text[50] = "";
    int textIndex = 0;

    // lsb
    int code = 0;
    int val = 1;
    int index = 0;

    while(!WindowShouldClose()) {

        switch (GetKeyPressed()) {
            case KEY_J:
                if (index >= 5) break;
                code = code | val;
                val *= 2;
                index++;
            break;
            case KEY_K:
                if (index >= 5) break;
                code = code | !val;
                val *= 2;
                index++;
            break;
            case KEY_SPACE:
                if (textIndex < 50) {
                    text[textIndex] = searchMorse(root, code, index);
                    textIndex++;
                }
                index = 0;
                code = 0;
                val = 1;
            break;
            case KEY_R:
                textIndex = 0;
                memset(text, 0, sizeof(text));
            break;
            default: ;
        }


        BeginDrawing();

        ClearBackground(WHITE);

        DrawText(TextFormat("%d %d %d", index, code, val), 50, 50, 24, RED);

        for (int i = 0; i < index; i++) {
            const int bit = (code >> i) & 1;
            DrawText(bit? "." : "-", 250 + i*50, 50, 48, RED);
        }

        DrawText(text, 50, 100, 48, BLACK);

        EndDrawing();

    }

    CloseWindow();

    freeTree(root);

    return 0;
}
