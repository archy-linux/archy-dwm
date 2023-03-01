# Anas Elgarhy's dwm
## My fork from dwm 🍴, with a lot of beautiful patches 🥰

### Applayed patches:
- [alwayscenter](https://dwm.suckless.org/patches/alwayscenter)
- [cool autostart](https://dwm.suckless.org/patches/cool_autostart)
- [fullscreen](https://dwm.suckless.org/patches/fullscreen)
- [gridmode](https://dwm.suckless.org/patches/gridmode)
- [movestack](https://dwm.suckless.org/patches/movestack)
- [pertag](https://dwm.suckless.org/patches/pertag)
- [systray](https://dwm.suckless.org/patches/systray)
- [sticky](https://dwm.suckless.org/patches/sticky)
- [noborder](https://dwm.suckless.org/patches/noborder)
- [fibonacci layouts](https://dwm.suckless.org/patches/fibonacci)
- [centeredmaster](https://dwm.suckless.org/patches/centeredmaster)
- [keychain](https://dwm.suckless.org/patches/keychain)

### Dependencies (apps)
- `google-chrome-stable` the main web browser
- `alacritty` the main terminal
- `spectacle` the main screenshot tool 
- `pcmanfm` the GUI file manger
- `rofi`
- `dmenu`
- `libxinerama-dev`\*\*
- `tmux`\*
- `tor-browser`
- `discord`
- `libxft-bgra` for color emojies support
- `jetbrains-toolbox`
- `nvim`\*
- `vim`\*
- `xbacklight` for control in the screen brightness
- `pamixer` for control in the audio level
- `playerctl` for control in the media
- `pactl` for control in the mic
- `betterlockscreen` for lock screen
- `setxkbmap` for switch between keyboard layouts, like (ar, en)
- `slstatus` the status bar
- `network-manager-applet` 
- `picom` compositor , for transparency
- `nitrogen` for set the wallpaper
- `copyq` clipboard manager
- `obsidian`

> \*\*: build dependencie.

### Install
- Manual:
  1. Run this command to install all avilable dependencies in standerd arch repostory
    ```bash
    sudo pacman -S google-chrome libxft-bgra rofi dmenu tmux tor-browser discord neovim jetbrains-toolbox vim pamixer playerctl betterlockscreen pcmanfm spectacle alacritty picom nitrogen libxinerama network-manager-applet copyq obsidian
    ```
    2. Install yay if you not installed it.
    3. Run this command to install all avilable dependencies in the AUR repostory `yay -S xkblayout`
    4. Clone this repostory `git clone https://github.com/anas-elgarhy/dwm-anas.git`
    5. Go to the source directory `cd dwm-anas/src`
    6. Build and install `sudo make install clean`
    7. Enjoy 😉


### Available in 

[![GitHub](https://img.shields.io/badge/GitHub-Main%20repo-brightgreen?style=for-the-badge&logo=GitHub)](https://github.com/anas-elgarhy/dwm-anas)
[![GitLab](https://img.shields.io/badge/GitLab-Mirror%20repo-brightgreen?style=for-the-badge&logo=GitLab)](https://gitlab.com/anas-elgarhy/dwm-anas)
[![BitBucket](https://img.shields.io/badge/BitBucket-Mirror%20repo-brightgreen?style=for-the-badge&logo=BitBucket)](https://bitbucket.org/anas_elgarhy/dwm-anas)
[![Codeberg](https://img.shields.io/badge/Codeberg-Mirror%20repo-brightgreen?style=for-the-badge&logo=Codeberg)](https://codeberg.org/anas-elgarhy/dwm-anas)

### Refrences:
- [XF86keysym](https://cgit.freedesktop.org/xorg/proto/x11proto/tree/XF86keysym.h)
