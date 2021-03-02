# ros_project_template

Template repository for ROS projects

## Usage
Use the following steps to start your repository with this template:

1. Create a new project
    > Do not initialize with a README or any other files
1. Clone your new repository locally
    ```bash
    git clone <my_new_repository>
    ```
1. Add this repository as a remote to your new repository
    ```bash
    cd <my_new_repository>
    git remote add template https://mrtd-gitlab.dyn.datasys.swri.edu/swri/templates/ros_project_template.git
    git fetch template
    ```
1. Check out the master branch from the template remote and push it to your new repository
    ```bash
    git checkout master
    git branch --set-upstream-to=template/master
    git push origin master
    ```
1. Remove this repository as a remote to your new repository, and reset the master branch to track your repository's remote
    ```bash
    git remote remove template
    git branch --set-upstream-to=origin/master
    ```
