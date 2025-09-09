#include <raylib.h>

void getCode(int code, char *res[5]) {

    int val = 1;
    for(int i = 0; i < 5; i++) {
        if (code & val )
            res[i] = ".";
        else
            res[i] = "-";
        val *= 2;
    }
}

int main(void) {

    SetTraceLogLevel(LOG_WARNING);
    InitWindow(800, 600, "morse chat");

    char text[50] = "";

    // lsb
    int code = 0;
    int val = 1;
    int index = 0;

    char dcode[5] = {};

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
                code = code & !val;
                val *= 2;
                index++;
            break;
            case KEY_SPACE:
                index = 0;
                code = 0;
                val = 1;
            default: ;
        }

        BeginDrawing();

        ClearBackground(WHITE);

        // for(int i = 0; i <= index; i++) {
        //     DrawText(c[i]? "." : "-", 20*i +20, 20, 24, BLACK);
        // }

        getCode(code, &dcode);
        DrawText(TextFormat("%d %d %d", index, code, val), 50, 50, 24, RED);
        DrawText(TextFormat("%c %c %c %c %c", dcode[0], dcode[1], dcode[2], dcode[3], dcode[4]), 50, 50, 24, RED);


        EndDrawing();

    }

    CloseWindow();

    return 0;
}
