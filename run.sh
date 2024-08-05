XEPHYR=$(whereis -b Xephyr | cut -f2 -d' ')
xinit ./lunnisWM -- \
    "$XEPHYR" \
        :98 \
        -screen 1280x720
