from setuptools import setup

package_name = 'fork_pkg_py'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='chenying',
    maintainer_email='evshary@gmail.com',
    description='ROS example for test fork',
    license='BSD',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'fork_node = fork_pkg_py.fork_node:main'
        ],
    },
)
