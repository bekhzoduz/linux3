# Start /usr/bin/rising and simulate pressing "3" to send it to the background
/usr/bin/rising &

# Now, kill the process by sending a STOP signal to it (this will suspend it)
kill -SIGSTOP $!
