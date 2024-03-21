#! /usr/bin/env python3

import rclpy
from rclpy.node import Node
from motoros2_interfaces.srv import StartTrajMode, ReadSingleIO, WriteSingleIO
from motoros2_interfaces.msg import MotionReadyEnum
from std_srvs.srv import Trigger

class RobotServiceNode(Node):
    def __init__(self):
        super().__init__('motoros2_simulator')

        self.create_service(StartTrajMode, 'start_traj_mode', self.enable_robot_callback)
        self.create_service(Trigger, 'stop_traj_mode', self.disable_robot_callback)
        self.create_service(ReadSingleIO, 'read_single_io', self.read_single_io_callback)
        self.create_service(WriteSingleIO, 'write_single_io', self.write_single_io_callback)
        self.io = {}

    async def enable_robot_callback(self, request, response):
        response.message = 'Robot enabled'
        response.result_code = MotionReadyEnum()
        response.result_code.value = MotionReadyEnum.READY
        return response


    async def disable_robot_callback(self, request, response):
        response.message = 'Robot disabled'
        response.success = True
        return response

    async def read_single_io_callback(self, request, response):
        if request.address in self.io:
            response.value = self.io[request.address]
            response.success = True
            response.message = f'Set IO {request.address} to {response.value}'
        else:
            response.message = f'Address {request.address} does not exist'
            response.success = False
        return response

    async def write_single_io_callback(self, request, response):
        self.io[request.address] = request.value
        response.success = True
        response.message = f'Successfully wrote IO {request.address} to {request.value}'
        return response


def main(args=None):
    rclpy.init(args=args)
    node = RobotServiceNode()
    node.get_logger().info('Started MotoROS2 simulator')
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
