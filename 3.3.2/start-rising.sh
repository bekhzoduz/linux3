#!/bin/bash
set -m
/usr/bin/rising &
kill -SIGSTOP $!