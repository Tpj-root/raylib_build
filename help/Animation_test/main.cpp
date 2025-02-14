// alias rbuild='g++ main* -o main -I/usr/local/include -L/usr/local/lib -lraylib -lm -lpthread -ldl -lX11'
#include "raylib.h"
#include <stdio.h>

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600
#define FRAME_COUNT   4  // Each animation has 4 frames
#define TOTAL_ANIM    14 // Number of animations

// Animation structure
typedef struct {
    Texture2D texture;
    Rectangle frames[FRAME_COUNT];
    int currentFrame;
    float frameTime;
    float frameSpeed;
} Animation;

// Global variables
const char *animNames[TOTAL_ANIM] = {
    "monster_arc.png", "monster_chair_left.png", "monster_mirror.png",
    "monster_blazon01.png", "monster_chair_right.png", "monster_phone.png",
    "monster_blazon02.png", "monster_closet.png", "monster_picture.png",
    "monster_blazon03.png", "monster_lamp_left.png", "monster_window.png",
    "monster_candle.png", "monster_lamp_right.png"
};

Animation animations[TOTAL_ANIM];
bool isAnimating = false;
int activeAnim = -1;  // -1 means no animation is playing


void DrawCloseButton() {
    // Define button position and size
    Rectangle closeBtn = {SCREEN_WIDTH - 50, 10, 40, 40}; // Position at top-right

    // Check if mouse is over the button and it is clicked
    if (CheckCollisionPointRec(GetMousePosition(), closeBtn) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        CloseWindow();  // Close the window
    }

    // Draw the button (you can customize the look of the button)
    DrawRectangleRec(closeBtn, RED);
    DrawText("X", SCREEN_WIDTH - 40, 15, 20, WHITE);  // "X" text to indicate close
}


void LoadAnimations() {
    for (int i = 0; i < TOTAL_ANIM; i++) {
        animations[i].texture = LoadTexture(animNames[i]);
        int width = animations[i].texture.width / FRAME_COUNT;
        int height = animations[i].texture.height;

        for (int j = 0; j < FRAME_COUNT; j++) {
            animations[i].frames[j] = (Rectangle){(float)(j * width), 0.0f, (float)width, (float)height};
        }

        animations[i].currentFrame = 0;
        animations[i].frameTime = 0;
        animations[i].frameSpeed = 0.15f;  // Animation speed
    }
}

void UnloadAnimations() {
    for (int i = 0; i < TOTAL_ANIM; i++) {
        UnloadTexture(animations[i].texture);
    }
}

void DrawMainMenu() {
    ClearBackground(RAYWHITE);
    
    // Button layout
    int x = 50, y = 60, btnWidth = 260, btnHeight = 50, spacing = 10;
    
    for (int i = 0; i < TOTAL_ANIM; i++) {
        Rectangle btnRect = {(float)x, (float)y, (float)btnWidth, (float)btnHeight};
        if (CheckCollisionPointRec(GetMousePosition(), btnRect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            activeAnim = i;
            isAnimating = true;
        }

        DrawRectangleRec(btnRect, GRAY);
        DrawText(animNames[i], x + 10, y + 10, 20, BLACK);

        y += btnHeight + spacing;
        if (i == 6) { // Move to second column
            x += btnWidth + 50;
            y = 50;
        }
    }

    // Back Button
    Rectangle backBtn = {SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 60, 100, 40};
    if (CheckCollisionPointRec(GetMousePosition(), backBtn) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        activeAnim = -1;
    }

    DrawRectangleRec(backBtn, RED);
    DrawText("Back", SCREEN_WIDTH / 2 - 25, SCREEN_HEIGHT - 50, 20, WHITE);


    DrawCloseButton();

}

void DrawAnimation() {
    ClearBackground(RAYWHITE);
    
    if (activeAnim != -1) {
        Animation *anim = &animations[activeAnim];
        anim->frameTime += GetFrameTime();

        if (anim->frameTime >= anim->frameSpeed) {
            anim->frameTime = 0;
            anim->currentFrame = (anim->currentFrame + 1) % FRAME_COUNT;
        }

        int x = SCREEN_WIDTH / 2 - anim->frames[0].width / 2;
        int y = SCREEN_HEIGHT / 2 - anim->frames[0].height / 2;

        DrawTextureRec(anim->texture, anim->frames[anim->currentFrame], (Vector2){(float)x, (float)y}, WHITE);
    }

    // Back Button
    Rectangle backBtn = {SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 60, 100, 40};
    if (CheckCollisionPointRec(GetMousePosition(), backBtn) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        activeAnim = -1;
        isAnimating = false;
    }

    DrawRectangleRec(backBtn, RED);
    DrawText("Back", SCREEN_WIDTH / 2 - 25, SCREEN_HEIGHT - 50, 20, WHITE);


    DrawCloseButton();
}

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Animation Tester");
    InitAudioDevice();  
    SetTargetFPS(60);

    LoadAnimations();

    while (!WindowShouldClose()) {
        BeginDrawing();
        
        if (isAnimating)
            DrawAnimation();
        else
            DrawMainMenu();

        EndDrawing();
    }

    UnloadAnimations();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
