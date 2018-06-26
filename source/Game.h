/*
MIT License
Copyright (c) 2018 fuzun
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef GAME_H
#define GAME_H

#include "common.h"

class Sound;

class Game
{
public:
    Game(class QGraphicsView *GraphicsView, class QSettings *cfg, class QSettings *registry, int windowWidth, int windowHeight);
    ~Game();

   void clickEvent();
   void updateScore();
   void gameOver();
   void prepareFirstGame();
   void prepareNewRound();
   void soundEnable();
   void soundDisable();

   bool isGameFinished();
   bool isGameStarted();
   bool isGameActuallyStarted();
   bool isSoundEnabled();

   int getScore();
   int getScoreRecord();
   int getScreenWidth();
   int getScreenHeight();

   qreal getScaleFactor();

   Sound *sound_die;
   Sound *sound_hit;
   Sound *sound_point;
   Sound *sound_swooshing;
   Sound *sound_wing;

   class Scene *scene;
   class QGraphicsView *graphicsView;

private:
    bool soundEnabled;
    bool gameFinished, gameStarted;
    bool gameActuallyStarted;
    bool physicsComplexAnalysis;

    int score, scoreRecord;
    int screenWidth, screenHeight;
    int physicsTickRate;

    qreal scaleFactor;

    class QOpenGLWidget *glWidget;

    void loadConfiguration();

protected:
    class QSettings *config;
    class QSettings *registry;
    class Physics *physics;

};

#endif // GAME_H
