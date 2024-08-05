#   08/05/2024 github.com/su8/lunnisWM
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 2 of the License, or
#   (at your option) any later version.

#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.

#   You should have received a copy of the GNU General Public License
#   along with this program; if not, write to the Free Software
#   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#   MA 02110-1301, USA.
CFLAGS+=-g2 -Wall -Wextra -O2 -I/usr/include/freetype2 -I/usr/X11R6/include -L/usr/X11R6/lib -I/usr/include/X11 -lX11 -lXft -lXrandr -pipe -pedantic -Wundef -Wshadow -W -Wwrite-strings -Wcast-align -Wstrict-overflow=5 -Wconversion -Wpointer-arith -Wformat=2 -Wsign-compare -Wendif-labels -Wredundant-decls -Winit-self
PACKAGE=lunnisWM

HEADERS = windowManager.h frame.h
SOURCES = main.cpp windowManager.cpp frame.cpp

all:
	$(CXX) $(HEADERS) $(SOURCES) $(CFLAGS) $(LDFLAGS) -o $(PACKAGE)

install: 
	install -D -s -m 755 $(PACKAGE) /usr/bin/$(PACKAGE)

clean:
	rm -f $(PACKAGE)

uninstall:
	rm -f /usr/bin/$(PACKAGE)

.PHONY: all install clean uninstall
