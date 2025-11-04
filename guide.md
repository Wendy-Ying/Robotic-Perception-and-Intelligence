1. 硬件启动
ros2 launch iqr_tb4_bringup bringup.launch.py
功能：启动机器人的硬件设置。
解释：bringup.launch.py 是一个ROS 2的启动文件，用于初始化机器人的硬件驱动和基本服务。这通常包括启动机器人的电机驱动、传感器（如激光雷达、摄像头等），以及设置通信接口。

2. 键盘遥操作
ros2 run teleop_twist_keyboard teleop_twist_keyboard
功能：通过键盘发送速度命令到 /cmd_vel 主题。
解释：teleop_twist_keyboard 是一个ROS 2工具，允许用户通过键盘输入指令来控制机器人的运动。例如，用户可以通过键盘上的箭头键来控制机器人的前进、后退、左转和右转。

3. Rviz2 可视化
ros2 launch iqr_tb4_description display.launch.py
功能：可视化机器人的“数字孪生”模型。
解释：display.launch.py 是一个启动文件，用于加载机器人的URDF（Unified Robot Description Format）文件，并在Rviz2中显示机器人的3D模型。这可以帮助用户直观地看到机器人的状态和传感器数据。

4. SLAM（Simultaneous Localization and Mapping）
ros2 launch turtlebot4_navigation slam.launch.py
功能：启动 slam_toolbox 的SLAM功能。
解释：SLAM 是一种技术，允许机器人在未知环境中同时进行定位和地图构建。slam.launch.py 启动了SLAM工具箱，用于处理传感器数据并生成地图。

ros2 launch turtlebot4_viz view_robot.launch.py
功能：启动Rviz2进行SLAM过程的可视化。
解释：在SLAM过程中，Rviz2可以显示机器人的位置、传感器数据以及生成的地图，帮助用户实时监控SLAM的进展。

ros2 run nav2_map_server map_saver_cli -f <name_of_your_saved_map>
功能：保存构建的地图。
解释：map_saver_cli 是一个工具，用于将SLAM过程中生成的地图保存为文件，方便后续使用。

5. 导航
ros2 launch turtlebot4_navigation localization.launch.py map:=<name_of_your_saved_map.yaml>
功能：启动定位功能，使用保存的地图。
解释：localization.launch.py 启动定位服务，机器人通过传感器数据和保存的地图来确定自己的位置。

ros2 launch turtlebot4_navigation nav2.launch.py
功能：启动导航功能。
解释：nav2.launch.py 启动导航堆栈（Navigation Stack），允许机器人根据目标位置进行路径规划和运动控制。

ros2 launch turtlebot4_viz view_robot.launch.py
功能：启动Rviz2进行导航过程的可视化。
解释：在导航过程中，Rviz2可以显示机器人的路径、目标位置以及实时状态，帮助用户监控导航过程。