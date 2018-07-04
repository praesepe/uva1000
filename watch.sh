#!/usr/bin/env sh
while [ true ]; do
    fswatch --one-event -E */*.cpp | (while read source; do SOURCE=$source make run; done)
    if [ $? = "130" ]; then
        break;
    fi
done
