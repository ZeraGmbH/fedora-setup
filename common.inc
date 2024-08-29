#! /bin/bash

# set terminal styles
if [ -t 1 ] ; then # are we on terminal?
    # tput available?
    if [ ! "x`which tput 2>/dev/null`" = "x" ] ; then
        # supports colors ?
        ncolors=`tput colors`
        if [ -n "$ncolors" -a  $ncolors -ge 8 ] ; then
            style_bold="`tput bold`"
            style_underline="`tput smul`"
            style_standout="`tput smso`"
            style_normal="`tput sgr0`"
            style_black="`tput setaf 0`"
            style_red="`tput setaf 1`"
            style_green="`tput setaf 2`"
            style_yellow="`tput setaf 3`"
            style_blue="`tput setaf 4`"
            style_magenta="`tput setaf 5`"
            style_cyan="`tput setaf 6`"
            style_white="`tput setaf 7`"
        fi
    fi
fi

CURRUSER=`id -u`
if [ $CURRUSER = "0" ]; then
    echo "${style_red}Do not run this script as root - you will be asked for sudo password!${style_normal}"
    exit
fi

# exit when any command fails
set -e

REPO_PATH=`dirname $0`


# Prevent sudo password-entry timeout
bash -c "while true; do sudo -v; sleep 60; done" &
sudo_pid=$!

function ctrl_c() {
    echo "CTRL+C pressed..."
    kill -9 $sudo_pid
    exit
}
trap ctrl_c INT

echo "${style_yellow}Enter sudo password:${style_normal}"
sudo echo

