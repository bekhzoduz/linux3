#!/bin/bash
set -m

# Start /usr/bin/rising and simulate pressing "3" to send it to the background
echo "3" | /usr/bin/rising &

# Allow some time for the process to start
sleep 1

# Now, kill the process by sending a STOP signal to it (this will suspend it)
kill -SIGSTOP $!

# Clear the terminal screen
clear
