#!/bin/sh

IS_SIMULATION=true
BASE_DESTINATION=/home/root

cd $BASE_DESTINATION/spaceDrivers
echo "++ Loading space drivers"
sh insmod_script.sh

if [ "$IS_SIMULATION" == false ]; then
	cd $BASE_DESTINATION/spaceUtils
	sh change_mac_address.sh
fi

# Launch SPACE application (no-op unless configured for automatic launch)
cd $BASE_DESTINATION
sh launch_space_app.sh