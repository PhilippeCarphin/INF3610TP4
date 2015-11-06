#!/bin/sh
set -e

IS_SIMULATION=true

DRIVERS_DIR="$(cygpath C:/SpaceCodesign/SpaceStudio-2.7.0/sw/OS/Linux3.6.0-digilent/drivers)"
BASE_DESTINATION=./home/root
DRIVERS_DESTINATION=$BASE_DESTINATION/spaceDrivers
UTILS_DESTINATION=$BASE_DESTINATION/spaceUtils
APP_DESTINATION=$BASE_DESTINATION/spaceApp

INSMOD_SCRIPT="$(cygpath C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/monitoring/armCortexA91/Linux/insmod_script.sh)"
EXECUTABLE="$(cygpath C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/monitoring/armCortexA91/Calculator_armCortexA91.arm.elf)"
STOP_SIMULATION="$(cygpath C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/monitoring/armCortexA91/stop_simulation.elf)"
IP_SAVER="$(cygpath C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/monitoring/armCortexA91/ip_saver.elf)"
CHANGE_MAC_ADD="$(cygpath C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/monitoring/armCortexA91/Linux/change_mac_address.sh)"
LAUNCH_SCRIPT="$(cygpath C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/monitoring/armCortexA91/Linux/launch_space_app.sh)"

RAMFS_BASE="$(cygpath C:/SpaceCodesign/SpaceStudio-2.7.0/sw/OS/Linux3.6.0-digilent/rootfs.cpio)"
RAMFS_MODIFIED="$(cygpath C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/monitoring/armCortexA91/Linux/rootfs.cpio.gz)"

LOGIN_SCRIPT_SRC="$(cygpath C:/Users/Arnaud/Desktop/Lab/Lab/Calculator/Calculator/Simtek/linux/linux/build/monitoring/armCortexA91/Linux/login_space.sh)"
LOGIN_SCRIPT_DEST=/etc/rcS.d/S99login_space.sh

# Extracting cpio file
rm -rf temp/
mkdir -p temp
cd temp
cpio -id --quiet < $RAMFS_BASE

# Moving login Space script
cp $LOGIN_SCRIPT_SRC .${LOGIN_SCRIPT_DEST}

# Copying space drivers and space app
mkdir -p $DRIVERS_DESTINATION
cp $INSMOD_SCRIPT $DRIVERS_DESTINATION 
cp $DRIVERS_DIR/*.ko $DRIVERS_DESTINATION 

mkdir -p $APP_DESTINATION
cp $EXECUTABLE $APP_DESTINATION

if $IS_SIMULATION; then
	mkdir -p $UTILS_DESTINATION
	cp $STOP_SIMULATION $UTILS_DESTINATION
	cp $IP_SAVER $UTILS_DESTINATION
else
	mkdir -p $UTILS_DESTINATION
	cp $CHANGE_MAC_ADD $UTILS_DESTINATION
fi




cp $LAUNCH_SCRIPT $BASE_DESTINATION


chmod +r,u+x .${LOGIN_SCRIPT_DEST}
chmod -R +r $BASE_DESTINATION
find $BASE_DESTINATION -name "*.sh" -o -name "*.elf" -type f -exec chmod u+x -- {} +

# Packing the files back into an cpio archive and gzip it
find . | cpio --create --format='newc' --quiet --owner 0:0 | gzip > $RAMFS_MODIFIED

cd ..
rm -rf temp

echo "--- ramfs created ---"