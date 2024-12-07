#!/bin/bash

LOG_FILE="/tmp/.something.log"

case "$1" in
    start)
        echo "$(date '+%b %d %H:%M:%S') apache2.service: Started" >> "$LOG_FILE"
        echo "Apache service started"
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
