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
#include <unordered_map>
#include <vector>
#include <list>
#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>
#include <X11/cursorfont.h>
#include <X11/extensions/Xrandr.h>

#include "frame.h"

#define Button1Mod1Mask (Button1Mask | Mod1Mask)
#define Button3Mod1Mask (Button3Mask | Mod1Mask)

class WindowManager
{
    public:
    void loop();
    WindowManager();

    private:

    Display* display;
    Window root;
    Window active;

    void handleKeyPress(XKeyEvent *ev);
    void handleKeyRelease(XKeyEvent *ev);
    void handleButtonPress(XButtonEvent *ev);
    void handleMotionNotify(XMotionEvent *ev);

    void handleConfigureRequest(XConfigureRequestEvent *ev);
    void handleMapRequest(XMapRequestEvent *ev);
    void frame(Window client);
    void handleUnmapRequest(XUnmapEvent *ev);
    void unframe(Window client);
    void handleUnmapNotify(XUnmapEvent *ev);

    std::unordered_map<Window, Frame> frameHandlesTOFrame;
    std::vector<Window> applications;
    int switchFrame = 0;

    int cursIntX;
    int cursIntY;
    int winIntX;
    int winIntY;
    unsigned int winIntWidth;
    unsigned int winIntHeight;
    int corner;
    void moveResizeWindow(XMotionEvent *ev, int x, int y);

    int monitorCnt;
    XRRMonitorInfo* xMonitors;
};
