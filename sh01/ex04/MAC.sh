#!/bin/sh
ifconfig | grep 'ether' | awk 'BEGIN{FS=" "}{print $2}'
