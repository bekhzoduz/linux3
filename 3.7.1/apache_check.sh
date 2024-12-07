#!/bin/bash

LOG_FILE="/tmp/.something.log"

# Perform config test
apache2ctl configtest >> "$LOG_FILE" 2>&1

# Append additional logs to simulate behavior
if grep -q "Syntax OK" "$LOG_FILE"; then
    echo "$(date '+%b %d %H:%M:%S') apache2: Configuration syntax OK" >> "$LOG_FILE"
else
    echo "$(date '+%b %d %H:%M:%S') apache2: Configuration syntax error detected" >> "$LOG_FILE"
fi
