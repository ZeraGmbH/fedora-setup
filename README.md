# fedora-setup

## Setting up a Linux environment (Fedora) with some basic development tools

### Install Fedora XFCE
Download it from https://fedoraproject.org/spins/xfce/

Install the system following its instructions.

### Setup Fedora XFCE
```
sudo dnf install git
git clone https://github.com/schnitzeltony/fedora-setup
cd fedora-setup
./setup-xfce-spin
```

To check the output of *setup-xfce-spin* (see below) perform following steps:
* Execute the script and save its log. Run it like `bash -x ./<SCRIPT_NAME>` to see the commands that were called. When not doing so, one has no idea which outputs belong to which command.
  -> Adapt the proper line of the above command like this: `bash -x ./setup-xfce-spin 2>&1 | tee -a log.txt`
* When the script has finished, check the log file.

## Manual troubleshooting

### Elder NVIDIA graphic cards
In case system boots into emergency console with reporting trouble starting
```dev-gpt\x2auto\x2droot.device```:

* Boot with elder kernel
* sudo akmods --force --rebuild
* sudo dracut --force --regenerate-all
* sudo grub2-mkconfig -o /boot/grub2/grub.cfg

### Google chrome 'public key not installed'
In case of
```
OpenPGP check for package "google-chrome-stable-..." (/var/cache/libdnf5/google-chrome-6ed7e4f336f6863c/packages/google-chrome-stable-145.0.7632.109-1.x86_64.rpm) from repo "google-chrome" has failed: Public key is not installed.
```

* run ```rpmkeys --list```
* For all keys from Google... copy hash and run: ```sudo rpmkeys --erase <hash>```
