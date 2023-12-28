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

