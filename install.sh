#!/bin/sh

chmod +x bbcfc
cp bbcfc /usr/bin

if [ "$1" != "-s" ]; then
    chmod +x bbcf
    cp bbcf /usr/bin
fi