#!/bin/bash

LOG_FILE="/tmp/.something.log"

if [[ "$1" == "-xe" ]]; then
    tail -n 20 "$LOG_FILE"
else
    echo "Usage: journalctl -xe"
    exit 1
fi
