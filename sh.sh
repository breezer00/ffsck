#!/bin/bash
# My first script

echo "Starting xfs_db"

xfs_db -x -c blockget -c "blocktrash -s 512109 -n 100" /dev/sda7

echo "End of xfs_db"

echo "Starting xfs_check"

xfs_check /dev/sda7

echo "End of xfs_check"

echo "Starting xfs_repair"

xfs_repair /dev/sda7

echo "End of xfs_repair"

