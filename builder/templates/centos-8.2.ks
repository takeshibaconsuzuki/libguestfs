# Kickstart file for centos-8.2
# Generated by libguestfs.git/builder/templates/make-template.ml

install
text
reboot
lang en_US.UTF-8
keyboard us
network --bootproto dhcp
rootpw builder
firewall --enabled --ssh
timezone --utc America/New_York
selinux --enforcing

bootloader --location=mbr --append="console=tty0 console=ttyS0,115200 rd_NO_PLYMOUTH"

url --url="http://mirror.centos.org/centos-8/8/BaseOS/x86_64/os"

zerombr
clearpart --all --initlabel --disklabel=gpt
autopart --type=plain

# Halt the system once configuration has finished.
poweroff

%packages
@core
%end

# EOF