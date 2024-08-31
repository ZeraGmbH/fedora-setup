#! /bin/bash

install_bare_vscode() {
    if ! command -v code &> /dev/null; then
        # see https://code.visualstudio.com/docs/setup/linux
        if [ ! -e /etc/yum.repos.d/vscode.repo ]; then
            echo "${style_blue}${style_bold}Prepare VSCode.${style_normal}"
            sudo rpm --import https://packages.microsoft.com/keys/microsoft.asc
            sudo sh -c 'echo -e "[code]\nname=Visual Studio Code\nbaseurl=https://packages.microsoft.com/yumrepos/vscode\nenabled=1\ngpgcheck=1\ngpgkey=https://packages.microsoft.com/keys/microsoft.asc" > /etc/yum.repos.d/vscode.repo'
            echo
        fi

        echo "${style_blue}${style_bold}Install VSCode...${style_normal}"
        sudo dnf -y install code
    fi
}

