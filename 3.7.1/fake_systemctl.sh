#!/bin/bash

LOG_FILE="/tmp/.something.log"

case "$1" in
    start)
        # Check Apache config syntax
        apache2ctl configtest 2> "$LOG_FILE"
        if [ $? -eq 0 ]; then
            echo "$(date '+%b %d %H:%M:%S') apache2.service: Started" >> "$LOG_FILE"
            echo "Apache service started"
        else
            echo "$(date '+%b %d %H:%M:%S') apache2.service: Failed to start - Configuration error" >> "$LOG_FILE"
            echo "Apache service failed to start due to configuration error"
        fi
        ;;
    stop)
        echo "$(date '+%b %d %H:%M:%S') apache2.service: Stopped" >> "$LOG_FILE"
        echo "Apache service stopped"
        ;;
    restart)
        echo "$(date '+%b %d %H:%M:%S') apache2.service: Restarted" >> "$LOG_FILE"
        echo "Apache service restarted"
        ;;
    status)
        echo "Apache service status is active"
        ;;
    *)
        echo "Usage: $0 {start|stop|restart|status}"
        exit 1
        ;;
esac
