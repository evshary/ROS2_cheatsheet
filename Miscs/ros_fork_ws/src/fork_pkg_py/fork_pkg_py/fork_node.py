import rclpy
from rclpy.node import Node
import os
import time

from std_msgs.msg import String

class MinimalPublisher(Node):
    def __init__(self):
        super().__init__("minimal_publisher")
        self.publisher_ = self.create_publisher(String, "topic", 10)
        self.timer = self.create_timer(0.5, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = String()
        msg.data = "Hello World: %d" % self.i
        self.publisher_.publish(msg)
        self.get_logger().info("Publishing: %s" % msg.data)
        self.i += 1

class MinimalSubscriber(Node):
    def __init__(self):
        super().__init__("minimal_subscriber")
        self.subscription = self.create_subscription(String,
                                                     "topic",
                                                     self.listener_callback,
                                                     10)

    def listener_callback(self, msg):
        self.get_logger().info("I heard: %s" % msg.data)

def child():
    print("Hello from child", os.getpid())
    rclpy.init()
    minimal_subscriber = MinimalSubscriber()
    rclpy.spin(minimal_subscriber)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()
    os._exit(0)

def parent():
    rclpy.init()
    minimal_publisher = MinimalPublisher()
    rclpy.spin(minimal_publisher)
    minimal_publisher.destroy_node()
    rclpy.shutdown()

def main():
    print('Hi from fork_pkg_py.')
    pid = os.fork()
    if pid == 0:
        print("This is child")
        child()
    else:
        print("This is parent")
        parent()


if __name__ == '__main__':
    main()
