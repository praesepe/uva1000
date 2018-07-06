#!/usr/bin/env sh
while [ true ]; do
    fswatch --one-event . | (while read source; do
        if echo $source | egrep '\.cpp$' > /dev/null; then
            SOURCE=$source make run
        fi
    done)
    if [ $? = "130" ]; then
        break;
    fi
done
