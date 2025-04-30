#include "raylib/raylib.h"
#include "Ball.h"
#include "GameTimer.h"
#include "game/Pin.h"
#include "fondo.h"
#include "Circulo.h"
#include "FinishLine.h"
#include <iostream>
#include <vector>
#include <string>
#include "Paredes.h"
int main()
{
    const int screenWidth = 600;
    const int screenHeight = 800;
    //std::cout << "Hello World!\n";
    InitWindow(screenWidth, screenHeight, "Pachinco");
    SetTargetFPS(60);

    fondo mfondo("resources/fnd.png");
    //Circulo mCirculo;
    GameTimer mTime;
    float secTime = 0;
    int score = 0;
    mTime.Reset();
    std::vector<Ball> mBalls;
    std::vector<Pin> mPin;
    std::vector<Paredes> mParedes;
    std::vector<Paredes> mParedes2;
    std::vector<FinishLine> mFinish;
    std::vector<Circulo> mCirculo;
    float waitTime = 1.0f;
    float waitTimeTemp = 0.0f;
    const float dist = 35.0f;
    int ppl = 1;
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < ppl; col++) {
            Pin pino;
            float x = 300.f - (row * dist / 2.f) + (col * dist);
            float y = 300.f + (row * dist);
            pino.SetPosition(Vector2{ x,y });
            mPin.push_back(pino);
        }
        ppl++;
    }
    Circulo miCirculo(Vector2{ 400.f,400.f });
    mCirculo.push_back(miCirculo);
    Paredes miPared(Vector2{ 590.f,400.f }, Vector2{ 500.f,600.f });
    Paredes miPared2(Vector2{ 100.f, 600.f }, Vector2{ 10.f, 400.f });
    FinishLine miFinish(Vector2{ 250, 750.f }, Vector2{ 350, 750.f });
    mParedes.push_back(miPared);
    mParedes2.push_back(miPared2);
    mFinish.push_back(miFinish);
    while (!WindowShouldClose()) {
        mTime.Tick();

        float dTime = mTime.DeltaTime();
        waitTimeTemp += dTime;  // Acumulamos el tiempo transcurrido

        if (waitTimeTemp >= waitTime) {
            //SI PASA CIERTO TIEMPO SE CREAN PELOTAS
            for (int i = 0; i < 5; ++i) {
                mBalls.push_back(Ball());
            }
            // Reinicia temporizador
            waitTimeTemp = 0.0f;
        }

        BeginDrawing();
        ClearBackground(DARKGRAY);
      //  DrawText(std::to_string("Puntaje:  " ),

        mfondo.Draw();
        miPared.Draw();
        miPared2.Draw();
        miFinish.Draw();
        miCirculo.Draw();
        DrawText(("Puntaje: " + std::to_string(score)).c_str(), 10, 10, 20, BLACK);
        for (Ball& bbll : mBalls) {
            bbll.Update(dTime);
            
           // Vector2 cualquier;
            bbll.HasCollision(mPin);
            bbll.HasCollision(mParedes);
            bbll.HasCollision(mParedes2);
            bbll.HasCollision(mCirculo);
           // bbll.Update(dTime);
            bbll.Draw();
            mBalls.erase(
                std::remove_if(
                    mBalls.begin(),
                    mBalls.end(),
                    [&](Ball& ball) {
                        if (ball.HasCollision(mFinish)) {
                            score += 10; // Incrementa el puntaje solo cuando eliminas la pelota
                            return true;
                        }
                        return false;
                    }),
                mBalls.end()
            );
        }
            for (Pin& ppl : mPin)
            {
                ppl.Update(dTime);
                ppl.GetPosition();
                ppl.Draw();
            }



            EndDrawing();
        }

        CloseWindow();
        return 0;




    }


