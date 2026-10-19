#include <raylib.h>
#include <string>
#include <iostream>
#include <raymath.h>

void FirstFunction()
{
    InitWindow(500, 500, "VGP230_FA26_C1a");
    SetTargetFPS(30);

    const char* title = "Cool Math Games";
    std::string Signiture = "W.Z";
    std::string author = "By: " + Signiture;

    int fontSize = 20;
    int titleWidth = MeasureText(title, fontSize);
    int authorWidth = MeasureText(author.c_str(), fontSize);

    Vector2 center = { 250, 250 };
    float rotation = -18.0f;
    float rotationSpeed = 45.0f;
    float radius = 150.0f;

    while (!WindowShouldClose())
    {
        rotation += rotationSpeed * GetFrameTime();

        if (rotation >= 360.0f)
        {
            rotation -= 360.0f;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCircle(250, 250, radius, BLUE);

        DrawPolyLinesEx(center, 5, radius, rotation, 5.0f, RED);

        DrawText(title, (GetScreenWidth() - titleWidth) / 2,
            240, fontSize, BLACK);

        DrawText(author.c_str(), (GetScreenWidth() - authorWidth) / 2,
            270, fontSize, BLACK);

        EndDrawing();
    }
}

void MovingBall()
{
    int width = 1600;
    int height = 800;
    InitWindow(width, height, "Moving Ball");
    SetTargetFPS(30);

    int radius = 20;
    int centerX = radius;
    int centerY = height / 2;
    int traillength = 100;
    int speed = 5;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);



        DrawCircle(centerX, centerY, radius, ORANGE);

        centerX += speed;

        if (centerX - radius >= width)
        {
            centerX = -radius + 1;
        }



        EndDrawing();
    }

    CloseWindow();
}

void NewMovingBall()
{
    int width = 1600;
    int height = 800;
    InitWindow(width, height, "New Moving Ball");
    SetTargetFPS(60);

    int radius = 20;
    int centerX = radius;
    int centerY = height / 2;
    int traillength = 100;
    int speed = 5;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = traillength - 1; i >= 0; i--)
        {
            int alpha = 255 * (traillength - i) / traillength;

            Color trailColor = {
                255, 165, 0, static_cast<unsigned char>(alpha)
            };

            DrawCircle(centerX - (i * speed * 2),
                centerY, radius, trailColor);
        }

        DrawCircle(centerX, centerY, radius, ORANGE);

        centerX += speed;

        if (centerX - radius >= width)
        {
            centerX = -radius + 1;
        }

        EndDrawing();
    }

    CloseWindow();
}

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

            // ball One
            // Right wall
            if (centerX1 + radius >= WindowWidth)
            {
                centerX1 = WindowWidth - radius;
                speedX1 = -GetRandomValue(2, 5);
                speedY1 = GetRandomValue(-5, 5);
            }
            // Left wall
            else if (centerX1 - radius <= 0)
            {
                centerX1 = radius;
                speedX1 = GetRandomValue(2, 5);
                speedY1 = GetRandomValue(-5, 5);
            }

            // Bottom wall
            if (centerY1 + radius >= WindowHeight)
            {
                centerY1 = WindowHeight - radius;
                speedY1 = -GetRandomValue(2, 5);
                speedX1 = GetRandomValue(-5, 5);
            }
            // Top wall
            else if (centerY1 - radius <= 0)
            {
                centerY1 = radius;
                speedY1 = GetRandomValue(2, 5);
                speedX1 = GetRandomValue(-5, 5);
            }

            // Corners
            if (centerX1 <= radius && speedX1 < 0)
            {
                speedX1 *= -1;
            }

            if (centerX1 >= WindowWidth - radius && speedX1 > 0)
            {
                speedX1 *= -1;
            }

            // Ball Two
            // Right wall
            if (centerX2 + radius >= WindowWidth)
            {
                centerX2 = WindowWidth - radius;
                speedX2 = -GetRandomValue(2, 5);
                speedY2 = GetRandomValue(-5, 5);
            }
            // Left wall
            else if (centerX2 - radius <= 0)
            {
                centerX2 = radius;
                speedX2 = GetRandomValue(2, 5);
                speedY2 = GetRandomValue(-5, 5);
            }

            // Bottom wall
            if (centerY2 + radius >= WindowHeight)
            {
                centerY2 = WindowHeight - radius;
                speedY2 = -GetRandomValue(2, 5);
                speedX2 = GetRandomValue(-5, 5);
            }
            // Top wall
            else if (centerY2 - radius <= 0)
            {
                centerY2 = radius;
                speedY2 = GetRandomValue(2, 5);
                speedX2 = GetRandomValue(-5, 5);
            }

            // Corners
            if (centerX2 <= radius && speedX2 < 0)
            {
                speedX2 *= -1;
            }

            if (centerX2 >= WindowWidth - radius && speedX2 > 0)
            {
                speedX2 *= -1;
            }

            // Collision Box Calculation
            int distanceX = centerX2 - centerX1;
            int distanceY = centerY2 - centerY1;

            // Collision
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

        // Collision Message
        if (pause)
        {
            DrawText("Collision - paused", 10, 10, 30, BLACK);
        }

        EndDrawing();
    }

    CloseWindow();
}

void TriangleFunction()
{
    int wh = 800;
    InitWindow(wh, wh, "Triangle Function");
    SetTargetFPS(60);

    Vector2 Top = { wh / 2.0f, 100.0f };
    Vector2 Left = { 100.0f, wh - 100.0f };
    Vector2 Right = { wh - 100.0f, wh - 100.0f };

    float r = 80;
    int isDragging = 0;

    while (!WindowShouldClose())
    {
        Vector2 Mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            float TopDist = Vector2Distance(Mouse, Top);
            float LeftDist = Vector2Distance(Mouse, Left);
            float RightDist = Vector2Distance(Mouse, Right);

            if (TopDist <= r)
            {
                isDragging = 1;
            }
            else if (LeftDist <= r)
            {
                isDragging = 2;
            }
            else if (RightDist <= r)
            {
                isDragging = 3;
            }
        }

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            isDragging = 0;
        }

        switch (isDragging)
        {
        case 1: Top = Mouse; break;
        case 2: Left = Mouse; break;
        case 3: Right = Mouse; break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTriangleLines(Top, Left, Right, BLACK);

        DrawCircle(Top.x, Top.y, r, RED);
        DrawCircle(Left.x, Left.y, r, GREEN);
        DrawCircle(Right.x, Right.y, r, BLUE);

        EndDrawing();
    }

    CloseWindow();
}

void TriangleColorFunction()
{
    int wh = 800;
    InitWindow(wh, wh, "Triangle Color Function");
    SetTargetFPS(60);
    Vector2 Center = { wh / 2.0f, wh / 2.0f };
    Vector2 Top = { Center.x, Center.y };
    Vector2 Left = { Center.x, Center.y };
    Vector2 Right = { Center.x, Center.y };

    float r = 120;
    int isDragging = 0;

    while (!WindowShouldClose())
    {
        Vector2 Mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            float TopDist = Vector2Distance(Mouse, Top);
            float LeftDist = Vector2Distance(Mouse, Left);
            float RightDist = Vector2Distance(Mouse, Right);

            if (TopDist <= r)
            {
                isDragging = 1;
            }
            else if (LeftDist <= r)
            {
                isDragging = 2;
            }
            else if (RightDist <= r)
            {
                isDragging = 3;
            }
        }

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            isDragging = 0;
        }

        if (isDragging != 0)
        {
			//Calculation Block, Determine the offset of the mouse from the center of the triangle
            Vector2 offset = { Mouse.x - Center.x, Mouse.y - Center.y };

			//2D Rotation Equation: x = xcos(Theta) - ysin(Theta), x = xcos(Theta) + ysin(Theta), Theta = 120 degrees, cos(Theta) = -0.5, sin(Theta) = 0.86602540378
            Vector2 plus120 = { -0.5f * offset.x - 0.86602540378f * offset.y, 0.86602540378f * offset.x - 0.5f * offset.y }; 

            Vector2 minus120 = { -0.5f * offset.x + 0.86602540378f * offset.y, -0.86602540378f * offset.x - 0.5f * offset.y };

            switch (isDragging) //Does the actual moving
            {
            case 1:
                Top = Mouse;
                Left = Vector2Add(Center, minus120);
                Right = Vector2Add(Center, plus120);
                break;

            case 2:
                Left = Mouse;
                Top = Vector2Add(Center, plus120);
                Right = Vector2Add(Center, minus120);
                break;

            case 3:
                Right = Mouse;
                Top = Vector2Add(Center, minus120);
                Left = Vector2Add(Center, plus120);
                break;
            }
        }


        BeginDrawing();

		BeginBlendMode(BLEND_ADDITIVE); //Additive Colour Blending Mode

        ClearBackground(BLACK);

        DrawTriangleLines(Top, Left, Right, GRAY);

        DrawCircle(Top.x, Top.y, r, RED);
        DrawCircle(Left.x, Left.y, r, GREEN);
        DrawCircle(Right.x, Right.y, r, BLUE);

        EndDrawing();
    }

    CloseWindow();
}

int main()
{
    TriangleColorFunction();
    return 0;
}