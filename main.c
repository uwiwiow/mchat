#include <raylib.h>

int main(void) {

    SetTraceLogLevel(LOG_WARNING);
    InitWindow(800, 600, "morse chat");

    char text[50] = "";

    int c[5] = {};

    for (int i = 0; i < 5; i++)
        c[i] = -1;

    int index = 0;

    while(!WindowShouldClose()) {

        switch (GetKeyPressed()) {
            case KEY_J:
                c[index] = 0;
                if (index < 4) index++;
            break;
            case KEY_K:
                c[index] = 1;
                if (index < 4) index++;
            break;
            case KEY_SPACE:
                index = 0;
                for (int i = 0; i < 5; i++)
                    c[i] = -1;
            default: ;
        }

        BeginDrawing();

        ClearBackground(WHITE);

        for(int i = 0; i <= index; i++) {
            DrawText(c[i]? "." : "-", 20*i +20, 20, 24, BLACK);
        }

        DrawText(TextFormat("%d", index), 50, 50, 24, RED);


        EndDrawing();

    }

    CloseWindow();

    return 0;
}
