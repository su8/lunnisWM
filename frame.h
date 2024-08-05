/*
Copyright 08/05/2024 https://github.com/su8/lunnisWM
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA.
*/
extern "C"
{
    #include <X11/Xutil.h>
}
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <X11/extensions/Xrandr.h>
#include <algorithm>
#include <cmath>

class Frame
{
    public:
    Frame(Display *displayPass, Window rootPass, Window clientPass);
    Frame();
    
    Window getFrameHandle();
    Window getClientHandle();

    void moveFrame(int x, int y);
    void moveResizeFrame(int x, int y, int width, int height);

    void handleFrameButtonPress(XButtonEvent *ev);

    void handleWindowDrag(XMotionEvent *ev, int cursIntX, int cursIntY, int winIntX, int winIntY);
    void handleWindowResize(XMotionEvent *ev, int cursIntX, int cursIntY, int winIntX, int winIntY, int winIntWidth, int winIntHeight, int corner);
    void handleWindowDragOrResize(XMotionEvent *ev, int cursIntX, int cursIntY, int winIntX, int winIntY, int winIntWidth, int winIntHeight);

    private:

    Display *display;

    Window frame;
    Window client;
    Window root;

    Window closeButton;
    Window maximizeButton;
    Window minimizeButton;
    Window titlebar;

    void handleMaximizeButton(XButtonEvent *ev);
    void handleMinimizeButton();
    void handleCloseButton();

    void maximize(int x, int y, int width, int height);
    void unmaximize();

    int frameX;
    int frameY;
    int frameWidth;
    int frameHeight;

    bool maximized = false;


    int borderWidth = 3;
    
    //int frameWidth;
};
