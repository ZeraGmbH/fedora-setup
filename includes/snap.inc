#! /bin/bash

############################################################################
echo "${style_blue}${style_bold}Install snap.${style_normal}"
sudo dnf -y install snapd
echo

############################################################################
if [ ! -e /snap ]; then
    echo "${style_blue}${style_bold}Make sure, snapd supports --classic.${style_normal}"
    sudo ln -sf /var/lib/snapd/snap /snap
    echo "Done"
fi

echo "${style_blue}${style_bold}Make sure, snapd is started/ready for operation.${style_normal}"
sudo systemctl start snapd.seeded.service
echo "Done"
echo

echo "${style_blue}${style_bold}Force snapd environment on first install of snapd.${style_normal}"
# This is what /etc/bashrc does
. /etc/profile.d/snapd.sh
echo "Done"
echo

echo "${style_blue}${style_bold}Check for snapd in PATH.${style_normal}"
SNAP_ENV_FOUND=0
echo "$PATH" | grep -q 'snapd' && SNAP_ENV_FOUND=1
if [ "$SNAP_ENV_FOUND" = "1" ]; then
    echo "OK"
else
    echo "${style_red}${style_bold}The environment for snap was not (yet) set."
    echo "Log off (or better restart) and run this script again to install snaps.${style_normal}"
    exit
fi
echo

echo "${style_blue}${style_bold}Refreshing snap.${style_normal}"
sudo snap refresh
echo


