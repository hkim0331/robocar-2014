#!/usr/bin/env bash
# VERSION: 0.0

if [ ! $# = 1 ]; then
    echo usage: burn prog.bin
    exit
fi

CRP="/Volumes/CRP DISABLD"
rm "${CRP}"/firmware.bin
cp $1 "${CRP}"/firmware.bin
if [ $? = 0 ]; then
    diskutil unmount "${CRP}"
    sleep 1
# can not rm since file's owner differs.
#    rm $1
    echo success.
else
    echo burn failed.
fi


