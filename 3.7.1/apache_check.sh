#!/bin/bash

LOG_FILE="/tmp/.something.log"

# Perform config test and redirect both stdout and stderr
# Run config test and check return code directly
if apache2ctl configtest 2> "$LOG_FILE"; then
    echo "$(date '+%b %d %H:%M:%S') apache2: Configuration syntax OK" >> "$LOG_FILE"
else
    echo "$(date '+%b %d %H:%M:%S') apache2: Configuration syntax error detected" >> "$LOG_FILE"
fi
