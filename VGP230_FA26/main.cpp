#include <raylib.h>
#include <cmath>
#include <iostream>

void TwoBallImpact()
{
    int WindowWidth = 500;
    int WindowHeight = 500;

    InitWindow(WindowWidth, WindowHeight, "Two Ball Impact");
    SetTargetFPS(60);

    int radius = 20;

    int centerX1 = radius;
    int centerY1 = WindowHeight / 2;
    int speedX1 = 5;
    int speedY1 = 5;

    int centerX2 = WindowWidth - radius;
    int centerY2 = WindowHeight / 2;
    int speedX2 = -5;
    int speedY2 = -5;

    int combinedRadius = radius * 2;
    bool pause = false;

    while (!WindowShouldClose())
    {
        if (!pause)
        {
            centerX1 += speedX1;
            centerY1 += speedY1;
            centerX2 += speedX2;
            centerY2 += speedY2;

            // Ball 1: right and left walls
            if (centerX1 + radius >= WindowWidth)
            {
                centerX1 = WindowWidth - radius;
                speedX1 = -GetRandomValue(2, 5);
                speedY1 = GetRandomValue(-5, 5);
            }
            else if (centerX1 - radius <= 0)
            {
                centerX1 = radius;
                speedX1 = GetRandomValue(2, 5);
                speedY1 = GetRandomValue(-5, 5);
            }

            // Ball 1: bottom and top walls
            if (centerY1 + radius >= WindowHeight)
            {
                centerY1 = WindowHeight - radius;
                speedY1 = -GetRandomValue(2, 5);
                speedX1 = GetRandomValue(-5, 5);
            }
            else if (centerY1 - radius <= 0)
            {
                centerY1 = radius;
                speedY1 = GetRandomValue(2, 5);
                speedX1 = GetRandomValue(-5, 5);
            }

            // Ball 1: keep movement inward at corners
            if (centerX1 <= radius && speedX1 < 0)
            {
                speedX1 *= -1;
            }

            if (centerX1 >= WindowWidth - radius && speedX1 > 0)
            {
                speedX1 *= -1;
            }

            // Ball 2: right and left walls
            if (centerX2 + radius >= WindowWidth)
            {
                centerX2 = WindowWidth - radius;
                speedX2 = -GetRandomValue(2, 5);
                speedY2 = GetRandomValue(-5, 5);
            }
            else if (centerX2 - radius <= 0)
            {
                centerX2 = radius;
                speedX2 = GetRandomValue(2, 5);
                speedY2 = GetRandomValue(-5, 5);
            }

            // Ball 2: bottom and top walls
            if (centerY2 + radius >= WindowHeight)
            {
                centerY2 = WindowHeight - radius;
                speedY2 = -GetRandomValue(2, 5);
                speedX2 = GetRandomValue(-5, 5);
            }
            else if (centerY2 - radius <= 0)
            {
                centerY2 = radius;
                speedY2 = GetRandomValue(2, 5);
                speedX2 = GetRandomValue(-5, 5);
            }

            // Ball 2: keep movement inward at corners
            if (centerX2 <= radius && speedX2 < 0)
            {
                speedX2 *= -1;
            }

            if (centerX2 >= WindowWidth - radius && speedX2 > 0)
            {
                speedX2 *= -1;
            }

            // Pause when the balls touch
            int distanceX = centerX2 - centerX1;
            int distanceY = centerY2 - centerY1;

            if (distanceX * distanceX + distanceY * distanceY
                <= combinedRadius * combinedRadius)
            {
                pause = true;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCircle(centerX1, centerY1, radius, ORANGE);
        DrawCircle(centerX2, centerY2, radius, BLUE);

        if (pause)
        {
            DrawText("Collision - paused", 10, 10, 20, BLACK);
        }

        EndDrawing();
    }

    CloseWindow();
}

int main()
{
    TwoBallImpact();
    return 0;
}