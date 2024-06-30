build:
	@echo "Building..."
	colcon build --cmake-args -DTESSERACT_BUILD_FCL=OFF -DBUILD_RENDERING=OFF

install:
	@echo "Installing..."
	# sudo apt-get install -y gazebo libgazebo-dev
	# sudo apt-get install -y ros-humble-octomap
	rosdep install --from-paths src -iry --skip-keys libvtk --skip-keys fcl --skip-keys taskflow

clean:
	@echo "Cleaning..."
	# rm -rf install log build

import:
	@echo "Import..."
	vcs import src < dependencies.repos

	# taskflow (from the ROS-I PPA)
	sudo add-apt-repository ppa:ros-industrial/ppa -y
	sudo apt-get update
	sudo apt-get install taskflow -y

	vcs import src < src/scan_n_plan_workshop/dependencies.repos
	vcs import src < src/scan_n_plan_workshop/dependencies_tesseract.repos

launch:
	# source install/setup.bash
	ros2 launch snp_automate_2023 start.launch.xml sim_robot:=true sim_vision:=true
	# ros2 launch snp_automate_2023 start.launch.xml sim_robot:=false sim_vision:=flase
exp_dep:
	vcs export --exact src > my_dependencies_exact.repos
	vcs export --exact-with-tags src > my_dependencies_exact_with_tags.repos
.PHONY: build clean install import launch