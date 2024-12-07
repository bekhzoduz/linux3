#!/bin/bash

LOG_FILE="/tmp/.something.log"
RED=$(tput setaf 1)
YELLOW=$(tput setaf 3)
RESET=$(tput sgr0)

# Color-code log lines based on keywords
colorize_logs() {
    while read -r line; do
        if [[ "$line" == *"error"* || "$line" == *"failed"* ]]; then
            echo -e "${RED}${line}${RESET}"
        elif [[ "$line" == *"warning"* ]]; then
            echo -e "${YELLOW}${line}${RESET}"
        else
            echo "$line"
        fi
    done
}

# Simulate journalctl behavior
case "$1" in
    -xe)
        tail -n 20 "$LOG_FILE" | colorize_logs
        ;;
    --since)
        if [[ -z "$2" ]]; then
            echo "Error: --since requires a timestamp argument"
            exit 1
        fi
        since_ts=$(date -d "$2" +%s 2>/dev/null)
        if [[ $? -ne 0 ]]; then
            echo "Error: Invalid timestamp format for --since"
            exit 1
        fi
        while IFS= read -r line; do
            line_date=$(echo "$line" | cut -d' ' -f1-3)
            line_ts=$(date -d "$line_date" +%s 2>/dev/null)
            if [[ $line_ts -ge $since_ts ]]; then
                echo "$line" | colorize_logs
            fi
        done < "$LOG_FILE"
        ;;
    --until)
        if [[ -z "$2" ]]; then
            echo "Error: --until requires a timestamp argument"
            exit 1
        fi
        until_ts=$(date -d "$2" +%s 2>/dev/null)
        if [[ $? -ne 0 ]]; then
            echo "Error: Invalid timestamp format for --until"
            exit 1
        fi
        while IFS= read -r line; do
            line_date=$(echo "$line" | cut -d' ' -f1-3)
            line_ts=$(date -d "$line_date" +%s 2>/dev/null)
            if [[ $line_ts -le $until_ts ]]; then
                echo "$line" | colorize_logs
            fi
        done < "$LOG_FILE"
        ;;
    --no-pager)
        cat "$LOG_FILE" | colorize_logs
        ;;
    *)
        echo "Usage: journalctl [-xe|--since|--until|--no-pager]"
        ;;
esac
