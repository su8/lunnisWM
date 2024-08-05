![](pic.png)

# lunnisWM
Dead simple window manager written in c++, based on steveWM

The bar/statusline is from my other project https://github.com/su8/doomy

# Compile and run

```bash
make -j8 # where 8 are CPU cores

chmod +x run.sh
./run.sh
```

# Requirements

g++/clang

xterm

xorg librares and headers

xephyr

# Keyboard shortcuts

alt + 1 executes **xterm**

ctrl + shift focuses the opened xephyr window

alt + tab changes windows focus

alt + escape quits the WM

alt + left/right mouse buttons resizes the current window
